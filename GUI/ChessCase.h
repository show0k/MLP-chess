#include "ClickableElement.h"

#ifndef CHESS_CASE
#define CHESS_CASE
class ChessCase : public ClickableELement {
	private:
		bool empty;
		char type;
		char coord[2]; //coord[0] = lettre || coord[1] = chiffre
	public:
		ChessCase(char a, char b);// EXEMPLE (A,1)
		ChessCase();
		string toString();
		~ChessCase();
		void pressed();
		void setEmpty(bool c);
};

#endif
