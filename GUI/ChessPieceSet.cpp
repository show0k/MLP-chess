/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "ChessPieceSet.h"

ChessPieceSet::ChessPieceSet(int color){
	this->color = color;
	char offsetPosition;
	switch(color){
		case BLANC:offsetPosition = 2;
			break;
		case NOIR:offsetPosition = 7;
			break;
	}
	for(int i=0;i<8;i++){
		pieces[i] = new ChessPiece('p', color);
		//pieces[i]->setCase(i+97, offsetPosition);
		//cout<<"Creation d'un(e) "<< pieces[i]->toString()<<"\n";
	}
	switch(color){
		case BLANC:offsetPosition = 1;
			break;
		case NOIR:offsetPosition = 8;
			break;
	}
	
	pieces[8] = new ChessPiece('k', color);
	//pieces[8]->setCase(4+97, offsetPosition);
	//cout<<"Creation d'un(e) "<< pieces[8]->toString()<<"\n";
	
	pieces[9] = new ChessPiece('q', color);
	//pieces[9]->setCase(3+97, offsetPosition);
	//cout<<"Creation d'un(e) "<< pieces[9]->toString()<<"\n";
	
	pieces[10] = new ChessPiece('b', color);
	pieces[11] = new ChessPiece('b', color);
	pieces[12] = new ChessPiece('n', color);
	pieces[13] = new ChessPiece('n', color);
	pieces[14] = new ChessPiece('r', color);
	pieces[15] = new ChessPiece('r', color);
}

ChessPieceSet::~ChessPieceSet(){
}

void ChessPieceSet::slainChessPiece(int n){
	pieces[n]->slain();
}

void ChessPieceSet::addPiecesToBoard(ChessBoard &plateau){
	char offsetPosition;
	switch(color){
		case BLANC:offsetPosition = 2;
			break;
		case NOIR:offsetPosition = 7;
			break;
	}
	for(int i=0;i<8;i++){
		pieces[i]->setCase(plateau.caseAt(i,8-offsetPosition));
	}
	switch(color){
		case BLANC:offsetPosition = 1;
			break;
		case NOIR:offsetPosition = 8;
			break;
	}
	pieces[8]->setCase(plateau.caseAt(4-1,8-offsetPosition));
	pieces[9]->setCase(plateau.caseAt(5-1,8-offsetPosition));
	pieces[10]->setCase(plateau.caseAt(3-1,8-offsetPosition));
	pieces[11]->setCase(plateau.caseAt(6-1,8-offsetPosition));
	pieces[12]->setCase(plateau.caseAt(2-1,8-offsetPosition));
	pieces[13]->setCase(plateau.caseAt(7-1,8-offsetPosition));
	pieces[14]->setCase(plateau.caseAt(1-1,8-offsetPosition));
	pieces[15]->setCase(plateau.caseAt(8-1,8-offsetPosition));
}

ChessPiece* ChessPieceSet::getPieceAt(ChessCase c){
	for(int i = 0;i<16; i++){
		if(*pieces[i]->getCase() == c)
			return pieces[i];
	}
}

ChessPiece* ChessPieceSet::TESTgetRandomPiece(){
	return pieces[rand()%16];
}
