#ifndef _MOVE_H_
#define _MOVE_H_

#include <string> 
#include <iostream> 


#include "square.h"
typedef enum {
                e_empty = 0,   // Empty
                e_wpawn = 1,   // White Pawn
                e_wknight = 2,   // White Knight
                e_wbishop = 3,   // White Bishop
                e_wrook = 4,   // White Rook
                e_wqueen = 5,   // White Queen
                e_wking = 6,   // White King

                e_bpawn = -1,   // Black Pawn
                e_bknight = -2,   // Black Knight
                e_bbishop = -3,   // Black Bishop
                e_brook = -4,   // Black Rook
                e_bqueen = -5,   // Black Queen
                e_bking = -6,   // Black King
                e_iv = 99   // INVALID

} EPieceCode;


class Move
{
        public:
                // Constructors
                Move(char* fromTo)  {fromString(fromTo);};
                Move(Square &from, Square &to) {};

                // method
                bool fromString(char* move);
                bool fromInt(int from,int to);
                Square getSquareFrom(void) {return _squareFrom;};
                Square getSquareTo(void) {return _squareTo ;};
                bool isValid(void);
                bool isItACapture(void);        


        private :
                Square _squareFrom ;
                Square _squareTo ;
                uint8_t _piece ;
                //captured






}; 




#endif // _MOVE_H_

