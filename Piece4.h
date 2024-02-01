/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece4 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE4_HH
#define PIECE4_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece4 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Piece4(int, int, int);
      ~Piece4();

/* -------------------------------------- */
/* --- Méthodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
		int get_most_right_brique();
		int get_most_left_brique();
		void tourner(int);
		void get_positions_after_turn(int*,int*,int);
/* ====================== */
/* === Membres privés === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Données privées --- */
/* ----------------------- */

/* ------------------------ */
/* --- Méthodes cachées --- */
/* ------------------------ */
      inline Piece4(const Piece4&);
      inline Piece4& operator = (const Piece4&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
