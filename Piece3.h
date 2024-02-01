/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece3 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE3_HH
#define PIECE3_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece3 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Piece3(int, int, int);
      ~Piece3();

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
      inline Piece3(const Piece3&);
      inline Piece3& operator = (const Piece3&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
