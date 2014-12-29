#ifndef _BOARD_H_
#define _BOARD_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <vector>

#include "move.h"
#include "utils.h"

#define WHITE 1
#define BLACK 0
#define BLACKANDWHITE 2

typedef enum { // Directions
    // Idea from http://chessprogramming.wikispaces.com/Direction
    nort = 10, sout = -10, east = -1, west = 1,
    noWe = 11, soWe = -9, noEa = 9, soEa = -11,

    // Knight
    noNoWe = 21, noNoEa = 19, noWeWe = 12, noEaEa = 8,
    soSoWe = -19, soSoEa = -21, soWeWe = -8, soEaEa = -12
} EDirections;


class Board {

public:
    Board() {};
    void newGame(void);
    bool DoMove(Move &mouve);
    bool UndoMove(Move &mouve);


    // display
    friend ostream &operator<<(ostream &out, const Board &b);

    // Trouve les déplacements possibles pour une pièce donnée
    void getLegalMoves(vector<Move> &moveLst, Square sq, char player = BLACKANDWHITE) ;

    // Trouve les déplacements possibles pour toutes les pièces
    void getAllLegalMoves(vector<Move> &moveLst, char player = BLACKANDWHITE);

    //Fonction d'évaluation
    int getValue() ;

    // A déplacer dans Move
    bool IsMoveValid(Move &move);

    void swapPlayers() {
        if (_playerToMove == WHITE)
            _playerToMove = BLACK;
        else
            _playerToMove = WHITE ;

    };
private:


    // plateau de jeu
    std::vector<uint8_t> _board;

    // Liste de tous les déplacements effectués
    std::vector<Move> _moveList ;

    // Blanc ou noir
    char _playerToMove ;


};


#endif // _BOARD_