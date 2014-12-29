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
