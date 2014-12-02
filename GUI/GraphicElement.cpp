#include <SFML/Graphics.hpp>

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
}

public GraphicElement::GraphicElement(const String &){
	stateNB = 1;
	state = 1;
	p = new Point2I();
	imgs = malloc(sizeof(sf::Sprite));
}

public GraphicElement::GraphicElement(){
	stateNB = 1;
	state = 1;
	p = new Point2I();
	imgs = malloc(sizeof(sf::Sprite));
}

public void GraphicElement::setSprite(String fileName, int lvl){
	sf::Texture t = new sf::Texture();
	t.loadFromFile(fileName);
	imgs[lvl] = new sf::Sprite(t);
	
}

public void GraphicElement::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(imgs[state], states);
}

