#include "GraphicElement.h"

GraphicElement::GraphicElement(const string &){
	nbState = 1;
	state = 0;
	//imgs = (sf::Sprite*)malloc(sizeof(sf::Sprite));
}

GraphicElement::GraphicElement(){
	nbState = 1;
	state = 0;
	//imgs = (sf::Sprite*)malloc(sizeof(sf::Sprite));
}

void GraphicElement::setSprite(string fileName, int lvl){
	t.loadFromFile(fileName);
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
