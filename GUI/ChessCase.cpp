#include "ChessCase.h"

ChessCase::ChessCase(char a, char b){
	coord[0] = a+97;
	coord[1] = 8-b;
	empty  = true;
	type = VIDE;
	setStartPoint(Point2I(a*SPRITE_SIZE + MARGE_W,b*SPRITE_SIZE + MARGE_H));
	setEndPoint(Point2I((a+1)*SPRITE_SIZE + MARGE_W,(b+1)*SPRITE_SIZE + MARGE_H));
}
ChessCase::ChessCase(){
	empty  = true;
	type = VIDE;
	coord[0] = 0;
	coord[1] = 0;
}

char* ChessCase::getCoord(){
	return coord;
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
	if(empty)
		cout << this->toString() << " est vide\n";
	else
		cout << this->toString() << " n'est pas vide\n";
}

void ChessCase::setEmpty(bool c){
	empty = c;
}

bool ChessCase::isEmpty(){
	return empty;
}

bool ChessCase::operator==(ChessCase const& a){
	if((a.coord[0] == this->coord[0]) && (a.coord[1] == this->coord[1]))
		return true;
	else
		return false;
}

void ChessCase::setType(int t){
	type = t;
}

int ChessCase::getType(){
	return type;
}

void ChessCase::baseAction(){
	sendShow();
}

bool ChessCase::isInVector(std::vector<ChessCase*> v){
	int l = v.size();
	for(int i = 0;i<l;i++){
		if(v[i]==this)
			return true;
	}
	return false;
}
string ChessCase::sendShow(){
	string s = "show ";
	s = s.append(1u, coord[0]);
	s = s.append(1u, coord[1]+48);

	sendCommand(s);

	return s;
}
