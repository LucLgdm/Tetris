/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece5 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE5_HH
#define PIECE5_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece5 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Piece5(int, int, int);
      ~Piece5();

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
      inline Piece5(const Piece5&);
      inline Piece5& operator = (const Piece5&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
