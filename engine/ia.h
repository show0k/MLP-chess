#ifndef _IA_H_
#define _IA_H_
#include <string>
#include <stdio.h>

#include "board.h"
using namespace std;
class IA {
public:
    IA(Board &board) : _board(board) {}
    Move findBestMove();

private:
    int search(int alpha, int beta, int level);
    Board &_board;
}; // end of class AI




#endif // _IA_H_