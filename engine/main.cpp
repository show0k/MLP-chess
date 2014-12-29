#include <string.h>
#include <stdio.h>
#include <iostream>


#include "board.h"
#include "square.h"

using namespace std;

void testSquare (void)
{

    Square t = Square("b6");
    cout << "t = " << t ;

}

int main()
{
    vector<Move> moveLst = vector<Move>() ;
    Board b = Board();
    b.newGame();
    cout << b ;
    b.getAllLegalMoves(moveLst) ;
    b.getLegalMoves(moveLst,Square("b2")) ;

    for (Move move : moveLst) {

        cout << move << " " ;

    }




}