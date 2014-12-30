#ifndef CHESS_CASE
#define CHESS_CASE

#include "ClickableElement.h"
//#include "ChessPiece.h"

class ChessCase : public ClickableElement {
	private:
		bool empty;
		char type; //Couleur de la piece qui est dessus
		char coord[2]; //coord[0] = lettre || coord[1] = chiffre
	public:
		ChessCase(char a, char b);// EXEMPLE (A,1)
		ChessCase();
		string toString();
		~ChessCase();
		void pressed();
		void setEmpty(bool c);
		void setType(int t);
		int getType();
		char* getCoord();
		void baseAction();
		

		bool operator==(ChessCase const& a);
};

#endif
