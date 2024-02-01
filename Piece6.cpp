/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Piece6 +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#include "Piece6.h"

// Piece en S2

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Piece6::Piece6(int orient, int x, int y):Piece(orient){
   double rouge, vert, bleu;
	this->cirage(&rouge, &vert, &bleu);
	this->brique[0] = new Brique(rouge, vert, bleu, x, y);
	this->brique[1] = new Brique(rouge, vert, bleu, x, y+1);
	this->brique[2] = new Brique(rouge, vert, bleu, x+1, y);
	this->brique[3] = new Brique(rouge, vert, bleu, x+1, y-1);
	this->briqueref=this->brique[0];
}

/* =================== */
/* === Destructeur === */
/* =================== */
Piece6::~Piece6(){
   
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Piece6::selfDisplay(std::ostream& stream) const {
   std::cout << "piece 6 \n";
	for (int i = 0; i<4; i++){
		std::cout << *(this->brique[i]);	
	}
}

int Piece6::get_most_left_brique(){
	if (this->orientation==2||this->orientation==0){ 
		return this->briqueref->get_position_i();
	}
	return this->briqueref->get_position_i()-1;
}

int Piece6::get_most_right_brique(){
	return this->briqueref->get_position_i()+1;	
}

void Piece6::tourner(int sens){
	if(sens==Piece::TURN_RIGHT){
		this->orientation=(this->orientation+1)%4;
	}else{
		this->orientation=(this->orientation+3)%4; 
	}
	int i_ref=this->briqueref->get_position_i();
	int j_ref=this->briqueref->get_position_j();
	if (this->orientation==0){
		this->brique[1]->set_position_i(i_ref);
		this->brique[1]->set_position_j(j_ref+1);
		this->brique[2]->set_position_i(i_ref+1);
		this->brique[2]->set_position_j(j_ref);
		this->brique[3]->set_position_i(i_ref+1);
		this->brique[3]->set_position_j(j_ref-1);		
	}else if (this->orientation==1){
		this->brique[1]->set_position_i(i_ref+1);
		this->brique[1]->set_position_j(j_ref);
		this->brique[2]->set_position_i(i_ref);
		this->brique[2]->set_position_j(j_ref-1);
		this->brique[3]->set_position_i(i_ref-1);
		this->brique[3]->set_position_j(j_ref-1);		
	}else if (this->orientation==2){
		this->brique[1]->set_position_i(i_ref);
		this->brique[1]->set_position_j(j_ref+1);
		this->brique[2]->set_position_i(i_ref+1);
		this->brique[2]->set_position_j(j_ref);
		this->brique[3]->set_position_i(i_ref+1);
		this->brique[3]->set_position_j(j_ref-1);		
	}else {
		this->brique[1]->set_position_i(i_ref+1);
		this->brique[1]->set_position_j(j_ref);
		this->brique[2]->set_position_i(i_ref);
		this->brique[2]->set_position_j(j_ref-1);
		this->brique[3]->set_position_i(i_ref-1);
		this->brique[3]->set_position_j(j_ref-1);
	}
}

void Piece6::get_positions_after_turn(int*table_i,int*table_j,int sens){
	int new_orientation;
	if(sens==Piece::TURN_RIGHT){
		new_orientation=(this->orientation+1)%4;
	}else{
		new_orientation=(this->orientation+3)%4; 
	}
	int i_ref=this->briqueref->get_position_i();
	int j_ref=this->briqueref->get_position_j();
	table_i[0]=i_ref;
	table_j[0]=j_ref;
	if (new_orientation==0){
		table_i[1]=i_ref;
		table_j[1]=j_ref+1;
		table_i[2]=i_ref+1;
		table_j[2]=j_ref;
		table_i[3]=i_ref+1;
		table_j[3]=j_ref-1;
	}else if (new_orientation==1){
		table_i[1]=i_ref+1;
		table_j[1]=j_ref;
		table_i[2]=i_ref;
		table_j[2]=j_ref-1;
		table_i[3]=i_ref-1;
		table_j[3]=j_ref-1;
	}else if (new_orientation==2){
		table_i[1]=i_ref;
		table_j[1]=j_ref+1;
		table_i[2]=i_ref+1;
		table_j[2]=j_ref;
		table_i[3]=i_ref+1;
		table_j[3]=j_ref-1;
	}else{
		table_i[1]=i_ref+1;
		table_j[1]=j_ref;
		table_i[2]=i_ref;
		table_j[2]=j_ref-1;
		table_i[3]=i_ref-1;
		table_j[3]=j_ref-1;
	}
}

/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
