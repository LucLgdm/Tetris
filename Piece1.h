/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece1 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE1_HH
#define PIECE1_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece1 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Piece1(int, int, int);
      ~Piece1();

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
      inline Piece1(const Piece1&);
      inline Piece1& operator = (const Piece1&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
