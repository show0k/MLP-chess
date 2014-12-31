#include "ia.h"


// To have moreinfo, see http://chessprogramming.wikispaces.com/Alpha-Beta
int32_t IA::alphabeta(int alpha, int beta, int depth) {

    int depthleft = depth;
    vector<Move> moveLst = vector<Move>();
    int32_t bestscore = -999;
    _board.getAllLegalMoves(moveLst);
    int32_t score ;
    if (depthleft == 0) return _board.getEvaluation(); // TODO : quiesce
    for (Move move : moveLst) {
        score = -alphabeta(-beta, -alpha, depthleft - 1);
        if (score >= beta)
            return score;  // fail-soft beta-cutoff
        if (score > bestscore) {
            bestscore = score;
            if (score > alpha)
                alpha = score;
        }
    }
    return bestscore;

} // end of int alphabeta


Move IA::findBestMove(int depth) {
    // Make a list of all legal moveLst
    vector<Move> moveLst = vector<Move>();
    _board.getAllLegalMoves(moveLst);

    engine_cout << "info " << moveLst.size() << " legal moves" << std::endl;

    vector<Move> bestMoveLst = vector<Move>(); // Array of the (one or more) best moveLst so far
    int best_val = -999;

    // alphabeta through all legal moveLst
    // for (uint i = 0; i < moveLst.size(); i++) {
    for (Move move : moveLst) {
        // Move move = moveLst[i];

        // Get value of current move
        _board.doMove(move);
        // cout << "DEBUG findBestMove level=" << _level << " " ;
        int val = -alphabeta(-999, 999, depth);
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