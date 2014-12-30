#include "ChessBoard.h"
#include "ClickableElement.h"

void GUI(void);
bool stringContains(string s1, string s2);
void stringSplit(string s, char c, std::vector<string> &splited);
void parseAction(string action);
void addBloodSpot(std::vector<GraphicElement*> &vect, int x, int y);
char convertCharToArrayIndex(char lettre);
void addDeadPony(std::vector<GraphicElement*> &vect, char color);
void gameInitialisation();

void displayGameIn(sf::RenderWindow &window);
void displayInterfaceIn(sf::RenderWindow &window);
void interfaceInitialisation(int step);
void notifyInterface(sf::Event event);
void notifyGame(sf::Event event);

void newGame();
void playerNumberSetTo1();
void playerNumberSetTo2();
void addPossibleMove(ChessCase *c);
void resetPossibleMove();
void makePieceMove(ChessCase *c);
