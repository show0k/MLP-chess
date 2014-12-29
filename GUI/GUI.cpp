#include "GUI.h"
#include "ChessPieceSet.h"

ChessPieceSet michelBlanc = ChessPieceSet(BLANC);
ChessPieceSet michelNoir = ChessPieceSet(NOIR);
ChessBoard plateau;
sf::RenderWindow window(sf::VideoMode(1100, 720), "GUI chess");

void GUI(){
	srand (time(NULL));
	std::vector<GraphicElement*> objGraphiques ;

	ChessCase caseSelect;
	ChessPiece pieceSelect;
    	
	michelBlanc.addPiecesToBoard(plateau);
	michelNoir.addPiecesToBoard(plateau);

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
				int x = (caseSelect.getCoord()[0]-97) *SPRITE_SIZE +MARGE_W+ SPRITE_SIZE/2;
				int y = (8-caseSelect.getCoord()[1]) *SPRITE_SIZE+MARGE_H + SPRITE_SIZE/2;
				addBloodSpot(objGraphiques, x, y);
				cout << "ajout de sang en ("<<x<<","<<y<<")\n";
			}
		}
		window.clear();
		plateau.draw(window);

        	nb1 = objGraphiques.size();
		// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
		for(int i=0;i<nb1;i++){
			objGraphiques.at(i)->draw(window);
		}
		
		// Dans cette boucle, on affiche l'ensemble des pieces vivantes du joueur blanc
		for(int i=0;i<16;i++){
			michelBlanc.pieces[i]->displayIn(window);
		}

		for(int i=0;i<16;i++){
			michelNoir.pieces[i]->displayIn(window);
		}
		window.display();

		if(!(michelBlanc.pieces[0]->getCase() == ChessCase(0,6)))
			cout << "Le pion a bougé:"<<michelBlanc.pieces[0]->getCase().toString()<<"\n";
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

void parseAction(string action){	// move A3 B9
	ChessCase caseActu;
	ChessPiece pieceActu;
	if(stringContains(action, "move")){
		string piece = action.substr(5,2);
		string destination = action.substr(8,2);
		
		char lettre = convertCharToArrayIndex(piece.at(0)), chiffre = 8- (piece.at(1)-40);
		
		caseActu = plateau.caseAt(lettre, chiffre);
		switch(caseActu.getType()){
			case BLANC:	pieceActu = michelBlanc.getPieceAt(caseActu);
					cout<<pieceActu.toString();
					break;
			case NOIR:	pieceActu = michelNoir.getPieceAt(caseActu);
					cout<<pieceActu.toString();
					break;
			case VIDE: 	//cout<<caseSelect.toString()<<" est vide\n";
					break;
		}

		lettre = convertCharToArrayIndex(destination.at(0));
		chiffre = 8- (destination.at(1)-40);
		
		caseActu = plateau.caseAt(lettre, chiffre);
		if(pieceActu.notNull()){
			pieceActu.setCase(caseActu);
			cout << "va en "<< caseActu.toString()<<"\n";
			if(!(pieceActu.getCase()==caseActu))
				cout<<"Ca na pas marché\n";
		}
		else{
			cout<<"Aucune pièce selectionnée\n";
		}
	}
	else{
		cout<<"Commande non reconnue\n";
	}
}

void addBloodSpot(std::vector<GraphicElement*> &vect, int x, int y){
	vect.push_back(new GraphicElement("sang.png"));
	vect[vect.size()-1]->setRotation(rand()%360);
	vect[vect.size()-1]->setScale(1+(rand()%800)/1000.);
	vect[vect.size()-1]->setPosition(Point2I(x-20+rand()%40,y-20+rand()%40));
}

char convertCharToArrayIndex(char lettre){
	if(lettre >= 97){
		return lettre%97 - 1;		
	}
	else{
		return lettre%63 - 1;
	}
}
