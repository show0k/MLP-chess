/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#ifndef _API_H_
#define _API_H_


#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "board.h"
#include "ia.h"


#define engine_cin std::cin
#define engine_cout std::cout

using namespace std;

const int8_t TERMINAL = 0;
const int8_t GUI = 1;

void displayMoveLst(vector<Move> &moves);
void help(void);

class API {
public :
    API(int8_t state = GUI): _state(state), _gameStarted(0) {
        _moveLst.reserve(500) ;
        _negamaxLevel = 3;
    }
    // istream inputStream = cin, ostream outputStream = cout
    // , inputStream(inputStream), outputStream(outputStream

    void loop();//int argc, char *argv[]);
    void invalid(string cmd, string other = "") ;
    void move(string cmd) ;
    void show(string cmd) ;
    void go(void) ;
    void newgame(string cmd) ;
    void displayTerminalInfo(void) ;
    void setDificulty(string cmd);
    bool displayVictoryOrDoNothing(void) ;


private :
    int _negamaxLevel ;
    int8_t _state;
    Board _board;
    vector<Move> _moveLst;
    bool _gameStarted ;


};

#endif  // _API_H_