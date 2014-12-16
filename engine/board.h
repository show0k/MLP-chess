#ifndef _BOARD_H_
#define _BOARD_H_

#include <string.h> 
#include <stdio.h> 
#include <iostream> 
#include <stdint.h>
#include <vector>

#include "square.h"
#include "move.h"

#define WHITE 1
#define BLACK -1

typedef enum // Directions
{
    N = 10, S = -10, E = -1, W = 1,
    NW = 11, SW = -9, NE = 9, SE = -11,
    NNW = 21, NNE = 19, NWW = 12, NEE = 8,
    SSW = -19, SSE = -21, SWW = -8, SEE = -12
} EDirections;


class Board{

public:
        Board(){};
        bool newGame();
        bool DoMove(Move &mouve);
        bool UndoMove(Move &mouve);

        // Trouve les déplacements possibles pour une pièce donnée
        std::vector<Move> findLegalMoves(Square sq) ;

        // Trouve les déplacements possibles pour toutes les pièces
        std::vector<Move> findAllLegalMoves();
        
        //Fonction d'évaluation
        int getValue() ;

        // A déplacer dans Move
        bool IsMoveValid(Move &move);

        //affiche le board dans la console
        void display();

private:
        
        void swapPlayer(){_playerToMove = -_playerToMove;}

        // plateau de jeu
        std::vector<int8_t> _board;

        // Liste de tous les déplacements effectués
        std::vector<Move> _moveList ; 

        int _playerToMove ;

        








};



#endif // _BOARD_