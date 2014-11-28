#include <SFML/Graphics.hpp>

class GraphicElement: public sf::Drawable{
	private:
		sf::Sprite imgs[];
		Point pointDebut, pointFin;
		char stateNb;
		char state;
	public:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
}

virtual void GraphicElement::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(imgs[state], states);
}

