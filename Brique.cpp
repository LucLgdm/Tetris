/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Définition de la classe Brique +++ */
/* ++++++++++++++++++++++++++++++++++++++ */
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Brique.h"

/////////////////////////////////////////////////////////////////////////////
///                      Méthodes publiques standard                      ///
/////////////////////////////////////////////////////////////////////////////

/* ==================== */
/* === Constructeur === */
/* ==================== */
Brique::Brique(double rouge, double vert, double bleu, int i, int j){
	this->red = rouge;
	this->green = vert;
	this->blue = bleu;
	this->position_i = i;
	this->position_j = j;
	}

/* =================== */
/* === Destructeur === */
/* =================== */
Brique::~Brique(){
}

/////////////////////////////////////////////////////////////////////////////
///                    Méthodes publiques d'interfaces                    ///
/////////////////////////////////////////////////////////////////////////////

/* ============================ */
/* === Fonction selfDisplay === */
/* ============================ */
void Brique::selfDisplay(std::ostream& stream) const {
/*	stream << "Brique\n";
	stream << "  -> couleur = ( " << this->red << " , " << this->green << " , " << this->blue << " )\n";
	stream << "  -> position = ( " << this->position_i << " , " << this->position_j << " )\n";*/
	stream << "Brique, position = ( " << this->position_i << " , " << this->position_j << " )\n";
}

/* ===================== */
/* === Fonction draw === */
/* ===================== */
void Brique::draw(double taille, double xref, double yref){
	double dx = 0.05*taille;
   double x = xref + taille * this->position_i;
   double y = yref + taille * this->position_j;
	glBegin(GL_QUADS);
   	glColor3d(this->red, this->green, this->blue); 
      glVertex2d( x + dx          , y + dx          );
      glVertex2d( x + taille - dx , y + dx          );
      glVertex2d( x + taille - dx , y + taille - dx );
      glVertex2d( x + dx          , y + taille - dx );
   glEnd();
}

/* ========================== */
/* === Fonction translate === */
/* ========================== */
void Brique :: translate(int di, int dj){
	this->position_i += di;
	this->position_j += dj;
}

int Brique::get_position_i(){
	return this->position_i;
}

int Brique::get_position_j(){
	return this->position_j;
}

void Brique::set_position_i(int nouveau_i){
	this->position_i=nouveau_i;
}

void Brique::set_position_j(int nouveau_j){
	this->position_j=nouveau_j;
}

/////////////////////////////////////////////////////////////////////////////
///                       Méthodes privées internes                       ///
/////////////////////////////////////////////////////////////////////////////
