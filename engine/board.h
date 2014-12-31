#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <stdint.h>
#include <vector>
#include <assert.h>

#include "move.h"
#include "utils.h"

#define WHITE 1
#define BLACK -1
#define BLACKANDWHITE 2
#define PLAYERTOMOVE 3

#define WHITE_WIN 1
#define BLACK_WIN 2
#define MATE 3


typedef enum { // Directions
    // Idea from http://chessprogramming.wikispaces.com/Direction
    nort = 10, sout = -10, east = -1, west = 1,
    noWe = 11, soWe = -9, noEa = 9, soEa = -11,

    // Knight
    noNoWe = 21, noNoEa = 19, noWeWe = 12, noEaEa = 8,
    soSoWe = -19, soSoEa = -21, soWeWe = -8, soEaEa = -12
} EDirections;


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


class Board {

public:
    Board()  {};


    void newGame(void) ;
    void newGame(string &input);
    void doMove(Move &move);
    void undoMove(Move &move);


    // display
    friend ostream &operator<<(ostream &out, const Board &b);

    //Copy constructor
    // Board(const Board &b) {
    //     _board = b._board;
    //     _moveList = b._moveList;
    //     _playerToMove = b._playerToMove;
    //     _pieceCounter = b. _pieceCounter;
    // } ;



    // fin all legal move for a Square (player input is only use for getAllLegalMoves)
    void getLegalMoves(vector<Move> &moveLst, Square sq, int8_t player = BLACKANDWHITE) ;

    // find all legal moves for all squares
    void getAllLegalMoves(vector<Move> &moveLst, int8_t player = PLAYERTOMOVE);

    //Fonction d'évaluation
    int32_t getEvaluation() ;

    // A déplacer dans Move
    bool isValidMove(Move &move);



    bool isKingInCheck(void);
    bool isOtherKingInCheck(void);

    // return true if this move make a chess (assume is it a valid move)
    bool isMoveGoToChess(Move move) ;

    // delete checks move from move liste
    // return number of move deleted
    int cleanChecksFromMoveLst(vector<Move> &moveLst) ;

    //return 0 if nothing
    // 1 if WHITE win
    // 2 if BLACK win
    // 3 if mate
    int getStateOfChessBoard(void);

    int8_t getPlayer() {
        return _playerToMove ;
    }

    // Print the current board as in UCI specification (ex : rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR)
    string getBackupGame() ;

    // pop the last move
    bool undoLastMove(void) {
        int movesCount = _moveList.size() ;
        if (movesCount == 0)
            return false ;
        else {
            undoMove(_moveList[movesCount - 1]);
            return true ;
        }
    }


private:

    bool parseNewGame(string &input, vector<uint8_t> &backupGame) ;
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