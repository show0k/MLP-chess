#include "move.h"


ostream &operator<<(ostream &out, const Move &m) {

    if (m._pieceCaptured == _)
        out << '('<< pieceToStr(m._piece) << ':'<< m._squareFrom << ';' << m._squareTo <<')' ;
    else {
        out << '('<< m._squareFrom << ';' << m._squareTo <<')' ;
    }
    return out ;
}


string pieceToStr(uint8_t piece) {

    switch (piece) {
        case  7:
            return ".";
            break;

        case  1:
            return "P";
            break;

        case 2:
            return "N";
            break;

        case 3:
            return "B";
            break;

        case 4:
            return "R";
            break;

        case 5:
            return "Q";
            break;

        case 6:
            return "K";
            break;



        case 8:
            return "p";
            break;

        case 9:
            return "n";
            break;

        case 10:
            return "b";
            break;

        case 11:
            return "r";
            break;

        case 12:
            return "q";
            break;

        case 13:
            return "k";
            break;

        case 99:
            return "\u2422";
            break;

        default :
            return pieceToStr(X) ;

    }

}

string pieceToStr(uint8_t piece, bool color) {
    if (!color)
        return pieceToStr(piece) ;
    BgColors bg = BgColors();

    switch (piece) {
        case  7:
            return bg.GREEN + "." + bg.ENDC;
            break;

        case  1:
            return bg.YELLOW + "P" + bg.ENDC;
            break;

        case 2:
            return bg.YELLOW + "N" + bg.ENDC;
            break;

        case 3:
            return bg.YELLOW + "B" + bg.ENDC;
            break;

        case 4:
            return bg.YELLOW + "R" + bg.ENDC;
            break;

        case 5:
            return bg.YELLOW + "Q" + bg.ENDC;
            break;

        case 6:
            return bg.YELLOW + "K" + bg.ENDC;
            break;



        case 8:
            return bg.BLUE + "p" + bg.ENDC;
            break;

        case 9:
            return bg.BLUE + "n" + bg.ENDC;
            break;

        case 10:
            return bg.BLUE + "b" + bg.ENDC;
            break;

        case 11:
            return bg.BLUE + "r" + bg.ENDC;
            break;

        case 12:
            return bg.BLUE + "q" + bg.ENDC;
            break;

        case 13:
            return bg.BLUE + "k" + bg.ENDC;
            break;

        case 99:
            return "\u2422";
            break;

        default :
            return pieceToStr(X) ;

    }



}
