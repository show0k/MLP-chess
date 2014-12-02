/*#ifndef _GUI
#define _GUI 1*/


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Point2I.h"


//#endif


class GraphicElement: public sf::Drawable{
	private:
		sf::Sprite *imgs;
		Point2I p;
		char stateNb;
		char state;
	public:
		GraphicElement();
		~GraphicElement();
		void draw(sf::RenderTarget& target, sf::RenderStates states);
};



