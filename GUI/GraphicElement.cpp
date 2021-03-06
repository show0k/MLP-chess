/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "GraphicElement.h"

GraphicElement::GraphicElement(const string s){
	nbState = 1;
	state = 0;
	setSprite(s, 0);
}

GraphicElement::GraphicElement(){
	nbState = 1;
	state = 0;
	//imgs = (sf::Sprite*)malloc(sizeof(sf::Sprite));
}

void GraphicElement::setSprite(string fileName, int lvl){
	t.loadFromFile("ressources/"+fileName);

	
	//loadFromMemory (const void *data, std::size_t size, const IntRect &area=IntRect());
	img = sf::Sprite(t);
}

void GraphicElement::setSprite(sf::Sprite sp, int lvl){
	//imgs[lvl] = sp;
	img = sp;
}

void GraphicElement::draw(sf::RenderWindow & window){
	window.draw(img);
}

GraphicElement::~GraphicElement(){
    /*free(imgs);
	free(p);*/
}

sf::Sprite& GraphicElement::getSprite(char state){
	//return imgs[state];
    return img;
}

void GraphicElement::putIntoVector(std::vector<GraphicElement> v){
    //v.push_back(this);
}

void GraphicElement::setPosition(Point2I p){
	img.setPosition(p.getX(), p.getY());
}

void GraphicElement::setRotation(float angle){
	img.setOrigin(SPRITE_SIZE/2, SPRITE_SIZE/2);
	img.setRotation(angle);
}

void GraphicElement::setScale(float size){
	img.setOrigin(SPRITE_SIZE/2, SPRITE_SIZE/2);
	img.setScale(size, size);
}

Point2I GraphicElement::getPosition(){
	return p;
}

void GraphicElement::checkPosition(){
	if((p.getX() != img.getPosition().x) && (p.getY() != img.getPosition().y))
		img.setPosition(p.getX(), p.getY());
}	
