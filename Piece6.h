/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece6 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE6_HH
#define PIECE6_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece6 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Piece6(int, int, int);
      ~Piece6();

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
      inline Piece6(const Piece6&);
      inline Piece6& operator = (const Piece6&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
