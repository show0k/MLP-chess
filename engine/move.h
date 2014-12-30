#ifndef _MOVE_H_
#define _MOVE_H_

#include <string>
#include <iostream>


#include "square.h"
#include "utils.h"


using namespace std;


typedef enum {
    _  = 7,   // Empty
    P = 1,   // White Pawn
    N = 2,   // White Knight
    B = 3,   // White Bishop
    R = 4,   // White Rook
    Q = 5,   // White Queen
    K = 6,   // White King

    p = 8,   // Black Pawn
    n = 9,   // Black Knight
    b = 10,   // Black Bishop
    r = 11,   // Black Rook
    q = 12,   // Black Queen
    k = 13,   // Black King
    X = 99   // INVALID

} EPieceCode;

//Fonctions
string pieceToStr(uint8_t piece);
string pieceToStr(uint8_t piece, bool color) ;


class Move {
public:
    // Constructors
    Move(string fromTo) {
        fromString(fromTo);
    };

    Move(uint8_t piece, Square &from, Square &to, uint8_t pieceCaptured = _, uint8_t piecePromoted = _):
        _piece(piece), _squareFrom(from), _squareTo(to), _pieceCaptured(pieceCaptured), _piecePromoted(piecePromoted) {}


    //Copy constructor
        // BUGGGGGG ??????????????????????????????????
    // Move(const Move &m) {
    //     _piece = m._piece;
    //     _squareFrom = m._squareFrom;
    //     _pieceCaptured = m._pieceCaptured;
    //     _piecePromoted = m._piecePromoted;
    // } ;

    // display
    friend ostream &operator<<(ostream &out, const Move &m);

    // overload operator
    friend bool operator==(Move &lhs, Move &rhs) {
        return lhs._squareFrom == rhs._squareFrom && lhs._squareTo == rhs._squareTo;
    }
    friend bool operator!=(Move &lhs, Move &rhs) {
        return lhs._squareFrom != rhs._squareFrom || lhs._squareTo != rhs._squareTo;
    }


    // methods
    void fromString(string &move);
    bool fromInt(int from, int to);


    //  Getter and setter
    uint8_t getPiece(void) {
        return _piece ;
    };

    Square getSquareFrom(void) {
        return _squareFrom;
    };
    Square getSquareTo(void) {
        return _squareTo ;
    };
    int8_t getPieceCaptured() {
        return _pieceCaptured;
    };
    void setPieceCaptured(int8_t piece) {
        _pieceCaptured = piece ;
    };
    void setPiecePromoted(int8_t piece) {
        _piecePromoted = piece ;
    };
    int8_t getPiecePromoted() {
        return _piecePromoted;
    };

    int compare(Move &move) {
        if (move._squareFrom == _squareFrom && move._squareTo == _squareTo)
            return 0 ;
        else return 1 ;

    }
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

