/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "api.h"

// inspired from
void API::loop() {

    string token, cmd;
    ofstream logfile("engine.log");
    assert(logfile.is_open()) ;

    do {
        displayTerminalInfo();

        if (!getline(engine_cin, cmd)) // Block here waiting for input
            cmd = "quit";
        istringstream is(cmd);
        is >> skipws >> token;
        logfile << token << endl ;
        logfile.flush();

        if (token == "quit" || token == "stop" || token == "exit") {
            // close ofstream;
            logfile.close();
            cout << endl << "closing engine ..." << endl ;
            exit(EXIT_SUCCESS);

        } else if (token == "newgame") newgame(cmd);
        else if (token == "go")  go() ;
        else if (token == "show" && _gameStarted) show(cmd) ;
        else if (token == "move" && _gameStarted) move(cmd);

        else if (token == "setdifficulty") setDificulty(cmd) ;
        else if (token == "isready")    engine_cout << "readyok" << endl;
        else if (token == "getbackup" && _gameStarted) engine_cout << "getbackup> " << _board.getBackupGame() << endl;
        else if (token == "undo" && _gameStarted) {
            if (_board.undoLastMove()) engine_cout << "undo> ok" << endl ;
            else engine_cout << "undo> invalid : no last move" << endl ;
        } else if (token == "getevaluation" && _gameStarted) engine_cout << "getevaluation> " <<  _board.getEvaluation() << endl ;
        else if (_state == TERMINAL) {
            help();
            engine_cout << "unknown command: " << cmd << endl;
        }

    } while (token != "quit"); // Passed args have one-shot behaviour

    // close ofstream;
    logfile.close();

}


void API::show(string cmd) {


    // displayVictoryOrDoNothing() ; // DEBUG

    if (cmd.size() > 5) {
        string sqStr = cmd.substr(5, 2) ;
        if (sqStr.size() >= 2) {
            _moveLst.clear();
            _board.getLegalMoves(_moveLst, Square(sqStr), _board.getPlayer());
            engine_cout << "debug string " << _board.getPieceStringFromSquare(Square(sqStr)) << endl ;
        } else {
            invalid(cmd);
        }
    } else {
        _board.getAllLegalMoves(_moveLst);
    }

    // Sppression des mouvements de mise en echec
    // engine_cout << "DEBUG avant taille = " << _moveLst.size();
    _board.cleanChecksFromMoveLst(_moveLst);
    // engine_cout << "DEBUG après taille = " << _moveLst.size();
    if (_moveLst.size() != 0) {
        engine_cout << "show>" ;
        displayMoveLst(_moveLst);

    }
    engine_cout << "debug string  evaluation = " << _board.getEvaluation() << endl ;

}

void API::move(string cmd) {

    if (cmd.size() < 9) {
        invalid(cmd, " example : move a2a3") ;
        return ;

    }
    Move move = Move(cmd.substr(5, 4));

    // Is this move valid ?
    if (_board.isValidMove(move)) {
        if (_board.isMoveGoToChess(move))
            engine_cout << "move> invalid : You are in CHECK. Play another move." << std::endl;
        else {
            _board.doMove(move) ;
            engine_cout << "move> ok" << endl;
            displayVictoryOrDoNothing() ;
        }
    } else {
        invalid(cmd) ;
    }

    engine_cout << "debug string evaluation = " << _board.getEvaluation() << endl ;
}

void API::go(void) {
    if (!displayVictoryOrDoNothing()) {

        IA ia = IA(_board) ;
        Move bestMove = ia.findBestMove(_negamaxLevel);

        std::cout << "bestmove " << bestMove << std::endl;

        _board.doMove(bestMove);
        displayVictoryOrDoNothing();


    }
}

void API::newgame(string cmd) {

    if (cmd.size() > 8) {
        string input = cmd.substr(8) ;
        _board.newGame(input);
    } else {
        _board.newGame();
    }

    _gameStarted = 1 ;
    engine_cout << "newgame> ok" << endl;

}

void API::displayTerminalInfo(void) {

    if (_state == TERMINAL && _gameStarted) {
        engine_cout << _board ;
        if (_board.getPlayer() == WHITE)
            engine_cout << "White to move" << endl;
        else engine_cout << "Black to move" << endl;

    } else if (_state == TERMINAL && !_gameStarted) {
        engine_cout << "Avaible commands : quit, newgame, show, go, move, getbackup, undo, getevaluation" << endl;
        engine_cout << "To begin the game, you must type \"newgame\" " << endl;
        help();
    }
}

void API::setDificulty(string cmd) {
    string input = cmd.substr(14) ;
    _negamaxLevel = int(input[0]) - 48 + 2 ;
    engine_cout << "setdifficulty> ok" << endl;
}



void API::invalid(string cmd, string other) {

    engine_cout << "invalid command :" << cmd << " " << other << endl;
    // if(_state == TERMINAL)
    //     help();
}
bool API::displayVictoryOrDoNothing(void) {
    int result = _board.getStateOfChessBoard() ;
    if (result == WHITE_WIN) {
        engine_cout << "victory WHITE" << endl ;
        _gameStarted = false ;

    } else if (result == BLACK_WIN) {
        engine_cout << "victory BLACK" << endl ;
        _gameStarted = false ;
    } else if (result == MATE) {
        engine_cout << "victory MATE" << endl ;
        _gameStarted = false ;
    }
    // show("show") ;
    return  !_gameStarted ;
}
void displayMoveLst(vector<Move> &moves) {
    for (Move m : moves)
        engine_cout << " " << m ;
    engine_cout << endl ;
}
//todebug : newgame k7/8/8/KQ6/8/8/8/8
//todebug : newgame kppppppp/8/8/1QQ5/8/8/8/K7
void help(void) {

    engine_cout << "Some examples : " << "\n" << "\"move a2a3\"" << "\n" << "\"show\"" << endl
                << "\"show f2\"" << endl << "\"go\"" << endl
                << "\"newgame RNBQKBNR/1PPPPPPP/P7/8/8/p7/1ppppppp/rnbqkbnr \"" << endl;
}