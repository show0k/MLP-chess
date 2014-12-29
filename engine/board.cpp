#include "board.h"



ostream &operator<<(ostream &out, const Board &b) { // output

    for (int i = 8 ; i > 0 ; i-- ) {
        out << "\n" << i << "  ";
        for (int j = 0; j < 8; j++) {
            out  << pieceToStr(b._board[10 * (i + 1) + j + 1], 1) << " ";
        }

    }
    out << "\n\n   a b c d e f g h \n" ;
    return out;
}

void Board::newGame() {
    uint8_t initial[120] = {
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

    _board.reserve(120);
    for (int i = 0; i < 120; i++) {
        _board[i] = initial[i];
        //cout << _board[i] <<" ";
    }
}



void Board::getLegalMoves(std::vector<Move> &moveLst, Square sq, char player) {
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
                            if (_board[sqDest] == _ ) {
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
                            if (_board[sqDest] == _ ) {
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
                            if (_board[sqDest] == _ ) {
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
                            if (_board[sqDest] == _ ) {
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
                            if (_board[sqDest] == _ ) {
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
                            if (_board[sqDest] == _ ) {
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

void Board::getAllLegalMoves(vector<Move> &moveLst, char player) {

    Square sq ;
    moveLst.clear();
    for (int i = 8 ; i > 0 ; i-- ) {
        for (int j = 0; j < 8; j++) {
            sq = 10 * (i + 1) + j + 1 ;
            getLegalMoves(moveLst, sq, player) ;
        }

    }

}

