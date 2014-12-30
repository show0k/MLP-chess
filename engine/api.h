#ifndef _API_H_
#define _API_H_


#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "board.h"

using namespace std;

const int8_t TERMINAL = 0;
const int8_t GUI = 1;

void displayMoveLst(vector<Move> &moves);
void help(void);

class API {
public :
    API(int8_t state = GUI): _state(state), _gameStarted(0) {_moveLst.reserve(500) ;}

    void loop(int argc, char *argv[]);
    void invalid(string cmd) ;

private :
    int8_t _state;
    Board _board;
    vector<Move> _moveLst;
    bool _gameStarted ;


};

#endif  // _API_H_