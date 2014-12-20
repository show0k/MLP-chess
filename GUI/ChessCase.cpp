#include "ChessCase.h"

ChessCase::ChessCase(char a, char b){
	coord[0] = a+97;
	coord[1] = 8-b;
	empty  = false;
	setStartPoint(Point2I(a*SPRITE_SIZE + MARGE_W,b*SPRITE_SIZE + MARGE_H));
	setEndPoint(Point2I((a+1)*SPRITE_SIZE + MARGE_W,(b+1)*SPRITE_SIZE + MARGE_H));
}
ChessCase::ChessCase(){
	empty  = false;
	coord[0] = 0;
	coord[1] = 0;
}

string ChessCase::toString(){
	string info = "(";
	info = info.append(1u,coord[0]) + ",";
	info = info.append(1u,coord[1]+48) +")";
	return info;
}

ChessCase::~ChessCase(){
}

void ChessCase::pressed(){
	//cout << this->toString() << " est cliqué\n";
	if(!empty)
		cout << this->toString() << " est vide\n";
	else
		cout << this->toString() << " est vide\n";
}

void ChessCase::setEmpty(bool c){
	empty = c;
}

