/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "Point2I.h"

Point2I::Point2I(int a, int b){
	x = a;
	y = b;
}

Point2I::Point2I(){
	x = 0;
	y = 0;
}

int Point2I::getX(){
	return x;
}

int Point2I::getY(){
	return y;
}

void Point2I::setX(int a){
	x = a;
}
void Point2I::setY(int b){
	x = b;
}

Point2I::~Point2I(){
	/*free(x);
	free(y);*/
}

string Point2I::toString(){
	stringstream ss;
	ss << "("<<x<<","<<y<<")";
	return	ss.str();
}

string intToString(int x){
	int i = 1;
	string s ="";
	while((x%(10*i))>0){
		
		char c = x%(10*i) + 40;
		s = s.append(1u,c);
		i++;
		
	}
	return s;
}

bool Point2I::operator==(Point2I const& p){
	if(x == p.x && y == p.y)
		return true;
	else
		return false;
}
