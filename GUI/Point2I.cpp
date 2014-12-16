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
	return "Pas encore implementé!!";
}

