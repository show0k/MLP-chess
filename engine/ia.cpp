#include "ia.h"


// To have moreinfo, see http://chessprogramming.wikispaces.com/Alpha-Beta
int32_t IA::search(int alpha, int beta, int depthleft) {

    vector<Move> moveLst = vector<Move>();
    int32_t bestscore = -999;
    _board.getAllLegalMoves(moveLst);
    int32_t score ;
    if (depthleft == 0) return _board.getEvaluation(); // TODO : quiesce
    for (Move move : moveLst) {
        score = -search(-beta, -alpha, depthleft - 1);
        if (score >= beta)
            return score;  // fail-soft beta-cutoff
        if (score > bestscore) {
            bestscore = score;
            if (score > alpha)
                alpha = score;
        }
    }
    return bestscore;




    // vector<Move> moveLst = vector<Move>();
    // if (level == 0)
    //     return _board.getEvaluation(); // We are at leaf, just return the static evaluation.

    // _board.getAllLegalMoves(moveLst);

    // int best_val = -999; // Assume the worst

    // // Search through all legal moveLst
    // for (Move move : moveLst) {
    //     if (best_val >= beta) {
    //         // This is the alpha-beta pruning.
    //         // Stop searching, if we already have found a "killer" move.
    //         break;
    //     }
    //     if (best_val > alpha) {
    //         // This is part of the alpha-beta pruning too.
    //         // Tighten the search window.
    //         alpha = best_val;
    //     }
    //     // cout << "DEBUG search1 " ;
    //     if (move.isCapturedAKing()) {
    //         return 900 + level; // Opponent's king can be captured. That means he is check-mated.
    //     }

    //     // cout << "DEBUG search2 " ;
    //     // Do a recursive search
    //     _board.doMove(move);
    //     int num = -search(-beta, -alpha, level - 1);
    //     _board.undoMove(move);

    //     if (num > best_val) {
    //         // Store the best value so far.
    //         best_val = num;
    //     }
    // }

    // return best_val;


    // for (Move move : moveLst) {
    //        if (best_val >= beta) {
    //            // This is the alpha-beta pruning.
    //            // Stop searching, if we already have found a "killer" move.
    //            break;
    //        }
    //        if (best_val > alpha) {
    //            // This is part of the alpha-beta pruning too.
    //            // Tighten the search window.
    //            alpha = best_val;
    //        }
    //        // cout << "DEBUG search1 " ;
    //        if (move.isCapturedAKing()) {
    //            return 900 + level; // Opponent's king can be captured. That means he is check-mated.
    //        }

    //        // cout << "DEBUG search2 " ;
    //        // Do a recursive search
    //        _board.doMove(move);
    //        int num = -search(-beta, -alpha, level - 1);
    //        _board.undoMove(move);

    //        if (num > best_val) {
    //            // Store the best value so far.
    //            best_val = num;
    //        }
    //    }

    //    return best_val;

} // end of int search

/***************************************************************
 * find_best_move
 *
 * This is the main AI.
 * It returns what it considers to be the best legal move in the
 * current position.
 ***************************************************************/
Move IA::findBestMove() {
    // Make a list of all legal moveLst
    vector<Move> moveLst = vector<Move>();
    _board.getAllLegalMoves(moveLst);

    engine_cout << "info " << moveLst.size() << " legal moveLst." << std::endl;

    vector<Move> bestMoveLst = vector<Move>(); // Array of the (one or more) best moveLst so far
    int best_val = -999;

    // Search through all legal moveLst
    // for (uint i = 0; i < moveLst.size(); i++) {
    for (Move move : moveLst) {
        // Move move = moveLst[i];

        // Get value of current move
        _board.doMove(move);
        cout << "DEBUG findBestMove level=" << _level << " " ;
        int val = -search(-999, 999, _level);
        _board.undoMove(move);

        engine_cout << "info string " << val << " : " << move << std::endl;

        if (val > best_val) {
            best_val = val;
            bestMoveLst.clear();
            bestMoveLst.push_back(move);
        } else if (val == best_val) {
            bestMoveLst.push_back(move);
        }
    }

    if (bestMoveLst.size() == 0) {
        engine_cout << "BUG: No legal moveLst!" << std::endl;
        exit(1);
    }

    return bestMoveLst[rand() % bestMoveLst.size()];
} // end of find_best_move