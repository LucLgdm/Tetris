/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Piece7 +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE7_HH
#define PIECE7_HH

/////////////////////////////////////////////////////////////////////////////

#include "Piece.h"

class Piece7 : public Piece{

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- M�thodes publiques standard --- */
/* ----------------------------------- */
      Piece7(int, int, int);
      ~Piece7();

/* -------------------------------------- */
/* --- M�thodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
		int get_most_right_brique();
		int get_most_left_brique();
		void tourner(int);
		void get_positions_after_turn(int*,int*,int);
/* ====================== */
/* === Membres priv�s === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Donn�es priv�es --- */
/* ----------------------- */

/* ------------------------ */
/* --- M�thodes cach�es --- */
/* ------------------------ */
      inline Piece7(const Piece7&);
      inline Piece7& operator = (const Piece7&);

/* --------------------------------- */
/* --- M�thodes priv�es internes --- */
/* --------------------------------- */

};


/////////////////////////////////////////////////////////////////////////////

#endif
