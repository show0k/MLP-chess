#include "ClickableElement.h"

ClickableELement::ClickableELement(){

}

void ClickableELement::setStartPoint(Point2I p){
	pointDebut = p;
}

void ClickableELement::setEndPoint(Point2I p){
	pointFin = p;
}

ClickableELement::~ClickableELement(){

}

bool ClickableELement::isInside(sf::Event event){
	if(event.type == sf::Event::MouseButtonPressed ){
		if(checkPosition(event.mouseButton.x, event.mouseButton.y)){
			pressed();
			return true;
		}
	}else if (event.type == sf::Event::MouseButtonReleased ){
		released();
		return true;
	}else if (event.type == sf::Event::MouseWheelMoved ){
		wheeled();
		return true;
	}
	return false;
}

void ClickableELement::released(){
}
void ClickableELement::wheeled(){
}
void ClickableELement::pressed(){
}

Point2I ClickableELement::getEndPoint(){
	return pointFin;
}

Point2I ClickableELement::getStartPoint(){
	return pointDebut;
}

bool ClickableELement::checkPosition(int x, int y){
	if( x>pointDebut.getX() && y>pointDebut.getY() && x<pointFin.getX() && y<pointFin.getY() )
		return true;
	else 
		return false;
}

