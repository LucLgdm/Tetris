/* ++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Xxx +++ */
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
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Xxx();
      ~Xxx();

/* -------------------------------------- */
/* --- Méthodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;

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
      inline Xxx(const Xxx&);
      inline Xxx& operator = (const Xxx&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */

};

inline std::ostream& operator << (std::ostream& stream, const Xxx& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif