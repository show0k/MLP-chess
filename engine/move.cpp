#include "move.h"


ostream &operator<<(ostream &out, const Move &m) {

    if (m._piecePromoted == _)
        out  << m._squareFrom << m._squareTo ;
    else {
        out  << m._squareFrom << m._squareTo << m._piecePromoted;
    }
    return out ;
}

void Move::fromString(string &move) {
    _squareFrom.fromString(move.substr(0, 2)) ;
    _squareTo.fromString(move.substr(2, 2)) ;
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
            return "X";
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
            return bg.INVERSE_WHITE + "P" + bg.ENDC;
            break;

        case 2:
            return bg.INVERSE_WHITE + "N" + bg.ENDC;
            break;

        case 3:
            return bg.INVERSE_WHITE + "B" + bg.ENDC;
            break;

        case 4:
            return bg.INVERSE_WHITE + "R" + bg.ENDC;
            break;

        case 5:
            return bg.INVERSE_WHITE + "Q" + bg.ENDC;
            break;

        case 6:
            return bg.INVERSE_WHITE + "K" + bg.ENDC;
            break;



        case 8:
            return bg.INVERSE_GREY + "p" + bg.ENDC;
            break;

        case 9:
            return bg.INVERSE_GREY + "n" + bg.ENDC;
            break;

        case 10:
            return bg.INVERSE_GREY + "b" + bg.ENDC;
            break;

        case 11:
            return bg.INVERSE_GREY + "r" + bg.ENDC;
            break;

        case 12:
            return bg.INVERSE_GREY + "q" + bg.ENDC;
            break;

        case 13:
            return bg.INVERSE_GREY + "k" + bg.ENDC;
            break;

        case 99:
            return "X";
            break;

        default :
            return pieceToStr(X) ;

    }
}

uint8_t pieceFromStr(const char pieceStr) {
    switch (pieceStr) {
        case '_' : return _; break;   // Empty
        case 'P' : return P; break;  // White Pawn
        case 'N' : return N; break;  // White Knight
        case 'B' : return B; break;  // White Bishop
        case 'R' : return R; break;  // White Rook
        case 'Q' : return Q; break;  // White Queen
        case 'K' : return K; break;  // White King
        case 'p' : return p; break;  // Black Pawn
        case 'n' : return n; break;  // Black Knight
        case 'b' : return b; break;   // Black Bishop
        case 'r' : return r; break;  // Black Rook
        case 'q' : return q; break;  // Black Queen
        case 'k' : return k; break;  // Black King
        case 'X' : return X; break; // INVALID
    }
    return X ;
}
