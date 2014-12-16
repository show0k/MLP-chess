classes :


Square:
Représentation de l'emplacement d'une piece (un numéro)

Move:
Représentation d'un déplacement et d'une piece
une piece, une origine, une destination
Utilisé pour l'API

Board :
Vue courante du jeu, doit être mise à jour en fonction des différents move et go
methodes :
        void newGame();
        void find_legal_moves(MoveList &moves) const;
        void make_move(const Move &move);
        void undo_move(const Move &move);
        bool IsMoveValid(CMove &move) const;
        bool isKingInCheck() const;
        bool isOtherKingInCheck() const;


API:
prend en entrée les commandes move, go
Communication avec la GUI

MoveList:
Liste représentatant une liste de mouvements


IA :
Donne un position à jouer de façon "intelligente"


