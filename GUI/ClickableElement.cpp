#include "ClickableElement.h"

ClickableElement::ClickableElement(){
	action = NULL;
	useBaseAction = false;
}

void ClickableElement::setStartPoint(Point2I p){
	pointDebut = p;
}

void ClickableElement::setEndPoint(Point2I p){
	pointFin = p;
}

ClickableElement::ClickableElement(Point2I d, Point2I f){
	pointFin = f;
	pointDebut = d;
	action = NULL;
	useBaseAction = false;
}

ClickableElement::ClickableElement(Point2I d, Point2I f, void (*fonction)()){
	pointFin = f;
	pointDebut = d;
	action = fonction;
	useBaseAction = false;
}

ClickableElement::~ClickableElement(){

}

bool ClickableElement::isInside(sf::Event event){
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

void ClickableElement::released(){
}
void ClickableElement::wheeled(){
}
void ClickableElement::pressed(){
	if(useBaseAction){
		baseAction();
	}else{
		if(action != NULL)
			(*action)();
		else
			cout<<"Pas d'action asscociée\n";
	}
}

Point2I ClickableElement::getEndPoint(){
	return pointFin;
}

Point2I ClickableElement::getStartPoint(){
	return pointDebut;
}

bool ClickableElement::checkPosition(int x, int y){
	if( x>pointDebut.getX() && y>pointDebut.getY() && x<pointFin.getX() && y<pointFin.getY() )
		return true;
	else 
		return false;
}

void ClickableElement::resetAction(){
	action = NULL;
}

void ClickableElement::setBaseAction(){
	useBaseAction = true;
}

void ClickableElement::baseAction(){
}

