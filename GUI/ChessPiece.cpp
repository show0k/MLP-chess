/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "ChessPiece.h"


ChessPiece::ChessPiece(){
	type = 'v';
	alive = false;
	color = VIDE;
	caseActu = new ChessCase(0,0);
}
ChessPiece::ChessPiece(char type){
	this->type = type;
	alive = true;
	color = VIDE;
	caseActu = new ChessCase(0,0);
}

ChessPiece::ChessPiece(char type, int color){
	this->type = type;
	this->color = color;
	alive = true;
	setImage(color);
	caseActu = new ChessCase(0,0);
}

void ChessPiece::setImage(int color){
	string suffixe;
	switch(color){
		case BLANC: suffixe = "blanc-";
			break;
		case NOIR: suffixe = "noir-";
			break;
	}
	
	switch(type){
		case 'k':	//Roi
			setSprite(suffixe+"roi.png", 0);
			break;
		case 'p':	//Pion
			setSprite(suffixe+"pion.png", 0);
			break;
		case 'q':	//Reine
			setSprite(suffixe+"reine.png", 0);
			break;
		case 'n':	//cavalier
			setSprite(suffixe+"chevalier.png", 0);
			break;
		case 'b':	//Fou
			setSprite(suffixe+"fou.png", 0);
			break;
		case 'r':	//Tour
			setSprite(suffixe+"tour.png", 0);
			break;
	}
}

ChessPiece::~ChessPiece(){

}

char ChessPiece::getType(){
	return type;
}

void ChessPiece::setCase(char a, char b){// EXEMPLE (A,1);
	caseActu = new ChessCase(a,b);
	p = Point2I((a%97)*SPRITE_SIZE+MARGE_W, 720 - (b%48 +1)*SPRITE_SIZE+MARGE_H);
	img.setPosition (p.getX(), p.getY());
}

void ChessPiece::setCase(ChessCase *c){// EXEMPLE (A,2);
	caseActu->setEmpty(true);
	caseActu->setType(VIDE);
	caseActu = c;
	c->setEmpty(false);
	c->setType(color);
	p = c->getStartPoint();
	setPosition(p);
}

ChessCase* ChessPiece::getCase() {
	return caseActu; 
}

string ChessPiece::toString(){
	string info ="";
	switch(type){
		case 'k':info += "Roi";
			break;
		case 'p':info += "Pion";
			break;
		case 'q':info += "Reine";
			break;
		case 'n':info += "Cavalier";
			break;
		case 'b':info += "Fou";
			break;
		case 'r':info += "Tour";
			break;
	}
	switch(color){
		case BLANC: info += " blanc";
			break;
		case NOIR: info += " noir";
			break;
	}
	info += " en "+caseActu->toString();
	return info;
}

bool ChessPiece::isAlive(){
	return alive;
}

void ChessPiece::slain(){
	alive = false;
	caseActu = new ChessCase(0,0);
}

void ChessPiece::displayIn(sf::RenderWindow & window){
	if(alive)this->draw(window);
}

bool ChessPiece::notNull(){
	if(type == 'v')
		return false;
	return true;
}

char ChessPiece::getColor(){
	return color;
}
