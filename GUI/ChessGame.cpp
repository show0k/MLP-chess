#include "GUI.h"
#include "ChessPieceSet.h"

ChessCase *caseSelect;
ChessPiece *pieceSelect;
std::vector<GraphicElement*> objGraphiques ;
ChessPieceSet michelBlanc = ChessPieceSet(BLANC);
ChessPieceSet michelNoir = ChessPieceSet(NOIR);
ChessBoard plateau;
extern std::vector<GraphicElement*> interface ;
void gameInitialisation(){
	michelBlanc = ChessPieceSet(BLANC);
	michelNoir = ChessPieceSet(NOIR);
	michelBlanc.addPiecesToBoard(plateau);
	michelNoir.addPiecesToBoard(plateau);
}

void displayGameIn(sf::RenderWindow &window){
	plateau.draw(window);
	int nb1 = objGraphiques.size();
	// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
	for(int i=0;i<nb1;i++)
		objGraphiques.at(i)->draw(window);
	
	// Dans cette boucle, on affiche l'ensemble des pieces vivantes du joueur blanc
	for(int i=0;i<16;i++)
		michelBlanc.pieces[i]->displayIn(window);

	for(int i=0;i<16;i++)
		michelNoir.pieces[i]->displayIn(window);
}

void parseAction(string action){	// move A3 B9, show B1
	ChessCase *caseActu = NULL;
	ChessPiece *pieceActu = NULL;
	if(stringContains(action, "move")){
		string piece = action.substr(5,2);
		string destination = action.substr(8,2);
		
		char lettre = convertCharToArrayIndex(piece.at(0)), chiffre = 8- (piece.at(1)-40);
		caseActu = plateau.caseAt(lettre, chiffre);
		
		switch(caseActu->getType()){
			case BLANC:	pieceSelect = michelBlanc.getPieceAt(*caseActu);
					cout<<pieceSelect->toString();
					break;
			case NOIR:	pieceSelect = michelNoir.getPieceAt(*caseActu);
					cout<<pieceSelect->toString();
					break;
			case VIDE: 	//cout<<caseSelect.toString()<<" est vide\n";
					break;
		}

		lettre = convertCharToArrayIndex(destination.at(0));
		chiffre = 8- (destination.at(1)-40);
		
		
		caseActu = plateau.caseAt(lettre, chiffre);
		string s = "";
		switch(caseActu->getType()){
			case BLANC:	pieceActu = michelBlanc.getPieceAt(*caseActu);
					s = pieceActu->toString();
					break;
			case NOIR:	pieceActu = michelNoir.getPieceAt(*caseActu);
					s = pieceActu->toString();
					break;
			case VIDE: 	//cout<<caseSelect.toString()<<" est vide\n";
					break;
		}
		
		if(pieceSelect != NULL){
			pieceSelect->setCase(caseActu);
			cout << " va en "<< pieceSelect->toString();
			if(pieceActu != NULL){
				cout<<"et mange "<<s<<" \n";
				int x = (caseActu->getCoord()[0]-97) *SPRITE_SIZE +MARGE_W+ SPRITE_SIZE/2;
				int y = (8-caseActu->getCoord()[1]) *SPRITE_SIZE+MARGE_H + SPRITE_SIZE/2;
				addBloodSpot(objGraphiques, x, y);
				addDeadPony(objGraphiques, pieceActu->getColor());
				pieceActu->slain();
			}
			if(!(pieceSelect->getCase()==caseActu))
				cout<<"Ca na pas marché\n";
		}
		else{
			cout<<"Aucune pièce selectionnée\n";
		}
	}
	else if(stringContains(action, "goto")){ // INCOMPLET CAR INUTILE: UTILISER MOVE
		char lettre = convertCharToArrayIndex(action.at(5)), chiffre = 8- (action.at(6)-40);
		caseActu = plateau.caseAt(lettre, chiffre);
		if(pieceSelect->notNull()){
			pieceSelect->setCase(caseActu);
			cout << "va en "<< caseActu->toString()<<"\n";
			if(!(pieceSelect->getCase()==caseActu))
				cout<<"Ca na pas marché\n";
		}
		else{
			cout<<"Aucune pièce selectionnée\n";
		}
	}else if(stringContains(action, "victoire")){
		std::vector<string> splited;
		stringSplit(action, ' ',splited);
		if(splited[1] == "blanc"){
			interface.push_back(new GraphicElement("victoire-blanc.png"));
			sf::Vector2u v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			interface[interface.size()-1]->setPosition(Point2I((int)(1100/2 - v.x/2 ),(int)(720/2 - v.y/2)));
		}
		else if (splited[1] == "noir"){
			interface.push_back(new GraphicElement("victoire-noir.png"));
			sf::Vector2u v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			interface[interface.size()-1]->setPosition(Point2I((int)(1100/2 - v.x/2 ),(int)(720/2 - v.y/2)));
		}
		else
			cout<<"De qui??\n";
		
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

void addDeadPony(std::vector<GraphicElement*> &vect, char color){
	switch(color){
		case NOIR:vect.push_back(new GraphicElement("noir-mort.png"));
			vect[vect.size()-1]->setRotation(rand()%360);
			vect[vect.size()-1]->setScale(1.5);
			vect[vect.size()-1]->setPosition(Point2I(1100-MARGE_W/2-40+rand()%80,360-40+rand()%80));
			break;
		case BLANC:vect.push_back(new GraphicElement("blanc-mort.png"));
			vect[vect.size()-1]->setRotation(rand()%360);
			vect[vect.size()-1]->setScale(1.5);
			vect[vect.size()-1]->setPosition(Point2I(MARGE_W/2-40+rand()%80,360-40+rand()%80));
			break;
	}
}
