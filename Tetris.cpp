/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Tetris +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Tetris.h"
#include "kernelsy.h"
#include "util.h"
#include "Piece1.h"
#include "Piece2.h"
#include "Piece3.h"
#include "Piece4.h"
#include "Piece5.h"
#include "Piece6.h"
#include "Piece7.h"

const int Tetris :: PIECE_VOLANTE = 1;
const int Tetris :: MAJ_PLATEAU = 2;
const int Tetris :: CHUTE_IMPOSEE = 3;

const int Tetris :: MOVE_DROITE = 4; 
const int Tetris :: MOVE_GAUCHE = 5;
const int Tetris :: TURN_DROITE = 6;
const int Tetris :: TURN_GAUCHE = 7;
const int Tetris :: FULL_SPEED = 8;
const int Tetris :: STAND_BY = 9;

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Tetris::Tetris(int nb_cases_verticale, int nb_cases_horizontale){
/* ----------------------------------------------------------- */
/* --- Initialisations provisoires des attributs pointeurs --- */
/* ----------------------------------------------------------- */
		this->plateau = NULL;
		this->time_lap=NULL;
		this->piece_volante = NULL;
		this->piece_suivante = NULL;
/* ---------------------------------- */
/* --- Initialisations par défaut --- */
/* ---------------------------------- */
      this->currentGameLevel = 0;
		this->score = 0;
		this->nombre_lignes_cassees = 0;
      
 /* --------------------------------------- */
 /* --- Récupération du nombre de cases --- */
 /* --------------------------------------- */
      this->verticalCaseNumber = nb_cases_verticale;
      this->horizontalCaseNumber = nb_cases_horizontale;
      
 /* ------------------------------- */
 /* --- Construction du plateau --- */
 /* ------------------------------- */
		this->plateau = new Plateau(nb_cases_verticale,nb_cases_horizontale,1.0,1.0,1.0);
		this->level_number = 10;
		this->time_lap = new int[level_number];
		this->first_level_time_lap = 500;
		int dt = this->first_level_time_lap;
		for(int i = 0; i<this->level_number; i++){
			this->time_lap[i] = dt;
			dt = int(0.9*dt);
		}
		this->state = Tetris :: MAJ_PLATEAU;
		this->time_lap_chute_libre = 50;

 /* ----------------------------------------- */
 /* --- Construction de la piece suivante --- */
 /* ----------------------------------------- */
		this->piece_suivante = this->creation();

      ftime(&(this->initialTime));

}

/* =================== */
/* === Destructeur === */
/* =================== */
Tetris::~Tetris(){
/* ----------------------------- */
/* --- Destruction 'plateau' --- */
/* ----------------------------- */
	if (this->time_lap != NULL){
   	delete this->time_lap; 
   }
   if (this->plateau != NULL){
      delete this->plateau;
   }
	if(this->piece_volante != NULL){
		delete this->piece_volante;
	}
	if(this->piece_suivante != NULL){
		delete this->piece_suivante;
	}
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Tetris::selfDisplay(std::ostream& stream) const {
      stream << "TETRIS\n";
      stream << "  . Niveau atteint : " << this->currentGameLevel << "\n";
      stream << "  . Nbre cases verticales : " << this->verticalCaseNumber << "\n";
      stream << "  . Nbre cases horizontales : " << this->horizontalCaseNumber << "\n";
		stream << "  . Score = " << this->score << "\n";
		stream << *(this->plateau);
		for(int i = 0; i<this->level_number; i++){
			stream << this->time_lap[i] << "\n";
		}
}

/* ===================== */
/* === Fonction draw === */
/* ===================== */
void Tetris :: draw(){

/* ----------- */
/* --- RAZ --- */
/* ----------- */
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

/* ------------------------------------ */
/* --- Dessin du liseret du plateau --- */
/* ------------------------------------ */
	glBegin(GL_LINE_LOOP);
   glColor3d( 0.4,0.4,0.4 ); 
   	glVertex2d( 0.8  , 0.8  );
     	glVertex2d( 11.2 , 0.8  );
     	glVertex2d( 11.2 , 23.2 );
    	glVertex2d( 0.8  , 23.2 );
   glEnd();

/* ----------------------------------------------- */
/* --- Dessin du liseret dde la pièce suivante --- */
/* ----------------------------------------------- */
	glBegin(GL_LINE_LOOP);
   	glColor3d( 0.4,0.4,0.4 ); 
   	glVertex2d( 12.8 , 16.8 );
		glVertex2d( 19.2 , 16.8 );
		glVertex2d( 19.2 , 23.2 );
		glVertex2d( 12.8 , 23.2 );
   glEnd();

/* ---------------------------------- */
/* --- Dessin du liseret du score --- */
/* ---------------------------------- */
	glBegin(GL_LINE_LOOP);
   	glColor3d( 0.4,0.4,0.4 ); 
   	glVertex2d( 12.8 , 10.8 );
		glVertex2d( 19.2 , 10.8 );
		glVertex2d( 19.2 , 13.2 );
		glVertex2d( 12.8 , 13.2 );
   glEnd();

/* ------------------------- */
/* --- Dessin du plateau --- */
/* ------------------------- */
	this->plateau->draw();


/* ------------------------------------------- */
/* --- Dessin eventuel de la piece volante --- */
/* ------------------------------------------- */
	if(this->piece_volante != NULL){
		this->piece_volante->draw(1.0, 1.0, 1.0);
	}

/* -------------------------------------------- */
/* --- Dessin eventuel de la piece suivante --- */
/* -------------------------------------------- */
	if(this->piece_suivante != NULL){
		this->piece_suivante->draw(1.0, 13.0, 17.0);
	}
	std::cout << this->score << "\n";

}

/* ========================== */
/* === Fonction get_score === */
/* ========================== */

int Tetris::get_score(){
	return this->score;
}

/* ========================== */
/* === Fonction get_level === */
/* ========================== */

int Tetris::get_level(){
	return this->currentGameLevel;
}

/* ========================= */
/* === Fonction get_time === */
/* ========================= */

int Tetris::get_time(){
	struct timeb realCurrentTime;
	ftime(&realCurrentTime);
	int temps = int( ( (unsigned long int)realCurrentTime.time -
		                (unsigned long int)this->initialTime.time ) +
        		          (realCurrentTime.millitm - this->initialTime.millitm)/1000);

	return temps;
}

/* ====================== */
/* === Fonction simul === */
/* ====================== */
int Tetris :: simul(int action){
	int new_positions_i[4];
	int new_positions_j[4];
	int i;



	switch(this->state){
/* -------------------------- */
/* --- Etat PIECE_VOLANTE --- */
/* -------------------------- */

	case Tetris :: PIECE_VOLANTE:
/* ::::::::::::::::::::::::::: */
/* ::: Gestion de l'action ::: */
/* ::::::::::::::::::::::::::: */



		switch (action){
		case Tetris :: MOVE_DROITE :
			if (this->piece_volante->get_most_right_brique() < this->horizontalCaseNumber-1){
			   this->piece_volante->get_positions_i(new_positions_i);
			   this->piece_volante->get_positions_j(new_positions_j);
			   for (i=0;i<4;i++){
			   	new_positions_i[i]++;			
			   }
			   if (this->plateau->position_libre(new_positions_i,new_positions_j)){
			      this->piece_volante->translate(1,0);
			   }
			}
			break;
		case Tetris :: MOVE_GAUCHE : 
			if (this->piece_volante->get_most_left_brique() >0){
			   this->piece_volante->get_positions_i(new_positions_i);
			   this->piece_volante->get_positions_j(new_positions_j);
			   for (i=0;i<4;i++){
			   	new_positions_i[i]--;			
			   }
			   if (this->plateau->position_libre(new_positions_i,new_positions_j)){
			      this->piece_volante->translate(-1,0);
			   }
			}
			break;
		case Tetris :: TURN_DROITE : 
			this->piece_volante->get_positions_after_turn(new_positions_i,new_positions_j,Piece::TURN_RIGHT);
			if (this->position_libre(new_positions_i,new_positions_j)){
				this->piece_volante->tourner(Piece::TURN_RIGHT);
			}		
			break;
		case Tetris :: TURN_GAUCHE : 
			this->piece_volante->get_positions_after_turn(new_positions_i,new_positions_j,Piece::TURN_LEFT);
			if (this->position_libre(new_positions_i,new_positions_j)){
				this->piece_volante->tourner(Piece::TURN_LEFT);
			}
			break;
		case Tetris :: FULL_SPEED : 
			this->state = Tetris :: CHUTE_IMPOSEE;
			break;
		}
/* :::::::::::::::::::::::: */
/* ::: Gestion du temps ::: */
/* :::::::::::::::::::::::: */
		if(noyau.temps_ecoule(this->time_lap[this->currentGameLevel])){
			this->piece_volante->get_positions_i(new_positions_i);
			this->piece_volante->get_positions_j(new_positions_j);
			for (i=0;i<4;i++){
				new_positions_j[i]--;			
			}
			if (this->touche_plateau(new_positions_i,new_positions_j)){

				this->plateau->reception_piece(this->piece_volante);
				delete this->piece_volante;
				this->piece_volante=NULL; 
				this->state = Tetris :: MAJ_PLATEAU;	
		   }else {
				this->piece_volante->translate(0,-1);
				this->noyau.initialize();
			}
			
		}
		break;
/* ------------------------ */
/* --- Etat MAJ_PLATEAU --- */
/* ------------------------ */
	case Tetris :: MAJ_PLATEAU:
		this->noyau.initialize();	
		this->nombre_lignes_cassees += this->plateau->destruction_descente_ligne(this->currentGameLevel, &(this->score));
		this->noyau.synchronize(this->time_lap[this->currentGameLevel]);
		this->piece_volante = this->piece_suivante;
		this->piece_volante->translate(2,17);
		this->piece_volante->get_positions_i(new_positions_i);
		this->piece_volante->get_positions_j(new_positions_j);
		if (!this->position_libre(new_positions_i,new_positions_j)){
			std::cout<<"game over\n"; 
			exit(0);
		}else{
			if (this->touche_plateau(new_positions_i,new_positions_j)){
				std::cout<<"game over\n"; 
				exit(0);
			}
		}
		this->piece_suivante = this->creation();
		this->state = Tetris :: PIECE_VOLANTE;
		if(currentGameLevel < level_number-1){
			if(this->nombre_lignes_cassees >= 10){
				this->currentGameLevel += 1;
				this->nombre_lignes_cassees = 0;			
			}
		}
		this->noyau.initialize();
		break;
/* -------------------------- */
/* --- Etat CHUTE_IMPOSEE --- */
/* -------------------------- */
	case Tetris :: CHUTE_IMPOSEE:
		this->noyau.synchronize(this->time_lap_chute_libre);
		this->piece_volante->get_positions_i(new_positions_i);
		this->piece_volante->get_positions_j(new_positions_j);
		for (i=0;i<4;i++){
			new_positions_j[i]--;
		}
		if (this->touche_plateau(new_positions_i,new_positions_j)){
			this->plateau->reception_piece(this->piece_volante);
			delete this->piece_volante;
			this->piece_volante=NULL; 
			this->state = Tetris :: MAJ_PLATEAU;	
	   }else {
			this->piece_volante->translate(0,-1);
			this->noyau.initialize();
		}
		break;
	}	
	return this->state;
}

/* ========================== */
/* === Fonction get_state === */
/* ========================== */
int Tetris :: get_state(){
	return this->state;
}



/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
Piece* Tetris :: creation(){
		int type_piece = tirage()+1;
		switch (type_piece){
		case 1 : 
			return new Piece1(1,2,3);
			break;
		case 2 : 
			return new Piece2(0,2,3);
			break;
		case 3 : 
			return new Piece3(0,2,3);
			break;
		case 4 : 
			return new Piece4(0,2,3);
			break;
		case 5 : 
			return new Piece5(0,3,3);
			break;
		case 6 : 
			return new Piece6(0,2,3);
			break;
		case 7 : 
			return new Piece7(0,3,3);
			break;

		default :
			std::cout << "Il gueule !! \n";
			exit(0);
		}
}

bool Tetris::position_libre(int* table_i,int* table_j){
	for(int i=0;i<4;i++){
		if(table_i[i]<0)return false; 
		if(table_i[i]>=horizontalCaseNumber)return false;
		if(table_j[i]<0)return false;
	}
	return this->plateau->position_libre(table_i,table_j);
}

bool Tetris::touche_plateau(int* table_i,int* table_j){
	for(int i=0;i<4;i++){
		if(table_j[i]==-1)return true;
	}
	for(int i=0;i<4;i++){
		if (!this->plateau->position_libre(table_i[i],table_j[i]))return true;
	}
	return false;
}

