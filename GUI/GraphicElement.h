#ifndef GRAPHICS
#define GRAPHICS

#define BLANC 100
#define NOIR 101

#define MARGE_H 40
#define MARGE_W 230 
#define SPRITE_SIZE 80

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
		void draw(sf::RenderWindow & window);
		void setSprite(string fileName, int lvl);
		void setSprite(sf::Sprite sp, int lvl);
		sf::Sprite& getSprite(char state);
		void putIntoVector(std::vector<GraphicElement> v);
};

#endif

