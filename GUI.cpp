#include <SFML/Graphics.hpp>
#include <Thread.hpp>


class GUI : public sf::Thread {
	private:
		std::List<GraphicElement> objGraphiques;
	public:
		GUI();
}

public GUI::GUI(){
	objGraphiques = new List<GraphicElement>();
	
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for(int i=0;i<;i++){
			
		}
		window.draw(sprite);
		window.draw(text);
		window.display();
	}
}
