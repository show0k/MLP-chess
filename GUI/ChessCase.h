#include "ClickableElement.h"

class ChessCase : public ClickableELement {
	private:
		bool occup;
		char type;
		char coord[2]; //coord[0] = chiffre || coord[0] = lettre
	public:
		ChessCase(int a, int b);
};
