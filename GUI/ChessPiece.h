#ifndef CHESS_PIECE
#define CHESS_PIECE

#include "ChessCase.h"
//  '-->#include "GraphicElement.h"

class ChessPiece : public GraphicElement{
	private:
		char type;
		int color;
		ChessCase *caseActu;
		bool alive;
	public:
		ChessPiece(char type);
		ChessPiece(char type, int color);
		ChessPiece();
		~ChessPiece();
		char getType();
		string toString();
		void setImage(int color);
		void setCase(char a, char b);
		ChessCase* getCase();
		bool isAlive();
		void slain();
		void displayIn(sf::RenderWindow & window);
		void setCase(ChessCase *c);
		bool notNull();
		char getColor();
		void showMoves();
};

#endif
