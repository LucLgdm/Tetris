/* +++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Piece +++ */
/* +++++++++++++++++++++++++++++++++++ */

#include "Piece.h"
#include "util.h"


const int Piece::TURN_RIGHT=0;
const int Piece::TURN_LEFT=1;

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Piece::Piece(int orientation){
	this->orientation = orientation;
	for(int i = 0; i<4; i++) this->brique[i] = NULL;
   this->briqueref= NULL;
}

/* =================== */
/* === Destructeur === */
/* =================== */
Piece::~Piece(){
   for(int i = 0; i<4; i++) this->brique[i] = NULL;	// les briques seront détruites par le plateau
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ======================= */
/* === Fonction cirage === */
/* ======================= */
void Piece :: cirage(double* rouge, double* vert, double* bleu){
	int couleur = tirage();
	if(couleur == 0){
		*rouge = 1.0;
		*vert = 0.0;
		*bleu = 0.0;
		return;
	}
	if(couleur == 1){
		*rouge = 0.0;
		*vert = 1.0;
		*bleu = 0.0;
		return;
	}
	if(couleur == 2){
		*rouge = 0.0;
		*vert = 0.0;
		*bleu = 1.0;
		return;
	}
	if(couleur == 3){
		*rouge = 1.0;
		*vert = 1.0;
		*bleu = 0.0;
		return;
	}
	if(couleur == 4){
		*rouge = 1.0;
		*vert = 0.0;
		*bleu = 1.0;
		return;
	}
	if(couleur == 5){
		*rouge = 0.0;
		*vert = 1.0;
		*bleu = 1.0;
		return;
	}
	*rouge = 1.0;
	*vert = 1.0;
	*bleu = 1.0;
	return;
}
/* ===================== */
/* === Fonction draw === */
/* ===================== */
void Piece :: draw(double taille, double xref, double yref){
	for(int i = 0; i<4;i++){
		this->brique[i]->draw(taille, xref, yref);
	}
}
/* ========================== */
/* === Fonction translate === */
/* ========================== */
void Piece :: translate(int di, int dj){
	for(int i = 0; i<4; i++){
		this->brique[i]->translate(di,dj);
	}
}

void Piece::get_positions_i(int*table){
	for(int i = 0; i<4;i++){
		table[i]=this->brique[i]->get_position_i();
	}
}


void Piece::get_positions_j(int*table){
	for(int i = 0; i<4;i++){
		table[i]=this->brique[i]->get_position_j();
	}
}

Brique* Piece::get_brique(int i){
	return this->brique[i];
}

/* ========================= */
/* === fonction rotation === */
/* ========================= */
/*
void Piece::tourner(int a){
	this->orientation=(this->orientation+a)%4;
}
*/

// DEBUT A EFFACER
/* ======================== */
/* === fonction deplace === */
/* ======================== */
/*
void Piece::deplace(int a){
	this->Xref=this->Xref+a;
}
*/

/* ========================== */
/* === fonction descendre === */
/* ========================== */
/*
void Piece::descendre(){
	this->Yref=this->Yref+1;
}
*/
// FIN A EFFACER

/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
