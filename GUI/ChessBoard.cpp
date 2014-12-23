#include "ChessBoard.h"

ChessBoard::ChessBoard(){
	setSprite("plateau.png", 0);
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			cases[i][j] =  new ChessCase(i,j);
		}
	}
}

ChessBoard::~ChessBoard(){
}

ChessCase ChessBoard::notifyCases(sf::Event event){
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			if(cases[i][j]->isInside(event)){
				//cases[i][j]->pressed();
				return *cases[i][j];
			}
		}
	}
	return ChessCase(0,0);
}

ChessCase& ChessBoard::caseAt(int i, int j){
	return *cases[i][j];
}
