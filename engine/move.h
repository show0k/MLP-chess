#ifndef _MOVE_H_
#define _MOVE_H_

#include <string> 
#include <iostream> 

typedef enum {
    EM = 0,   // Empty
    P = 1,   // White Pawn
    N = 2,   // White Knight
    B = 3,   // White Bishop
    R = 4,   // White Rook
    Q = 5,   // White Queen
    K = 6,   // White King
    p = -1,  // Black Pawn
    n = -2,  // Black Knight
    b = -3,  // Black Bishop
    r = -4,  // Black Rook
    q = -5,  // Black Queen
    k = -6,  // Black King
    IV = 99   // INVALID
} e_piece;


class Move
{
    public:
        // Constructors
        Move(string move) : {}
        
        
        
       



}; 

#endif // _MOVE_H_

