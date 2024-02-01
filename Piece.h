/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Piece +++ */
/* ++++++++++++++++++++++++++++++++++++++ */

#ifndef PIECE_HH
#define PIECE_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Brique.h"

class Piece {

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:
		static const int TURN_RIGHT;
		static const int TURN_LEFT;
/* ----------------------------------- */
/* --- M�thodes publiques standard --- */
/* ----------------------------------- */
      Piece(int);
      virtual ~Piece();
		virtual void tourner(int)=0;
      //void deplace(int);
      //void descendre();
		void get_positions_i(int*);
		void get_positions_j(int*);
		virtual void get_positions_after_turn(int*,int*,int)=0;
		void cirage(double*, double*, double*);
		void draw(double, double, double);
		void translate(int, int);
		virtual int get_most_right_brique() = 0;
		virtual int get_most_left_brique() = 0;
		Brique* get_brique(int);

/* -------------------------------------- */
/* --- M�thodes publiques d'interface --- */
/* -------------------------------------- */
      virtual void selfDisplay(std::ostream&) const = 0;

/* ======================== */
/* === Membres prot�g�s === */
/* ======================== */
   protected:

/* ------------------------- */
/* --- Donn�es prot�g�es --- */
/* ------------------------- */
		Brique* brique[4];
		int orientation;
		Brique* briqueref;

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
      inline Piece(const Piece&);
      inline Piece& operator = (const Piece&);

/* --------------------------------- */
/* --- M�thodes priv�es internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Piece& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif
