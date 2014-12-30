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


        } else if (token == "newgame") {

            if (cmd.size() > 7) {
                string input = cmd.substr(7) ;
                _board.newGame(input);
            }
            else {
                _board.newGame();
            }
            
            _gameStarted = 1 ;
            cout << "ok" << endl;

        } else if (token == "go")   cout << cmd << endl ;


        else if (token == "show" && _gameStarted) {

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

            displayMoveLst(_moveLst);


        } else if (token == "move" && _gameStarted)  {
            Move move = Move(cmd.substr(5, 4));

            // Is this move valid ?
            if (_board.isValidMove(move)) {
                _board.doMove(move) ;
                cout << "ok" << endl;
            } else {
                invalid(cmd) ;
            }


        } //position(pos, is);
        else if (token == "isready")    cout << "readyok" << endl;
        else if (token == "getbackup") cout << _board.getBackupGame() << endl;


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

void displayMoveLst(vector<Move> &moves) {
    for (Move m : moves)
        cout << m << " ";
    cout << endl ;
}

void help(void) {

    cout << "Command examples : " << "\n" << "\"move a2a3\"" << "\n" << "\"show\"" << endl << "\"show f2\"" << endl << "\"go\"" << endl;
}