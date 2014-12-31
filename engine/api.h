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
    }
    // istream inputStream = cin, ostream outputStream = cout
    // , inputStream(inputStream), outputStream(outputStream

    void loop();//int argc, char *argv[]);
    void invalid(string cmd) ;
    void move(string cmd) ;
    void show(string cmd) ;
    void go(void) ;
    void newgame(string cmd) ;
    void displayTerminalInfo(void) ;
    void setDificulty(string cmd);


private :
    int _negamaxLevel ;
    int8_t _state;
    Board _board;
    vector<Move> _moveLst;
    bool _gameStarted ;


};

#endif  // _API_H_