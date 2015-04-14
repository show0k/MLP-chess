/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
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
