/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "GraphicElement.h"

#ifndef CLICKABLE
#define CLICKABLE

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class ClickableElement{
	private:
		Point2I pointDebut, pointFin;
		void (*action)();
		bool useBaseAction;
	
	public:
		~ClickableElement();
		ClickableElement();
		void setStartPoint(Point2I p);
		void setEndPoint(Point2I p);
		Point2I getEndPoint();
		Point2I getStartPoint();
		void pressed();
		void released();
		void wheeled();
		bool isInside(sf::Event event);
		bool checkPosition(int x, int y);
		ClickableElement(Point2I d, Point2I f);
		ClickableElement(Point2I d, Point2I f, void (*fonction)());
		void setBaseAction();
		virtual void baseAction();
		void resetAction();
};

#endif
