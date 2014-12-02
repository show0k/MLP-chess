#include "GraphicElement.h"

GraphicElement::GraphicElement(const String &){
	stateNB = 1;
	state = 1;
	p = new Point2I();
	imgs = malloc(sizeof(sf::Sprite));
}

GraphicElement::GraphicElement(){
	stateNB = 1;
	state = 1;
	p = new Point2I();
	imgs = malloc(sizeof(sf::Sprite));
}

GraphicElement::setSprite(String fileName, int lvl){
	sf::Texture t = new sf::Texture();
	t.loadFromFile(fileName);
	imgs[lvl] = new sf::Sprite(t);
	
}

GraphicElement::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(imgs[state], states);
}

