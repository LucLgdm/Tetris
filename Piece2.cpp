/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Piece2 +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#include "Piece2.h"

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Piece2::Piece2(int orient, int x, int y):Piece(orient){
   double rouge, vert, bleu;
	this->cirage(&rouge, &vert, &bleu);
	this->brique[0] = new Brique(rouge, vert, bleu, x-1, y);
	this->brique[1] = new Brique(rouge, vert, bleu, x, y);
	this->brique[2] = new Brique(rouge, vert, bleu, x+1, y);
	this->brique[3] = new Brique(rouge, vert, bleu, x+2, y);
	this->briqueref=this->brique[1];
}

/* =================== */
/* === Destructeur === */
/* =================== */
Piece2::~Piece2(){
   
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Piece2::selfDisplay(std::ostream& stream) const {
   std::cout << "piece 2 \n";
	for (int i = 0; i<4; i++){
		std::cout << *(this->brique[i]);	
	}
}


int Piece2::get_most_right_brique(){
	if (this->orientation==1||this->orientation==3){ 
		return this->briqueref->get_position_i();
	}
	return this->briqueref->get_position_i()+2;	
}

int Piece2::get_most_left_brique(){
	if (this->orientation==1||this->orientation==3){ 
		return this->briqueref->get_position_i();
	}
	return this->briqueref->get_position_i()-1;	
}

void Piece2::tourner(int sens){
	if(sens==Piece::TURN_RIGHT){
		this->orientation=(this->orientation+1)%4;
	}else{
		this->orientation=(this->orientation+3)%4; 
	}
	int i_ref=this->briqueref->get_position_i();
	int j_ref=this->briqueref->get_position_j();
	if (this->orientation==0||this->orientation==2){
		this->brique[0]->set_position_i(i_ref-1);
		this->brique[0]->set_position_j(j_ref);
		this->brique[2]->set_position_i(i_ref+1);
		this->brique[2]->set_position_j(j_ref);
		this->brique[3]->set_position_i(i_ref+2);
		this->brique[3]->set_position_j(j_ref);		
	}else{
		this->brique[0]->set_position_i(i_ref);
		this->brique[0]->set_position_j(j_ref+1);
		this->brique[2]->set_position_i(i_ref);
		this->brique[2]->set_position_j(j_ref-1);
		this->brique[3]->set_position_i(i_ref);
		this->brique[3]->set_position_j(j_ref-2);
	}
}


void Piece2::get_positions_after_turn(int*table_i,int*table_j,int sens){
	int new_orientation;
	if(sens==Piece::TURN_RIGHT){
		new_orientation=(this->orientation+1)%4;
	}else{
		new_orientation=(this->orientation+3)%4; 
	}
	int i_ref=this->briqueref->get_position_i();
	int j_ref=this->briqueref->get_position_j();
	table_i[1]=i_ref;
	table_j[1]=j_ref;
	if (new_orientation==0||new_orientation==2){
		table_i[0]=i_ref-1;
		table_j[0]=j_ref;
		table_i[2]=i_ref+1;
		table_j[2]=j_ref;
		table_i[3]=i_ref+2;
		table_j[3]=j_ref;
	}else{
		table_i[0]=i_ref;
		table_j[0]=j_ref+1;
		table_i[2]=i_ref;
		table_j[2]=j_ref-1;
		table_i[3]=i_ref;
		table_j[3]=	j_ref-2;
	}
}
/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
