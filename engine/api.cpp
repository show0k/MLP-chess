#include "api.h"

// inspired from
void API::loop() {

    string token, cmd;

    do {
        displayTerminalInfo();

        if (!getline(engine_cin, cmd)) // Block here waiting for input
            cmd = "quit";
        istringstream is(cmd);
        is >> skipws >> token;

        if (token == "quit" || token == "stop") {

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
        } else if (token == "getevaluation" && _gameStarted ) engine_cout << "getevaluation> " <<  _board.getEvaluation() << endl ;
        else if (_state == TERMINAL)
            help();
        else
            engine_cout << "unknown command: " << cmd << endl;

    } while (token != "quit"); // Passed args have one-shot behaviour
}

void API::invalid(string cmd) {

    engine_cout << "invalid command :" << cmd << endl;
    // if(_state == TERMINAL)
    //     help();
}


void API::show(string cmd) {

    if (cmd.size() > 5) {
        string sqStr = cmd.substr(5, 2) ;
        if (sqStr.size() >= 2) {
            _moveLst.clear();
            _board.getLegalMoves(_moveLst, Square(sqStr), _board.getPlayer());
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
    engine_cout << "show> " ;
    if (_moveLst.size() != 0)
        displayMoveLst(_moveLst);



}

void API::move(string cmd) {
    Move move = Move(cmd.substr(5, 4));

    // Is this move valid ?
    if (_board.isValidMove(move)) {
        if (_board.isMoveGoToChess(move))
            engine_cout << "move> invalid : You are in CHECK. Play another move." << std::endl;
        else {
            _board.doMove(move) ;
            engine_cout << "move> ok" << endl;

            int result = _board.getStateOfChessBoard() ;
            if (result == WHITE_WIN)
                engine_cout << "victory WHITE" << endl ;
            else if (result == BLACK_WIN)
                engine_cout << "victory BLACK" << endl ;
            else if (result == MATE) engine_cout << "victory MATE" << endl ;
        }
    } else {
        invalid(cmd) ;
    }
}

void API::go(void) {
    IA ia = IA(_board, _negamaxLevel) ;
    Move bestMove = ia.findBestMove();

    std::cout << "bestmove " << bestMove << std::endl;

    _board.doMove(bestMove);

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



void displayMoveLst(vector<Move> &moves) {
    for (Move m : moves)
        engine_cout << m << " ";
    engine_cout << endl ;
}


//todebug : newgame k7/8/8/KQ6/8/8/8/8
void help(void) {

    engine_cout << "Some examples : " << "\n" << "\"move a2a3\"" << "\n" << "\"show\"" << endl
                << "\"show f2\"" << endl << "\"go\"" << endl
                << "\"newgame RNBQKBNR/1PPPPPPP/P7/8/8/p7/1ppppppp/rnbqkbnr \"" << endl;
}