#include "ia.h"


// To have moreinfo, see http://chessprogramming.wikispaces.com/Alpha-Beta
int32_t IA::alphabeta(int32_t alpha, int32_t beta, int32_t depth) {

    // int32_t depthleft = depth;
    // vector<Move> moveLst = vector<Move>();
    // int32_t32_t bestscore = -999;
    // _board.getAllLegalMoves(moveLst);
    // int32_t32_t score ;
    // if (depthleft == 0) return _board.getEvaluation(); // TODO : quiesce
    // for (Move move : moveLst) {
    //     score = -alphabeta(-beta, -alpha, depthleft - 1);
    //     if (score >= beta)
    //         return score;  // fail-soft beta-cutoff
    //     if (score > bestscore) {
    //         bestscore = score;
    //         if (score > alpha)
    //             alpha = score;
    //     }
    // }
    // return bestscore;




    vector<Move> moveLst = vector<Move>();
    if (depth == 0)
        return _board.getEvaluation(); // We are at leaf, just return the static evaluation.

    _board.getAllLegalMoves(moveLst);

    int32_t score = -20000; // Assume the worst

    for (Move move : moveLst) {
        if (score >= beta) {
            // This is the alpha-beta pruning.
            // Stop alphabetaing, if we already have found a "killer" move.
            break;
        }
        if (score > alpha) {
            // This is part of the alpha-beta pruning too.
            // Tighten the alphabeta window.
            alpha = score;
        }
        // cout << "DEBUG alphabeta1 " ;
        if (move.isCapturedAKing()) {
            return 10000 + depth; // Opponent's king can be captured. That means he is check-mated.
        }

        _board.doMove(move);
        int32_t num = -alphabeta(-beta, -alpha, depth - 1);
        _board.undoMove(move);

        if (num > score) {
            score = num;
        }
    }
    return score;

}


Move IA::findBestMove(int32_t depth) {
    // Make a list of all legal moveLst

    vector<Move> moveLst = vector<Move>();
    _board.getAllLegalMoves(moveLst);
    _board.cleanChecksFromMoveLst(moveLst) ;

    // Addapt the time of search
    int level = depth ;
    if (moveLst.size() <= 10 && level < 4) level ++ ;
    else if (moveLst.size() <= 6 && level < 5) level +=2 ;

    engine_cout << "debug string " << moveLst.size() << " legal moves" << std::endl;
    engine_cout << "debug string depth = " << level << std::endl;

    vector<Move> bestMoveLst = vector<Move>(); // Array of the (one or more) best moveLst so far
    int32_t best_val = -20000;

    // alphabeta through all legal moveLst
    for (Move move : moveLst) {
        // Get value of current move
        _board.doMove(move);
        // cout << "DEBUG findBestMove level=" << _level << " " ;
        int32_t val = -alphabeta(-20000, 20000, level);
        _board.undoMove(move);

        engine_cout << "debug string eval = " << val << " : " << move << std::endl;

        if (val > best_val) {
            best_val = val;
            bestMoveLst.clear();
            bestMoveLst.push_back(move);
        } else if (val == best_val) {
            bestMoveLst.push_back(move);
        }
    }

    if (bestMoveLst.size() == 0) {
        engine_cout << "invalid : No legal moveLst!" << std::endl;
        //exit(1);
        return Move() ;
    }

    //IA cannot go in checks !
    _board.cleanChecksFromMoveLst(bestMoveLst) ;

    return bestMoveLst[rand() % bestMoveLst.size()];
} // end of find_best_move