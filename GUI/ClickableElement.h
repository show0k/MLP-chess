#include "GraphicElement.h"

#ifndef CLICKABLE
#define CLICKABLE

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class ClickableELement{
	private:
		Point2I pointDebut, pointFin;
	
	public:
		~ClickableELement();
		ClickableELement();
		virtual void setStartPoint(Point2I p);
		void setEndPoint(Point2I p);
		Point2I getEndPoint();
		Point2I getStartPoint();
		void pressed();
		void released();
		void wheeled();
		bool isInside(sf::Event event);
		bool checkPosition(int x, int y);
};

#endif
