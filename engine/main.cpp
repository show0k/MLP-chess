#include <string.h>
#include <stdio.h>
#include <iostream>


#include "board.h"
#include "move.h"
#include "square.h"
#include "api.h"



using namespace std;


void testPasUnitaireDuTout() ;

int main(int argc, char *argv[]) {

    // Parse input to start the api
    int8_t api_state = GUI ;
    bool debug = false;
    if (argc > 1) {
        if (strcmp(argv[1], "--terminal") == 0 || strcmp(argv[1], "-t") == 0) {
            api_state = TERMINAL;
            argc = 1;
        } else if (strcmp(argv[1], "--debug") == 0 || strcmp(argv[1], "-d") == 0) {
            debug = true ;
        }
    }

    if (!debug) {
        API api = API(api_state) ;
        api.loop();
    } else testPasUnitaireDuTout();
}



void testPasUnitaireDuTout() {
    vector<Move> moveLst = vector<Move>() ;
    Board b = Board();
    b.newGame();
    cout << b;
    b.getAllLegalMoves(moveLst, PLAYERTOMOVE) ;

    for (Move move : moveLst) {

        cout << move << " " ;
    }
    Move move = Move("a2a3");
    b.doMove(move) ;

    cout << b << endl;
    b.getAllLegalMoves(moveLst, PLAYERTOMOVE) ;

    for (Move move : moveLst) {

        cout << move << " " ;

    }
}