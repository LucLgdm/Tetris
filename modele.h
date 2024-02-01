/* ++++++++++++++++++++++++++++++++++++ */
/* +++ D�claration de la classe Xxx +++ */
/* ++++++++++++++++++++++++++++++++++++ */

#ifndef XXX_HH
#define XXX_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Xxx {

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:

/* ----------------------------------- */
/* --- M�thodes publiques standard --- */
/* ----------------------------------- */
      Xxx();
      ~Xxx();

/* -------------------------------------- */
/* --- M�thodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;

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
      inline Xxx(const Xxx&);
      inline Xxx& operator = (const Xxx&);

/* --------------------------------- */
/* --- M�thodes priv�es internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Xxx& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif