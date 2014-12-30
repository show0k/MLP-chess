#ifndef _UTILS_H_
#define  _UTILS_H_
#include <string>
#include <stdio.h>

using namespace std;

class BgColors {
public :


    string WHITE  = "\033[37m";
    string CYAN   = "\033[36m";
    string PURPLE = "\033[95m";
    string BLUE   = "\033[94m";
    string GREEN  = "\033[92m";
    string YELLOW = "\033[93m";
    string RED    = "\033[91m";
    string ENDC = "\033[0m" ;

    string UNDERLINE            = "\033[4m";
    string UNDERLINE_WHITE      = "\033[4m\033[37m";
    string UNDERLINE_BOLD_WHITE = "\033[4m\033[1m\033[37m";

    string     BOLD = "\033[1m";
    string     BOLD_CYAN   = "\033[1m\033[36m";
    string     BOLD_PURPLE = "\033[1m\033[95m";
    string     BOLD_YELLOW = "\033[1m\033[93m";
    string     BOLD_RED    = "\033[1m\033[91m";

    string     INVERSE_WHITE  = "\033[7m\033[37m";
    string     INVERSE_PURPLE = "\033[7m\033[95m";
    string     INVERSE_BLUE   = "\033[7m\033[94m";
    string     INVERSE_GREEN  = "\033[7m\033[92m";
    string     INVERSE_YELLOW = "\033[7m\033[93m";
    string     INVERSE_RED    = "\033[7m\033[91m";
    string     INVERSE_GREY  = "\33[100m";
} ;

#endif  // _UTILS_H_