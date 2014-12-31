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
	t.loadFromFile(fileName);

	
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

