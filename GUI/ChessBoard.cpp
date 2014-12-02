#include <SFML/Graphics.hpp>

class ChessBoard: public GraphicElement{
	private:
		ChessCase cases[64];
	
	public:
		ChessBoard();
}

public ChessBoard::ChessBoard(){
	
	for(int i = 0;i<64;i++){
		cases[i] =  new ChessCase();
	}
}

