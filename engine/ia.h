/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#ifndef _IA_H_
#define _IA_H_
#include <string>
#include <stdio.h>

#include "board.h"
#include "api.h"


using namespace std;
class IA {
public:
    IA(Board &board) : _board(board) {}
    Move findBestMove(int depth = 4);

private:
    int32_t alphabeta(int32_t alpha, int32_t beta, int32_t depth);
    Board& _board;
}; 

#endif // _IA_H_