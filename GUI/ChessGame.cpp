#include "GUI.h"
#include "ChessPieceSet.h"

ChessCase *caseSelect;
ChessPiece *pieceSelect;
std::vector<GraphicElement*> objGraphiques ;
ChessPieceSet michelBlanc = ChessPieceSet(BLANC);
ChessPieceSet michelNoir = ChessPieceSet(NOIR);
ChessBoard plateau;
int nbMouvementsAffiches = 0;
std::vector<ChessCase*> casesAutorisees;
int joueurActu = 0;

extern std::vector<GraphicElement*> interface ;
extern std::vector<ClickableElement*> boutons ;

void gameInitialisation(){
	michelBlanc = ChessPieceSet(BLANC);
	michelNoir = ChessPieceSet(NOIR);
	michelBlanc.addPiecesToBoard(plateau);
	michelNoir.addPiecesToBoard(plateau);
	joueurActu = BLANC;
	displayPlayer(joueurActu);
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
	if(stringContains(action, "move")){
		ChessCase *caseActu = NULL;
		string piece = action.substr(5,2);
		string destination = action.substr(8,2);
		
		char lettre = convertCharToArrayIndex(piece.at(0)), chiffre = 8- (piece.at(1)-40);
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
		makePieceMove(caseActu);
		
	}else if(stringContains(action, "victoire")){
		std::vector<string> splited;
		stringSplit(action, ' ',splited);
		if(splited[1] == "BLANC"){
			interface.push_back(new GraphicElement("victoire-blanc.png"));
			sf::Vector2u v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			interface[interface.size()-1]->setPosition(Point2I((int)(WINDOW_W/2 - v.x/2 ),(int)(WINDOW_H/2 - v.y/2)));
		}
		else if (splited[1] == "NOIR"){
			interface.push_back(new GraphicElement("victoire-noir.png"));
			sf::Vector2u v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			interface[interface.size()-1]->setPosition(Point2I((int)(WINDOW_W/2 - v.x/2 ),(int)(WINDOW_H/2 - v.y/2)));
		}
		else
			cout<<"De qui??\n";
		
	}else if(stringContains(action, "show")){
		std::vector<string> splited;
		stringSplit(action, ' ',splited);
		int l = splited.size();
		for(int i = 1;i<l;i++){
			addPossibleMove(plateau.caseAt(splited[i].at(2)-97,8-(splited[i].at(3)-48)));
			casesAutorisees.push_back(plateau.caseAt(splited[i].at(2)-97,8-(splited[i].at(3)-48)));
			nbMouvementsAffiches ++;
		}
	}else if(stringContains(action, "player playing")){
		std::vector<string> splited;
		stringSplit(action, ' ',splited);
		if(splited[2] == "blanc"){
			joueurActu = BLANC;
		}else if (splited[2] == "noir"){
			joueurActu = NOIR;
		}
		else
			cout<<"C'est pas une couleur!\n";
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
	/*graphicEffect("grow", &vect[vect.size()-1]->getSprite(0), 3, 1.5);
	sf::Thread thread(&growSprite);
	thread.launch();*/
}

void addDeadPony(std::vector<GraphicElement*> &vect, char color){
	switch(color){
		case NOIR:vect.push_back(new GraphicElement("noir-mort.png"));
			vect[vect.size()-1]->setRotation(rand()%360);
			vect[vect.size()-1]->setScale(1.5);
			vect[vect.size()-1]->setPosition(Point2I(WINDOW_W-MARGE_W/2-40+rand()%80,WINDOW_H/2-40+rand()%80));
			break;
		case BLANC:vect.push_back(new GraphicElement("blanc-mort.png"));
			vect[vect.size()-1]->setRotation(rand()%360);
			vect[vect.size()-1]->setScale(1.5);
			vect[vect.size()-1]->setPosition(Point2I(MARGE_W/2-40+rand()%80,WINDOW_H/2 -40+rand()%80));
			break;
	}
}

void notifyGame(sf::Event event){
	caseSelect = plateau.notifyCases(event);
	if((nbMouvementsAffiches != 0) && pieceSelect->notNull()){
		if(caseSelect->isInVector(casesAutorisees)){
			makePieceMove(caseSelect);
			resetPossibleMove();
			changePlayer();
		}
	}
	switch(caseSelect->getType()){
		case BLANC:	if(joueurActu ==caseSelect->getType()){
					pieceSelect = michelBlanc.getPieceAt(*caseSelect);
					cout<<pieceSelect->toString()<<"\n";
				}
				break;
		case NOIR:	if(joueurActu ==caseSelect->getType()){
					pieceSelect = michelNoir.getPieceAt(*caseSelect);
					cout<<pieceSelect->toString()<<"\n";
				}
				break;
		case VIDE: 	pieceSelect = new ChessPiece();
				resetPossibleMove();
				break;
	}
	int x = (caseSelect->getCoord()[0]-97) *SPRITE_SIZE +MARGE_W+ SPRITE_SIZE/2;
	int y = (8-caseSelect->getCoord()[1]) *SPRITE_SIZE+MARGE_H + SPRITE_SIZE/2;
}

void addPossibleMove(ChessCase *c){
	if(c->isEmpty())
		interface.push_back(new GraphicElement("mouvement-caseVide.png"));
	else
		interface.push_back(new GraphicElement("mouvement-prendrePiece.png"));
	interface[interface.size()-1]->setPosition(c->getStartPoint());
}

void resetPossibleMove(){
	while(nbMouvementsAffiches>0){
		nbMouvementsAffiches --;
		interface.pop_back();
	}
	casesAutorisees.clear();
}

void makePieceMove(ChessCase *c){
	ChessPiece *pieceActu = NULL;
	string s = "";
	switch(c->getType()){
		case BLANC:	pieceActu = michelBlanc.getPieceAt(*c);
				break;
		case NOIR:	pieceActu = michelNoir.getPieceAt(*c);
				break;
	}	
	if(pieceSelect != NULL){
		pieceSelect->setCase(c);
		cout << pieceSelect->toString()<<" va en "<< c->toString();
		if(pieceActu != NULL){
			cout<<"et mange "<<pieceActu->toString()<<" \n";
			int x = (c->getCoord()[0]-97) *SPRITE_SIZE +MARGE_W+ SPRITE_SIZE/2;
			int y = (8-c->getCoord()[1]) *SPRITE_SIZE+MARGE_H + SPRITE_SIZE/2;
			addBloodSpot(objGraphiques, x, y);
			addDeadPony(objGraphiques, pieceActu->getColor());
			pieceActu->slain();
		}else
			cout<<"\n";
		string cmd = "move ";
		char l = pieceSelect->getCase()->getCoord()[0];
		char ch = 8-pieceSelect->getCase()->getCoord()[1] + 48;
		cmd = cmd.append(1u,l);
		cmd = cmd.append(1u,ch);
		l = c->getCoord()[0];
		ch = c->getCoord()[1] + 48;
		cmd = cmd.append(1u,l);
		cmd = cmd.append(1u,ch);
		sendCommand(cmd);
	}
	else{
		cout<<"Aucune pièce selectionnée\n";
	}
}

void changePlayer(){
	interface.pop_back();
	boutons.pop_back();
	if(joueurActu == BLANC)
		joueurActu = NOIR;
	else
		joueurActu = BLANC;
	displayPlayer(joueurActu);
}

void displayPlayer(int color){
	sf::Vector2u v;
	Point2I p1;
	Point2I p2;
	if(joueurActu == NOIR){
		interface.push_back(new GraphicElement("blackIsPlaying.png"));

		v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
		p1 =  Point2I(WINDOW_W - v.x - 20, 50);
		p2 =  Point2I(WINDOW_W + 20 , v.y + 50);

		interface[interface.size()-1]->setPosition(p1);
		boutons.push_back(new ClickableElement(p1, p2, &playerNumberSetTo2));
		//cout<<"Joueur noir joue\n";
	}else{
		interface.push_back(new GraphicElement("whiteIsPlaying.png"));

		v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
		
		p1 =  Point2I(20, 50);
		p2 =  Point2I(20 + v.x, v.y + 50);

		interface[interface.size()-1]->setPosition(p1);
		boutons.push_back(new ClickableElement(p1, p2, &playerNumberSetTo2));
		//cout<<"Joueur blanc joue\n";
	}
}
