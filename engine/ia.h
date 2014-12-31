#ifndef _IA_H_
#define _IA_H_
#include <string>
#include <stdio.h>

#include "board.h"
#include "api.h"


using namespace std;
class IA {
public:
    IA(Board &board, int level = 4) : _level(level), _board(board) {}
    Move findBestMove();

private:
    int _level ;
    int32_t search(int alpha, int beta, int depthleft);
    Board &_board;
}; 

#endif // _IA_H_