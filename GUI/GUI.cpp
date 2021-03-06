/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "GUI.h"

sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "GUI chess");
std::vector<GraphicElement*> interface ;
std::vector<ClickableElement*> boutons ;
GraphicElement* graphicMusic  = new GraphicElement("music-on.png");;
ClickableElement *musicClickable;
sf::Music music;
int nbJoueurs;
bool gameGoesOn = false;
bool musicEnable = true;
string engineIP = "localhost";
extern bool check ;
void GUI(){
	int cnt =0;
	srand (time(NULL));
	bool startGame = true;
	musicInitialisation();
	interfaceInitialisation(0);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)){
		
			if (event.type == sf::Event::Closed){
				window.close();
				check = false;
				exit(0);
			}
			else if (event.type == sf::Event::MouseButtonPressed ){
				notifyInterface(event);
				if(gameGoesOn)
					notifyGame(event);
			}
		}
		window.clear();
		
		if(gameGoesOn)
			displayGameIn(window);
		displayInterfaceIn(window);
		window.display();
		
		if(gameGoesOn){
			if(cnt %100 == 0)
				checkFunctionnement();
			cnt++;
		}
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
			if(stringActu.size() != 0)
				splited.push_back(string(stringActu));
			stringActu = "";
		}
	}
	if(stringActu.size() != 0)
		splited.push_back(string(stringActu));
}



char convertCharToArrayIndex(char lettre){
	if(lettre >= 97){
		return lettre%97 +1;		
	}
	else{
		return lettre%48 - 1;
	}
}

void displayInterfaceIn(sf::RenderWindow &window){
	int  nb2 = interface.size();
	// Dans cette boucle, on affiche l'ensemble des objets graphiques du jeu (hors pieces)
	for(int i=0;i<nb2;i++)
		interface.at(i)->draw(window);
}

void interfaceInitialisation(int step){
	interface.clear();
	boutons.clear();
	Point2I p1;
	Point2I p2;
	sf::Vector2u v;

	switch(step){
		case 0:	interface.push_back(new GraphicElement("accueil.png"));
			interface.push_back(graphicMusic);
			boutons.push_back(musicClickable);
			interface.push_back(new GraphicElement("bouton-newGame.png"));

			v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			p1 =  Point2I(WINDOW_W/2 - v.x/2, WINDOW_H - v.y - 100);
			p2 =  Point2I(WINDOW_W/2 + v.x/2, WINDOW_H - 100);

			interface[interface.size()-1]->setPosition(p1);
			boutons.push_back(new ClickableElement(p1, p2, &newGame));
			break;

		case 1:	interface.push_back(new GraphicElement("accueil.png"));
			interface.push_back(graphicMusic);
			boutons.push_back(musicClickable);
			interface.push_back(new GraphicElement("bouton-2Players.png"));

			v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			p1 =  Point2I(WINDOW_W/2 - v.x/2, WINDOW_H - v.y - 200);
			p2 =  Point2I(WINDOW_W/2 + v.x/2, WINDOW_H - 200);

			interface[interface.size()-1]->setPosition(p1);
			boutons.push_back(new ClickableElement(p1, p2, &playerNumberSetTo2));

			interface.push_back(new GraphicElement("bouton-1Players.png"));

			v = interface[interface.size()-1]->getSprite(0).getTexture()->getSize();
			p1 =  Point2I(WINDOW_W/2 - v.x/2, WINDOW_H - v.y - 500);
			p2 =  Point2I(WINDOW_W/2 + v.x/2, WINDOW_H - 500);

			interface[interface.size()-1]->setPosition(p1);
			boutons.push_back(new ClickableElement(p1, p2, &playerNumberSetTo1));
			break;
		case 2:	interface.push_back(graphicMusic);
			boutons.push_back(musicClickable);
			gameInitialisation();
			gameGoesOn = true;
			break;
	}
}

void notifyInterface(sf::Event event){
	int l = boutons.size();
	for(int i = 0;i<l;i++){
		boutons[i]->isInside(event);
	}
}

void newGame(){
	interfaceInitialisation(1);
	//cout<<"New Game\n";
}

void playerNumberSetTo1(){
	nbJoueurs = 1;
	interfaceInitialisation(2);
	//cout<<"Players set to 1\n";
}

void playerNumberSetTo2(){
	nbJoueurs = 2;
	interfaceInitialisation(2);
	//cout<<"Players set to 2\n";
}

void setMusicEnable(){
	sf::Vector2u v = graphicMusic->getSprite(0).getTexture()->getSize();
	Point2I p1 =  Point2I(WINDOW_W - v.x -10, WINDOW_H - v.y - 10);
	if(musicEnable){
		musicEnable = false;
		music.pause();
		graphicMusic->setSprite("music-off.png",0);
		cout<<"Music off\n";
	}else{
		musicEnable = true;
		music.play();
		graphicMusic->setSprite("music-on.png",0);
		cout<<"Music on\n";
	}
	graphicMusic->setPosition(p1);
}

void musicInitialisation(){
	music.openFromFile("ressources/music.ogg");
	music.setLoop(true);
	music.play();
	graphicMusic = new GraphicElement("music-on.png");
	sf::Vector2u v = graphicMusic->getSprite(0).getTexture()->getSize();
	Point2I p1 =  Point2I(WINDOW_W - v.x -10, WINDOW_H - v.y - 10);
	Point2I p2 =  Point2I(WINDOW_W -10, WINDOW_H - 10);	
	graphicMusic->setPosition(p1);
	musicClickable = new ClickableElement(p1, p2, &setMusicEnable);
}
