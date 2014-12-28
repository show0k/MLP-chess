#ifndef _MOVE_H_
#define _MOVE_H_

#include <string>
#include <iostream>


#include "square.h"
#include "utils.h"


using namespace std;


typedef enum {
    _  = 0,   // Empty
    P = 1,   // White Pawn
    N = 2,   // White Knight
    B = 3,   // White Bishop
    R = 4,   // White Rook
    Q = 5,   // White Queen
    K = 6,   // White King

    p = 7,   // Black Pawn
    n = 8,   // Black Knight
    b = 9,   // Black Bishop
    r = 10,   // Black Rook
    q = 11,   // Black Queen
    k = 12,   // Black King
    X = 99   // INVALID

} EPieceCode;

//Fonctions
string pieceToStr(uint8_t piece);
string pieceToStr(uint8_t piece, bool color) ;


class Move {
public:
    // Constructors
    // Move(string fromTo) {
    //     fromString(fromTo);
    // };
    // Move(Square &from, Square &to) {};
    // Move(uint8_t piece, Square &from, Square &to, uint8_t pieceCaptured):
    //     _piece(piece), _squareFrom(from), _squareTo(to), _pieceCaptured(pieceCaptured) {}


    Move(uint8_t piece, Square &from, Square &to, uint8_t pieceCaptured = _, uint8_t piecePromoted = _):
        _piece(piece), _squareFrom(from), _squareTo(to), _pieceCaptured(pieceCaptured), _piecePromoted(piecePromoted) {}


    // display
    friend ostream &operator<<(ostream &out, const Move &m);
    // methods
    bool fromString(string move);
    bool fromInt(int from, int to);
    Square getSquareFrom(void) {
        return _squareFrom;
    };
    Square getSquareTo(void) {
        return _squareTo ;
    };
    bool isValid(void);
    bool isItACapture(void);




private :

    uint8_t _piece ;
    Square _squareFrom ;
    Square _squareTo ;
    int8_t _pieceCaptured;
    int8_t _piecePromoted;


};




#endif // _MOVE_H_

