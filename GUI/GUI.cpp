#include "GUI.h"

sf::RenderWindow window(sf::VideoMode(1100, 720), "GUI chess");
std::vector<GraphicElement*> interface ;

void GUI(){
	srand (time(NULL));
    	gameInitialisation();

	int  nb2 = interface.size();
	
	sf::Sprite test;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)){
		
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed ){
				/*caseSelect = plateau.notifyCases(event);
				switch(caseSelect->getType()){
					case BLANC:	pieceSelect = michelBlanc.getPieceAt(*caseSelect);
							//pieceSelect = michelNoir.TESTgetRandomPiece();
							cout<<pieceSelect->toString()<<"\n";
							break;
					case NOIR:	pieceSelect = michelNoir.getPieceAt(*caseSelect);
							cout<<pieceSelect->toString()<<"\n";
							break;
					case VIDE: 	//cout<<caseSelect.toString()<<" est vide\n";
							break;
				}
				int x = (caseSelect->getCoord()[0]-97) *SPRITE_SIZE +MARGE_W+ SPRITE_SIZE/2;
				int y = (8-caseSelect->getCoord()[1]) *SPRITE_SIZE+MARGE_H + SPRITE_SIZE/2;*/
			}
		}
		window.clear();
        	displayGameIn(window);

		nb2 = interface.size();
		// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
		for(int i=0;i<nb2;i++){
			interface.at(i)->draw(window);
		}
		window.display();
	}
}

bool stringContains(string s1, string s2){	// s1 contains s2 ??
	int l1 = s1.size(), l2 = s2.size();
	int cnt = 0;
	for(int i=0;i< l1; i++){
		if(s1.at(i) == s2.at(cnt))
			cnt++;
		else
			cnt = 0;
		if(cnt == l2)
			return true;
	}		
	return false;
}

void stringSplit(string s, char c, std::vector<string> &splited){
	int l = s.size();
	string stringActu = "";
	for(int i=0;i<l;i++){
		if(s.at(i) != c)
			stringActu.append(1u, s.at(i));
		else{
			splited.push_back(string(stringActu));
			stringActu = "";
		}
	}
	splited.push_back(string(stringActu));
}



char convertCharToArrayIndex(char lettre){
	if(lettre >= 97){
		return lettre%97 +1;		
	}
	else{
		return lettre%63 - 1;
	}
}

