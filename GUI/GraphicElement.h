#ifndef GRAPHICS
#define GRAPHICS
#define BLANC 100
#define NOIR 101

#include "Point2I.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std; 

class GraphicElement/*: public sf::Drawable*/{
	protected:
		//sf::Sprite *imgs;
		sf::Sprite img;
		sf::Texture t;
		Point2I p;
		char nbState;
		char state;
		

	public:
		GraphicElement();
		~GraphicElement();
		GraphicElement(const string &);
		/*void draw(sf::RenderTarget& target, sf::RenderStates states) const;*/
		void setSprite(string fileName, int lvl);
		void setSprite(sf::Sprite sp, int lvl);
		sf::Sprite& getSprite(char state);
		void putIntoVector(std::vector<GraphicElement> v);
};

#endif

