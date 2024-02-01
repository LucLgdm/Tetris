/* ++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Xxx +++ */
/* ++++++++++++++++++++++++++++++++++++ */

#ifndef BRIQUE_HH
#define BRIQUE_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Brique {

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- M�thodes publiques standard --- */
/* ----------------------------------- */
      Brique(double,double,double,int,int);
      ~Brique();

/* -------------------------------------- */
/* --- M�thodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
		void draw(double,double,double);
		void translate(int, int);
		int get_position_i();
		int get_position_j();
	   void set_position_i(int);
		void set_position_j(int);

/* ====================== */
/* === Membres priv�s === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Donn�es priv�es --- */
/* ----------------------- */
		double red,green,blue;
		int position_i;
		int position_j;
		
/* ------------------------ */
/* --- M�thodes cach�es --- */
/* ------------------------ */
      inline Brique(const Brique&);
      inline Brique& operator = (const Brique&);

/* --------------------------------- */
/* --- M�thodes priv�es internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Brique& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif
