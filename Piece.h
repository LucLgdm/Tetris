/* ++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Piece +++ */
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
/* --- Méthodes publiques standard --- */
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
/* --- Méthodes publiques d'interface --- */
/* -------------------------------------- */
      virtual void selfDisplay(std::ostream&) const = 0;

/* ======================== */
/* === Membres protégés === */
/* ======================== */
   protected:

/* ------------------------- */
/* --- Données protégées --- */
/* ------------------------- */
		Brique* brique[4];
		int orientation;
		Brique* briqueref;

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
      inline Piece(const Piece&);
      inline Piece& operator = (const Piece&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Piece& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif
