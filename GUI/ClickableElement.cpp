#include "ClickableElement.h"

ClickableELement::ClickableELement(){

}

void ClickableELement::setStartPoint(Point2I p){
	pointDebut.setX(p.getX());
	pointDebut.setY(p.getY());
}

void ClickableELement::setEndPoint(Point2I p){
	pointFin.setX(p.getX());
	pointFin.setY(p.getY());
}


