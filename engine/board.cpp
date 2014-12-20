#include "board.h"

void Board::newGame()
{
        uint8_t initial[120] = {
        X, X, X, X, X, X, X, X, X, X,
        X, X, X, X, X, X, X, X, X, X,
        X, R, N, B, Q, K, B, N, R, X,
        X, P, P, P, P, P, P, P, P, X,
        X, _, _, _, _, _, _, _, _, X,
        X, _, _, _, _, _, _, _, _, X,
        X, _, _, _, _, _, _, _, _, X,
        X, _, _, _, _, _, _, _, _, X,
        X, p, p, p, p, p, p, p, p, X,
        X, r, n, b, q, k, b, n, r, X,
        X, X, X, X, X, X, X, X, X, X,
        X, X, X, X, X, X, X, X, X, X} ;

        _board.reserve(120);
        for (int i = 0; i < 120; i++)
        {
               _board[i] = initial[i];
               //cout << _board[i] <<" ";
        }
}

void Board::display()
{       
        
        for (int i = 8 ; i >0 ; i-- )
        {       cout << "\n" << i << "  ";
                for (int j = 0; j < 8; j++)
                {       
                        cout  << pieceToStr(_board[10*(i+1)+j +1],1) <<" ";
                }
                
        }
        cout << "\n\n   a b c d e f g h \n" ;
}


std::vector<Move> getLegalMoves(Square sq) 
{
        vector<Move> movelst = vector<Move>();
        switch(sq) :
                case p case P :

                break


}