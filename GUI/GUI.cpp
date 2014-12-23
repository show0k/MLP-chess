#include "GUI.h"
#include "ChessPieceSet.h"

void GUI(){
	std::vector<GraphicElement> objGraphiques ;
	
	ChessBoard plateau;
	objGraphiques.push_back(plateau);
	ChessCase caseSelect;
	ChessPiece pieceSelect;

    	ChessPieceSet michelBlanc = ChessPieceSet(BLANC);
	ChessPieceSet michelNoir = ChessPieceSet(NOIR);
	michelBlanc.addPiecesToBoard(plateau);
	michelNoir.addPiecesToBoard(plateau);
	
	sf::RenderWindow window(sf::VideoMode(1100, 720), "GUI chess");
	string s;

	int nb1 = objGraphiques.size();
	
	sf::Sprite test;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)){
		
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed ){
				caseSelect = plateau.notifyCases(event);
				switch(caseSelect.getType()){
					case BLANC:	pieceSelect = michelBlanc.getPieceAt(caseSelect);
							cout<<pieceSelect.toString()<<"\n";
							break;
					case NOIR:	pieceSelect = michelNoir.getPieceAt(caseSelect);
							cout<<pieceSelect.toString()<<"\n";
							break;
					case VIDE: 	//cout<<caseSelect.toString()<<" est vide\n";
							break;
				}
			}
		}
		window.clear();
        	nb1 = objGraphiques.size();
		
		// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
		for(int i=0;i<nb1;i++){
			objGraphiques.at(i).draw(window);
		}
		

		// Dans cette boucle, on affiche l'ensemble des pieces vivantes du joueur blanc
		for(int i=0;i<16;i++){
			michelBlanc.pieces[i]->displayIn(window);
		}

		for(int i=0;i<16;i++){
			michelNoir.pieces[i]->displayIn(window);
		}
		window.display();
		cin >> s;
		cout << "test:"+s;
	}
}
