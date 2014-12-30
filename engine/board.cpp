#include "board.h"



ostream &operator<<(ostream &out, const Board &b) { // output

    for (int i = 8 ; i > 0 ; i--) {
        out << "\n" << i << "  ";
        for (int j = 0; j < 8; j++) {
            out  << pieceToStr(b._board[10 * (i + 1) + j + 1], 1) << " ";
        }

    }
    out << "\n\n   a b c d e f g h \n" ;
    return out;
}

int materialWt(int8_t pieceCode) {

    switch (pieceCode) {
        case p: case P: return 1; break;
        case b: case B: case n: case N: return 3; break;
        case r: case R: return 5; break;
        case q: case Q: return 9; break;
        case k: case K: return 200; break;
        default : return 0 ;
    }

}

void Board::newGame(void) {

    _pieceCounter.clear();
    _pieceCounter.reserve(100);
    _board.reserve(120);
    for (int i = 0; i < 120; i++) {
        _pieceCounter[INIT_GAME[i]] += 1 ;
        _board[i] = INIT_GAME[i];
    }
}

void Board::newGame(vector<uint8_t> &backupGame) {

    _pieceCounter.clear();
    _pieceCounter.reserve(100);
    _board.reserve(120);
    for (int i = 0; i < 120; i++) {
        _pieceCounter[backupGame[i]] += 1 ;
        _board[i] = backupGame[i];
    }
}




void Board::doMove(Move &move) {

    _board[move.getSquareTo()] = _board[move.getSquareFrom()];
    _board[move.getSquareFrom()] = _ ;
    if (move.getPiecePromoted() != _) {
        _board[move.getSquareTo()] = move.getPiecePromoted();
        _pieceCounter[move.getPiecePromoted()] += 1 ;
        _pieceCounter[move.getPiece()] -= 1 ;
    }
    if (move.getPieceCaptured() != _) {
        _pieceCounter[move.getPieceCaptured()] -= 1 ;
    }

    swapPlayers() ;

}

void Board::undoMove(Move &move) {


    _board[move.getSquareFrom()] = move.getPiece();
    _board[move.getSquareTo()] = move.getPieceCaptured();

    //for evaluation
    if (move.getPieceCaptured() != _) {
        _pieceCounter[move.getPieceCaptured()] += 1;
    }
    if (move.getPiecePromoted() != _) {
        _pieceCounter[move.getPiecePromoted()] -= 1 ;
        _pieceCounter[move.getPiece()] += 1 ;
    }

    swapPlayers();
}


bool Board::isKingInCheck(void) {
    EPieceCode king ;
    vector<Move> moveLst ;
    if (_playerToMove == WHITE) {
        king = K ;
        getAllLegalMoves(moveLst, BLACK);
    } else if (_playerToMove == BLACK) {
        king = k ;
        getAllLegalMoves(moveLst, WHITE);
    }

    for (Move m : moveLst) {
        if (_board[m.getSquareTo()] == king) return true ;
    }
    return false ;
}

bool Board::isMoveValid(Move &move) {
    vector<Move> moveLst ;
    getAllLegalMoves(moveLst) ;
    for (Move m : moveLst) {
        if (m == move) {
            // l'égalité ne prend pas en compte les pieces promu et capturées
            move.setPieceCaptured(m.getPieceCaptured()) ;
            move.setPiecePromoted(m.getPiecePromoted()) ;
            return true ;
        }
    }
    return false ;
}


/**
* inspired from http://chessprogramming.wikispaces.com/Evaluation
* material score depending on the piece value
* mobility score depending on the number of legal values
*
*/

int32_t Board::getEvaluation() {

    vector<Move> moveLst = vector<Move>() ;

    // weight from Larry Kaufman
    int32_t materialScore =
        10000 * (_pieceCounter[K] - _pieceCounter[k])
        + 1000 * (_pieceCounter[Q] - _pieceCounter[q])
        + 525 * (_pieceCounter[R] - _pieceCounter[r])
        + 350 * (_pieceCounter[B] - _pieceCounter[b])
        + 350 * (_pieceCounter[N] - _pieceCounter[n])
        + 100 * (_pieceCounter[P] - _pieceCounter[p]) ;

    // TODO :
    // add piece Sqaure table : https://chessprogramming.wikispaces.com/Simplified+evaluation+function
    // add bonus for bishops complementarity
    // add Penalty for the rook pair


    getAllLegalMoves(moveLst, WHITE) ;
    int32_t wMobility = moveLst.size() ;
    moveLst.clear();
    getAllLegalMoves(moveLst, BLACK);
    int32_t bMobility = moveLst.size() ;

    int32_t mobilityScore = 5 * (wMobility - bMobility) ;


    return (materialScore + mobilityScore) * _playerToMove ;
}


void Board::getLegalMoves(std::vector<Move> &moveLst, Square sq, int8_t player) {
    // vector<Move> moveLst = vector<Move>();
    int8_t piece = _board[sq];
    Square sqDest ;
    if (player ==  BLACKANDWHITE || player == WHITE) {
        // cout << "player WHITE " ;
        switch (piece) {
            // WHITE
            case P :  //white pawn
                //if nothing in front of the pawn
                sqDest = sq + nort ;
                if (_board[sqDest] == _) {
                    if (sq >= A7) { //if promoted
                        //promoted as queen
                        Move move(piece, sq, sqDest, _, Q);
                        moveLst.push_back(move);

                    } else { //regular move
                        Move move(piece, sq, sqDest, _);
                        moveLst.push_back(move);

                    }

                    sqDest = sq + nort + nort ;
                    //if no capture
                    if (_board[sqDest] == _) {
                        //if on the second rank ->
                        if (sq <= H2) {
                            Move move(piece, sq, sqDest, _);
                            moveLst.push_back(move);
                        }
                    }
                }
                // diagonalS
                sqDest = sq + noEa ;

                // if not invalid and is an ennemy
                if (_board[sqDest] != X && _board[sqDest] > _) {
                    if (sq >= A7) { // if promoted
                        Move move(piece, sq, sqDest, _board[sqDest], Q);
                        moveLst.push_back(move);
                    } else {
                        Move move(piece, sq, sqDest, _board[sqDest]);
                        moveLst.push_back(move);
                    }
                }

                sqDest = sq + noWe ;
                // if not invalid and is an ennemy
                if ((_board[sqDest] != X && _board[sqDest] > _)) {
                    if (sq >= A7) { // if promoted
                        Move move(piece, sq, sqDest, _board[sqDest], q);
                        moveLst.push_back(move);
                    } else {
                        Move move(piece, sq, sqDest, _board[sqDest]);
                        moveLst.push_back(move);
                    }
                }

                break;

            // white Knight
            case N : {
                    vector<int8_t> dirLst = {noNoWe, noNoEa, noWeWe, noEaEa, soSoWe, soSoEa, soWeWe, soEaEa};

                    for (int8_t dir : dirLst) {
                        // cout << "N:" << _board[sqDest];
                        sqDest = sq + dir;
                        if (_board[sqDest] != X && _board[sqDest] >= _) {
                            Move move(piece, sq, sqDest, _board[sqDest]);
                            moveLst.push_back(move);
                        }
                    }
                    // cout << "\n" ;
                }

                break;

            case B : { // White bishop
                    vector<int8_t> dirLst = {noEa, noWe, soEa, soWe};

                    for (int8_t dir : dirLst) {
                        sqDest = sq;
                        while (1) {
                            sqDest = dir + sqDest;
                            // if invalid
                            if (_board[sqDest] == X) break;
                            //if empty
                            if (_board[sqDest] == _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);

                                // if ennemy
                            } else if (_board[sqDest] > _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                                break;

                            } else
                                break;
                        }
                    }
                }

                break;

            case R : { // White rook
                    vector<int8_t> dirLst = {nort, east, sout, west};

                    for (int8_t dir : dirLst) {
                        sqDest = sq;
                        while (1) {
                            sqDest = dir + sqDest;
                            // if invalid
                            if (_board[sqDest] == X) break;
                            //if empty
                            if (_board[sqDest] == _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);

                                // if ennemy
                            } else if (_board[sqDest] > _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                                break;

                            } else
                                break;

                        }
                    }
                }

                break;

            case Q : { // White queen
                    vector<int8_t> dirLst = {noEa, noWe, soEa, soWe, nort, east, sout, west};
                    for (int8_t dir : dirLst) {
                        sqDest = sq;
                        while (1) {
                            sqDest = dir + sqDest;
                            // if invalid
                            if (_board[sqDest] == X) break;
                            //if empty
                            if (_board[sqDest] == _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);

                                // if ennemy
                            } else if (_board[sqDest] > _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                                break;

                            } else
                                break;

                        }
                    }
                }

                break;

            case K : { // White king
                    vector<int8_t> dirLst = {noEa, noWe, soEa, soWe, nort, east, sout, west};
                    for (int8_t dir : dirLst) {
                        sqDest = sq + dir;
                        if (_board[sqDest] != X && _board[sqDest] >= _) {
                            Move move(piece, sq, sqDest, _board[sqDest]);
                            moveLst.push_back(move);
                        }
                    }

                }

                break;

                //BLACK
        }
    }
    if (player ==  BLACKANDWHITE || player == BLACK) {
        // cout << "player BLACK " ;

        switch (piece) {
            case p : //Black pawn
                //if nothing in front of the pawn
                sqDest = sq + sout ;
                if (_board[sqDest] == _) {
                    if (sq <= H2) { //if promoted
                        //promoted as queen
                        Move move(piece, sq, sqDest, _, q);
                        moveLst.push_back(move);

                    } else { //regular move
                        Move move(piece, sq, sqDest, _);
                        moveLst.push_back(move);

                    }

                    sqDest = sq + sout + sout ;
                    //if no capture
                    if (_board[sqDest] == _) {

                        //if on the second rank ->
                        if (sq >= A7) {
                            Move move(piece, sq, sqDest, _);
                            moveLst.push_back(move);
                        }
                    }
                }
                // diagonalS
                sqDest = sq + soEa ;

                // if not invalid and is an ennemy
                if (_board[sqDest] != X && _board[sqDest] < _) {
                    if (sq <= H2) { // if promoted
                        Move move(piece, sq, sqDest, _board[sqDest], q);
                        moveLst.push_back(move);
                    } else {
                        Move move(piece, sq, sqDest, _board[sqDest]);
                        moveLst.push_back(move);
                    }
                }

                sqDest = sq + soWe ;
                // if not invalid and is an ennemy
                if ((_board[sqDest] != X && _board[sqDest] < _)) {
                    if (sq <= H2) { // if promoted
                        Move move(piece, sq, sqDest, _board[sqDest], q);
                        moveLst.push_back(move);
                    } else {
                        Move move(piece, sq, sqDest, _board[sqDest]);
                        moveLst.push_back(move);
                    }
                }

                break;

            // Black Knight
            case n : {
                    vector<int8_t> dirLst = {noNoWe, noNoEa, noWeWe, noEaEa, soSoWe, soSoEa, soWeWe, soEaEa};

                    for (int8_t dir : dirLst) {
                        sqDest = sq + dir;
                        if (_board[sqDest] != X && _board[sqDest] <= _) {
                            Move move(piece, sq, sqDest, _board[sqDest]);
                            moveLst.push_back(move);
                        }
                    }
                }

                break;

            case b : { // Black bishop
                    vector<int8_t> dirLst = {noEa, noWe, soEa, soWe};

                    for (int8_t dir : dirLst) {
                        sqDest = sq;
                        while (1) {
                            sqDest = dir + sqDest;
                            // if invalid
                            if (_board[sqDest] == X) break;
                            //if empty
                            if (_board[sqDest] == _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);

                                // if ennemy
                            } else if (_board[sqDest] < _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                                break;

                            } else
                                break;
                        }
                    }
                }

                break;


            case r : { // Black rook
                    vector<int8_t> dirLst = {nort, east, sout, west};

                    for (int8_t dir : dirLst) {
                        sqDest = sq;
                        while (1) {
                            sqDest = dir + sqDest;
                            // if invalid
                            if (_board[sqDest] == X) break;
                            //if empty
                            if (_board[sqDest] == _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);

                                // if ennemy
                            } else if (_board[sqDest] < _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                                break;

                            } else
                                break;

                        }
                    }
                }

                break;

            case q : { // Black queen
                    vector<int8_t> dirLst = {noEa, noWe, soEa, soWe, nort, east, sout, west};
                    for (int8_t dir : dirLst) {
                        sqDest = sq;
                        while (1) {
                            sqDest = dir + sqDest;
                            // if invalid
                            if (_board[sqDest] == X) break;
                            //if empty
                            if (_board[sqDest] == _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);

                                // if ennemy
                            } else if (_board[sqDest] < _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                                break;

                            } else
                                break;

                        }
                    }
                }

                break;

            case k: { // Black king
                    vector<int8_t> dirLst = {noEa, noWe, soEa, soWe, nort, east, sout, west};
                    for (int8_t dir : dirLst) {
                        sqDest = sq + dir;
                        if (_board[sqDest] != X) {
                            if (_board[sqDest] == _ ||  _board[sqDest] < _) {
                                Move move(piece, sq, sqDest, _board[sqDest]);
                                moveLst.push_back(move);
                            }
                        }
                    }

                }

                break;
        }
    }

}

void Board::getAllLegalMoves(vector<Move> &moveLst, int8_t player) {

    Square sq ;
    moveLst.clear();
    if (player == PLAYERTOMOVE)
        player = _playerToMove ;
    for (int i = 8 ; i > 0 ; i--) {
        for (int j = 0; j < 8; j++) {
            sq = 10 * (i + 1) + j + 1 ;
            getLegalMoves(moveLst, sq, player) ;
        }

    }

}

