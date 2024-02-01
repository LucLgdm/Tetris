/* ++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Plateau +++ */
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
/* --- M�thodes publiques standard --- */
/* ----------------------------------- */
      Plateau(int,int,double,double,double);
      ~Plateau();
		
/* -------------------------------------- */
/* --- M�thodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
		void draw();
		int destruction_descente_ligne(int, int*);
		bool position_libre(int*,int*);
		bool position_libre(int,int);
		void reception_piece(Piece*);
/* ====================== */
/* === Membres priv�s === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Donn�es priv�es --- */
/* ----------------------- */
		int nb_cases_verticale;
		int nb_cases_horizontale;
		double x_ref;
	   double y_ref;
		Brique*** brique ;
		double taille_brique;

/* ------------------------ */
/* --- M�thodes cach�es --- */
/* ------------------------ */
      inline Plateau(const Plateau&);
      inline Plateau& operator = (const Plateau&);

/* --------------------------------- */
/* --- M�thodes priv�es internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Plateau& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif
