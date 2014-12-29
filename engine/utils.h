#ifndef _UTILS_H_
#define  _UTILS_H_
#include <string.h> 
#include <stdio.h> 

using namespace std;

class BgColors
{
    public :
        string HEADER = "\033[95m" ;
        string BLUE = "\033[94m" ;
        string GREEN = "\033[92m" ;
        string YELLOW ="\033[33m" ;
        string WARNING = "\033[93m" ;
        string FAIL = "\033[91m" ;
        string ENDC = "\033[0m" ;
} ;

#endif  // _UTILS_H_