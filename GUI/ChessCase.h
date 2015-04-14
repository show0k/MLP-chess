/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
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
		string sendShow();
		bool isEmpty();
		bool isInVector(std::vector<ChessCase*> v);

		bool operator==(ChessCase const& a);
};

#endif
