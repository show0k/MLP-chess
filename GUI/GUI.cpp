#include "GUI.h"

void GUI(){
	std::vector<GraphicElement> objGraphiques ;
	
	ChessBoard plateau = new ChessBoard();
	objGraphiques.push_back(plateau);

	
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)){
		
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		/*for(int i=0;i<;i++){
			
		}
		window.draw(sprite);
		window.draw(text);*/
		window.display();
	}
}
