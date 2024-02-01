/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece2 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE2_HH
#define PIECE2_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece2 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:


/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Piece2(int, int, int);
      ~Piece2();

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
      inline Piece2(const Piece2&);
      inline Piece2& operator = (const Piece2&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
