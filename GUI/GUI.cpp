#include "GUI.h"
#include "ChessPieceSet.h"

void GUI(){
	std::vector<GraphicElement> objGraphiques ;
	
	ChessBoard plateau;
	objGraphiques.push_back(plateau);

    	ChessPieceSet michelBlanc = ChessPieceSet(BLANC);
	
	ChessPiece *pion[3];
	pion[0] = new ChessPiece('p', BLANC);
	pion[0]->setCase('a', 2);
	//objGraphiques.push_back(pion[0]);
	pion[1] = new ChessPiece('p', BLANC);
	pion[1]->setCase('b', 2);
	//objGraphiques.push_back(pion[1]);
	pion[2] = new ChessPiece('p', BLANC);
	pion[2]->setCase('c', 2);
	objGraphiques.push_back(pion[0]);

	
	sf::RenderWindow window(sf::VideoMode(720, 720), "GUI chess");


	int nb1 = objGraphiques.size();
	int nb2 = michelBlanc.activePieces.size();
	int nb3 = objGraphiques.size();
	//printf("%d objets graphiques a afficher\n", nb);
	
	sf::Sprite test;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)){
		
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
        	nb1 = objGraphiques.size();

		// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
		for(int i=0;i<nb1;i++){
			window.draw(objGraphiques.at(i).getSprite(0));
		}

		nb2 = michelBlanc.activePieces.size();
		// Dans cette boucle, on affiche l'ensemble des pieces vivantes du joueur blanc
		for(int i=0;i<nb2;i++){
			test = michelBlanc.activePieces.at(i).getSprite(0);
			window.draw(test);
		}
		window.display();
	}
}
