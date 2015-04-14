/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "ChessBoard.h"
#include "ClickableElement.h"
#include <SFML/Audio.hpp>
#include <unistd.h>

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
void setMusicEnable();
void musicInitialisation();

void newGame();
void playerNumberSetTo1();
void playerNumberSetTo2();
void addPossibleMove(ChessCase *c);
void resetPossibleMove();
void makePieceMove(ChessCase *c);
void changePlayer();
void displayPlayer(int color);
void checkFunctionnement();
