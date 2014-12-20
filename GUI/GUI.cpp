#include "GUI.h"
#include "ChessPieceSet.h"

void GUI(){
	std::vector<GraphicElement> objGraphiques ;
	
	ChessBoard plateau;
	objGraphiques.push_back(plateau);

    	ChessPieceSet michelBlanc = ChessPieceSet(BLANC);
	ChessPieceSet michelNoir = ChessPieceSet(NOIR);
	
	sf::RenderWindow window(sf::VideoMode(1100, 720), "GUI chess");
	

	int nb1 = objGraphiques.size();
	
	sf::Sprite test;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)){
		
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed )
				plateau.notifyCases(event);
		}
		window.clear();
        	nb1 = objGraphiques.size();
		
		// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
		for(int i=0;i<nb1;i++){
			objGraphiques.at(i).draw(window);
		}
		

		// Dans cette boucle, on affiche l'ensemble des pieces vivantes du joueur blanc
		for(int i=0;i<10;i++){
			michelBlanc.pieces[i]->displayIn(window);
		}

		for(int i=0;i<10;i++){
			michelNoir.pieces[i]->displayIn(window);
		}
		window.display();
	}
}
