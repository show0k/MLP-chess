#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <string>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdint.h>

using namespace std;
// Définit un entier de 0 à 119 qui code l'emplacement sur l'echequier

// Chess représentation
// 110 111 112 113 114 115 116 117 118 119
// 100 101 102 103 104 105 106 107 108 109
//  90  A8  92  93  94  95  96  97  H8  99
//  80  A7  82  83  84  85  86  87  88  89
//  70  A6  72  73  74  75  76  77  78  79
//  60  A5  62  63  64  65  66  67  68  69
//  50  A4  52  53  54  55  56  57  58  59
//  40  A3  42  43  44  45  46  47  48  49
//  30  A2  32  33  34  35  36  37  38  39
//  20  A1  B1  C1  D1  E1  F1  G1  H1  29
//  10  11  12  13  14  15  16  17  18  19
//   0   1   2   3   4   5   6   7   8   9


typedef enum {

    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
} ESquare ;



class Square {
public:
    // Constructeurs
    Square(int aSquare = 0) : _square(aSquare) {};
    Square(string aSquare) {
        fromString(aSquare);
    };

    //Conversion implicite vers int
    operator int() {
        return _square;
    }


    //display
    friend std::ostream &operator <<(std::ostream &out, const Square &s) {
        char c = (s._square % 10) + 'a' - 1;
        char r = (s._square / 10) + '1' - 2;
        return out << c << r;
    }

    operator string() {
        ostringstream os;
        os << _square ;
        return os.str();
    }
    // Square operator + {A const &first, A const &second)
    //     return _square;
    // }


    // methode
    bool fromString(string sq) {
        sq[0] = tolower(sq[0]);
        int col = sq[0] - 'a';
        int row = sq[1] - '1';

        _square = row * 10 + col + 21;
        return (col >= 8 || row >= 8);
    };


private:
    uint8_t  _square; // 0 - 119.
};



#endif // _SQUARE_H_