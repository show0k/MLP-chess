#include "ChessBoard.h"

ChessBoard::ChessBoard(){
	setSprite("plateau.png", 0);
	//putIntoVector(parent);
	for(int i = 0;i<64;i++){
		//cases[i] =  new ChessCase(i,i);
	}
}
