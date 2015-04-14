/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "ChessCase.h"
//	'->#include "GraphicElement.h"

#ifndef CHESSBOARD
#define CHESSBOARD

class ChessBoard: public GraphicElement	{
	private:
		ChessCase *cases[8][8];
	
	public:
		ChessBoard();
		~ChessBoard();
		ChessCase* notifyCases(sf::Event event);
		ChessCase* caseAt(int i, int j);
};

#endif
