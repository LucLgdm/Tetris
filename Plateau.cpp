/* +++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Plateau +++ */
/* +++++++++++++++++++++++++++++++++++ */

#include "Plateau.h"

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Plateau::Plateau(int nb_cases_verticale, int nb_cases_horizontale,double x_ref, double y_ref,double taille_brique){
	this->brique = NULL ;
  	this->nb_cases_verticale = nb_cases_verticale;
	this->nb_cases_horizontale = nb_cases_horizontale;
	this->x_ref = x_ref;
	this->y_ref = y_ref;
	this->taille_brique=taille_brique;
	this->brique=new Brique** [nb_cases_horizontale];
	for (int i=0 ; i<nb_cases_horizontale ; i++){
		this->brique[i]=new Brique*[nb_cases_verticale];
		for (int j=0; j<nb_cases_verticale; j++){
			this-> brique [i][j]=NULL;
		}
	}
}

/* =================== */
/* === Destructeur === */
/* =================== */
Plateau::~Plateau(){
   if (this-> brique != NULL){
		for (int i=0 ; i<nb_cases_horizontale ; i++){
			for (int j=0 ; j<nb_cases_verticale ; j++){
				delete this->brique[i][j];
			}
			delete this->brique[i];
		}
		delete this-> brique ;
	}
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Plateau::selfDisplay(std::ostream& stream) const {
	for (int j=nb_cases_verticale-1 ; j>=0 ; j--){
			for (int i=0 ; i<nb_cases_horizontale ; i++){
				if (this->brique[i][j]==NULL)stream <<0;
				else stream <<1;
			}stream<<"\n";
	}
}

/* ===================== */
/* === Fonction draw === */
/* ===================== */
void Plateau::draw(){
	for (int i=0 ; i<this->nb_cases_horizontale ; i++){
		for (int j=0 ; j<this->nb_cases_verticale ; j++){
			if (this->brique[i][j] != NULL){
				this->brique[i][j]->draw(this->taille_brique, x_ref,y_ref) ;
			} 
		}
	}
}

/* =========================================== */
/* === Fonction destruction_descente_ligne === */
/* =========================================== */


int Plateau :: destruction_descente_ligne(int currentGameLevel, int* score){
	int compteur = 0;
	for(int j = 0; j<this->nb_cases_verticale; j++){
		bool fini = true;
		bool ligne_pleine  = true;
		for(int i = 0; i<this->nb_cases_horizontale; i++){
			if(this->brique [i][j] != NULL){
				fini = false;
			}else{
				ligne_pleine = false;
			}
		}
		if(ligne_pleine){
			compteur ++;	
			for(int i = 0; i<this->nb_cases_horizontale; i++){
				delete this->brique[i][j];
			}
			for(int k = j; k<this->nb_cases_verticale-1; k++){
				for(int i = 0; i<this->nb_cases_horizontale; i++){
					this->brique[i][k] = this->brique[i][k+1];
					if (this->brique[i][k] != NULL)	this->brique[i][k]->translate(0,-1);
				}
			}
			for(int i = 0; i<this->nb_cases_horizontale; i++){
				this->brique[i][this->nb_cases_verticale-1] = NULL;
			}
			j--;
		}
		if(fini) break;
	}
	if(compteur == 1){
		*score += currentGameLevel+1;
	}
	if(compteur == 2){
		*score += 3*(currentGameLevel+1);
	}
	if(compteur == 3){
		*score += 7*(currentGameLevel+1);
	}
	if(compteur == 4){
		*score += 15*(currentGameLevel+1);
	}
	return compteur;
}


bool Plateau::position_libre(int* table_i,int* table_j){
	for(int i=0;i<4;i++){
		if(this->brique[table_i[i]][table_j[i]]!=NULL)return false; 
	}
	return true; 
}

bool Plateau::position_libre(int i,int j){
	if(this->brique[i][j]!=NULL)return false; 
	return true; 
}


void Plateau::reception_piece(Piece* piece){
	for (int i=0;i<4;i++){
		Brique* b=piece->get_brique(i);
		this->brique[b->get_position_i()][b->get_position_j()] = b;
	}
}


/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
