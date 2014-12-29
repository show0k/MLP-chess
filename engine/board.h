#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <vector>

#include "move.h"
#include "utils.h"

#define WHITE 1
#define BLACK -1
#define BLACKANDWHITE 2
#define PLAYERTOMOVE 3


typedef enum { // Directions
    // Idea from http://chessprogramming.wikispaces.com/Direction
    nort = 10, sout = -10, east = -1, west = 1,
    noWe = 11, soWe = -9, noEa = 9, soEa = -11,

    // Knight
    noNoWe = 21, noNoEa = 19, noWeWe = 12, noEaEa = 8,
    soSoWe = -19, soSoEa = -21, soWeWe = -8, soEaEa = -12
} EDirections;

// return weight of each piece (usefull for evaluation)
int materialWt(int8_t pieceCode) ;

class Board {

public:
    Board() :_playerToMove(WHITE) {};


    void newGame(void);
    void newGame(vector<uint8_t> &backupGame);
    void doMove(Move &move);
    void undoMove(Move &move);


    // display
    friend ostream &operator<<(ostream &out, const Board &b);

    // fin all legal move for a Square (player input is only use for getAllLegalMoves)
    void getLegalMoves(vector<Move> &moveLst, Square sq, int8_t player = BLACKANDWHITE) ;    

    // find all legal moves for all squares
    void getAllLegalMoves(vector<Move> &moveLst, int8_t player = PLAYERTOMOVE);

    //Fonction d'évaluation
    int32_t getEvaluation() ;

    // A déplacer dans Move
    bool IsMoveValid(Move &move);

    int8_t getPlayer() {
        return _playerToMove ;
    }

    const vector<uint8_t> INIT_GAME {
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
        X, X, X, X, X, X, X, X, X, X
    } ;
private:


    void swapPlayers() {
        if (_playerToMove == WHITE)
            _playerToMove = BLACK;
        else
            _playerToMove = WHITE ;

    };
    // plateau de jeu
    std::vector<uint8_t> _board;

    // Liste de tous les déplacements effectués
    std::vector<Move> _moveList ;

    // Black or white
    int8_t _playerToMove ;

    // count the occurenceof each piece on the board
    // usefull for evaluation
    vector<int> _pieceCounter ;


};


#endif // _BOARD_