#include "api.h"

// inspired from
void API::loop(int argc, char *argv[]) {

    string token, cmd;

    argv = NULL;
    for (int i = 1; i < argc; ++i)
        cmd += string(argv[i]) + " ";

    do {


        if (_state == TERMINAL && _gameStarted) {
            cout << _board ;
            if (_board.getPlayer() == WHITE)
                cout << "White to move" << endl;
            else cout << "Black to move" << endl;

        } else if (_state == TERMINAL && !_gameStarted) {
            cout << "Avaible commands : quit, newgame, show, go, move" << endl;
            cout << "To begin the game, you must type \"newgame\" " << endl;
            help();
        }


        if (argc == 1 && !getline(cin, cmd)) // Block here waiting for input
            cmd = "quit";

        istringstream is(cmd);

        is >> skipws >> token;

        if (token == "quit" || token == "stop") {

            exit(EXIT_SUCCESS);


        } else if (token == "newgame") newgame(cmd);
        else if (token == "go")   cout << cmd << endl ;


        else if (token == "show" && _gameStarted) show(cmd) ;

        else if (token == "move" && _gameStarted) move(cmd);
        else if (token == "isready")    cout << "readyok" << endl;
        else if (token == "getbackup") cout << _board.getBackupGame() << endl;
        else if (token == "getbackup") cout << _board.getBackupGame() << endl;
        else if (token == "undo") {
            if (_board.undoLastMove()) cout << "ok" << endl ;
            else cout << "invalid : no last move" << endl ;
        } else if (token == "get_evaluation") cout << _board.getEvaluation() << endl ;
        else if (_state == TERMINAL)
            help();
        else
            cout << "Unknown command: " << cmd << endl;

    } while (token != "quit" && argc == 1); // Passed args have one-shot behaviour
}

void API::invalid(string cmd) {

    cout << "invalid command :" << cmd << endl;
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
    cout << "DEBUG avant taille = " << _moveLst.size();
    displayMoveLst(_moveLst);
    cleanMoveLstFromChecks(_moveLst, _board);
    cout << "DEBUG après taille = " << _moveLst.size();
    displayMoveLst(_moveLst);

    cout << "show" << "> " ;


}

void API::move(string cmd) {
    Move move = Move(cmd.substr(5, 4));

    // Is this move valid ?
    if (_board.isValidMove(move)) {
        if (_board.isMoveGoToChess(move))
            std::cout << "invalid : You are in CHECK. Play another move." << std::endl;
        else {
            _board.doMove(move) ;
            cout << "ok" << endl;

            if (_board.isKingInCheck()) {
                if (_board.getPlayer() == WHITE)
                    cout << "victore BLANC" << endl ;
                else
                    cout << "victore NOIR" << endl ;

            }
        }
    } else {
        invalid(cmd) ;
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
    cout << "ok" << endl;

}



void displayMoveLst(vector<Move> &moves) {
    for (Move m : moves)
        cout << m << " ";
    cout << endl ;
}

void cleanMoveLstFromChecks(vector<Move> &moveLst, Board &board) {

    vector<Move> tmpLst = moveLst ; // copy
    moveLst.clear();
    for (uint8_t i = 0 ; i < tmpLst.size() ; i++) {
        if (!board.isMoveGoToChess(moveLst[i]))
            moveLst.push_back(tmpLst[i]);
    }


    //todebug : newgame k7/8/8/KQ6/8/8/8/8
}

void help(void) {

    cout << "Some examples : " << "\n" << "\"move a2a3\"" << "\n" << "\"show\"" << endl
         << "\"show f2\"" << endl << "\"go\"" << endl
         << "\"newgame RNBQKBNR/1PPPPPPP/P7/8/8/p7/1ppppppp/rnbqkbnr \"" << endl;
}