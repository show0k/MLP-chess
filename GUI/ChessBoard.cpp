/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
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

ChessCase* ChessBoard::notifyCases(sf::Event event){
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			if(cases[i][j]->isInside(event)){
				//cases[i][j]->pressed();
				return cases[i][j];
			}
		}
	}
	return cases[0][0];
}

ChessCase* ChessBoard::caseAt(int i, int j){
	return cases[i][j];
}
