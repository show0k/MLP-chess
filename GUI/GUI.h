#include "ChessBoard.h"

void GUI(void);
bool stringContains(string s1, string s2);
void stringSplit(string s, char c, std::vector<string> &splited);
void parseAction(string action);
void addBloodSpot(std::vector<GraphicElement*> &vect, int x, int y);
char convertCharToArrayIndex(char lettre);
void addDeadPony(std::vector<GraphicElement*> &vect, char color);


