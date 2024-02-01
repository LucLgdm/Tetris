/* ++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Plateau +++ */
/* ++++++++++++++++++++++++++++++++++++ */

#ifndef PLATEAU_HH
#define PLATEAU_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Brique.h"
#include "Piece.h" 

class Plateau {

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Plateau(int,int,double,double,double);
      ~Plateau();
		
/* -------------------------------------- */
/* --- Méthodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
		void draw();
		int destruction_descente_ligne(int, int*);
		bool position_libre(int*,int*);
		bool position_libre(int,int);
		void reception_piece(Piece*);
/* ====================== */
/* === Membres privés === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Données privées --- */
/* ----------------------- */
		int nb_cases_verticale;
		int nb_cases_horizontale;
		double x_ref;
	   double y_ref;
		Brique*** brique ;
		double taille_brique;

/* ------------------------ */
/* --- Méthodes cachées --- */
/* ------------------------ */
      inline Plateau(const Plateau&);
      inline Plateau& operator = (const Plateau&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Plateau& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif
