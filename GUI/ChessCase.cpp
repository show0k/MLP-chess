#include "ChessCase.h"

ChessCase::ChessCase(char a, char b){
	coord[0] = a;
	coord[1] = b;
	
}
ChessCase::ChessCase(){
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
