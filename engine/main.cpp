#include <string.h>
#include <stdio.h>
#include <iostream>


#include "board.h"
#include "square.h"
#include "api.h"

using namespace std;


int main(int argc, char *argv[]) {

    // vector<Move> moveLst = vector<Move>() ;
    // Board b = Board();
    // b.newGame();
    // cout << b;
    // b.getAllLegalMoves(moveLst,PLAYERTOMOVE) ;

    // for (Move move : moveLst) {

    //     cout << move << " " ;

    // }

    // b.doMove(moveLst[1]) ;

    // cout << endl;
    // b.getAllLegalMoves(moveLst,PLAYERTOMOVE) ;

    // for (Move move : moveLst) {

    //     cout << move << " " ;

    // }

    // cout << b;
    // if (argv[2] == "-gui") {
    //     cout << "GUI" ;
    //     API api = API(GUI) ;
    //     api.loop(argc, argv);
    // }
    // else {
    //     API api = API(TERMINAL) ;
    //     api.loop(argc, argv);
    // }

    API api = API(GUI) ;
    api.loop(argc, argv);
    

}


