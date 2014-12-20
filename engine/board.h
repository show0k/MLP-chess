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

#define WHITE true
#define BLACK false

typedef enum // Directions
{       // Idea from http://chessprogramming.wikispaces.com/Direction
        nort = 10, sout = -10, east = -1, west = 1,
        noWe = 11, soWe = -9, noNe = 9, soEa = -11,
        // Knight
        noNoWe = 21, noNoEa = 19, noWeWe = 12, noEaEa = 8,
        soSoWe = -19, soSoEa = -21, soWeWe = -8, soEaEa = -12
} EDirections;


class Board{

public:
        Board(){};
        void newGame(void);
        bool DoMove(Move &mouve);
        bool UndoMove(Move &mouve);

        // Trouve les déplacements possibles pour une pièce donnée
        std::vector<Move> getLegalMoves(Square sq) ;

        // Trouve les déplacements possibles pour toutes les pièces
        std::vector<Move> getAllLegalMoves();
        
        //Fonction d'évaluation
        int getValue() ;

        // A déplacer dans Move
        bool IsMoveValid(Move &move);

        //affiche le board dans la console
        void display();

private:
        
        void swapPlayer(){_playerToMove = !_playerToMove;}

        // plateau de jeu
        std::vector<uint8_t> _board;

        // Liste de tous les déplacements effectués
        std::vector<Move> _moveList ; 

        // Blanc ou noir
        bool _playerToMove ;


};


#endif // _BOARD_