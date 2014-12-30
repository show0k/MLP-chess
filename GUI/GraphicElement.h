#ifndef GRAPHICS
#define GRAPHICS

#define BLANC 101
#define NOIR 102
#define VIDE 104

#define MARGE_H 40
#define MARGE_W 230 
#define SPRITE_SIZE 80
#define WINDOW_W 1100
#define WINDOW_H 720

#include "Point2I.h"
#include "API.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std; 

class GraphicElement/*: public sf::Drawable*/{
	protected:
		//sf::Sprite *imgs;
		sf::Sprite img;
		sf::Texture t;
		Point2I p;
		char nbState;
		char state;
		void *action;
		

	public:
		GraphicElement();
		~GraphicElement();
		GraphicElement(const string s);
		void draw(sf::RenderWindow & window);
		void setSprite(string fileName, int lvl);
		void setSprite(sf::Sprite sp, int lvl);
		sf::Sprite& getSprite(char state);
		void putIntoVector(std::vector<GraphicElement> v);
		void setPosition(Point2I p);
		void setRotation(float angle);
		void setScale(float size);
};

#endif

