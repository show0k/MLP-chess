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

