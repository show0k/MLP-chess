#include "ChessPiece.h"
#include "ChessBoard.h"

class ChessPieceSet{
	private:
		
		int color;
	public:
		ChessPiece *pieces[16];
		std::vector<ChessPiece> activePieces;
		ChessPieceSet(int color);
		void slainChessPiece(int n);
		~ChessPieceSet();
		void addPiecesToBoard(ChessBoard &plateau);
		ChessPiece* getPieceAt(ChessCase c);
		ChessPiece* TESTgetRandomPiece();
};
