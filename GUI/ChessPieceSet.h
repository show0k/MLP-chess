/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
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
