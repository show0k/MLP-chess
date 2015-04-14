/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
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
uint8_t pieceFromStr(const char pieceStr) ;


class Move {
public:
    // Constructors
    Move(string fromTo) : _piece(X), _pieceCaptured(X), _piecePromoted(X) {
        fromString(fromTo);
    }

    Move(void) : _piece(X), _squareFrom(0), _squareTo(0), _pieceCaptured(X), _piecePromoted(X) {}

    Move(uint8_t piece, Square &from, Square &to, uint8_t pieceCaptured = _, uint8_t piecePromoted = _):
        _piece(piece), _squareFrom(from), _squareTo(to), _pieceCaptured(pieceCaptured),
        _piecePromoted(piecePromoted) {}


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

    bool isCapturedAKing() {
        return _pieceCaptured == k || _pieceCaptured == K ;
    } ;

    void setPiece(uint8_t piece) {
        _piece = piece ;
    }
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
    void setPieceCaptured(int8_t piece) {
        _pieceCaptured = piece ;
    };
    int8_t getPieceCaptured() {
        return _pieceCaptured;
    };
    void setPiecePromoted(int8_t piece) {
        _piecePromoted = piece ;
    };
    int8_t getPiecePromoted() {
        return _piecePromoted;
    };

private :

    uint8_t _piece ;
    Square _squareFrom ;
    Square _squareTo ;
    int8_t _pieceCaptured;
    int8_t _piecePromoted;


};

#endif // _MOVE_H_

