/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Piece1 +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#include "Piece1.h"

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Piece1::Piece1(int orient, int x, int y):Piece(orient){
   double rouge, vert, bleu;
	this->cirage(&rouge, &vert, &bleu);
	this->brique[0] = new Brique(rouge, vert, bleu, x, y);
	this->brique[1] = new Brique(rouge, vert, bleu, x+1, y);
	this->brique[2] = new Brique(rouge, vert, bleu, x+1, y-1);
	this->brique[3] = new Brique(rouge, vert, bleu, x, y-1);
	this->briqueref=this->brique[0];
}

/* =================== */
/* === Destructeur === */
/* =================== */
Piece1::~Piece1(){
   
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Piece1::selfDisplay(std::ostream& stream) const {
   std::cout << "piece 1 \n";
	for (int i = 0; i<4; i++){
		std::cout << *(this->brique[i]);	
	}
}


int Piece1::get_most_right_brique(){
	return this->briqueref->get_position_i()+1;
}

int Piece1::get_most_left_brique(){
	return this->briqueref->get_position_i();
}

void Piece1::tourner(int sens){
	return;
}

void Piece1::get_positions_after_turn(int*table_i,int* table_j,int sens){
	for (int i = 0; i<4; i++){
		table_i[i]=this->brique[i]->get_position_i();
		table_j[i]=this->brique[i]->get_position_j();
	}
}


/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
