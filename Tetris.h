/* +++++++++++++++++++++++++++++++++++++++ */
/* +++ Déclaration de la classe Tetris +++ */
/* +++++++++++++++++++++++++++++++++++++++ */

#ifndef TETRIS_HH
#define TETRIS_HH

/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Plateau.h"
#include "Piece.h"
#include "kernelsy.h"

class Tetris {

/* ======================= */
/* === Membres publics === */
/* ======================= */
   public:
/* ------------------------- */
/* --- Données publiques --- */
/* ------------------------- */
		static const int PIECE_VOLANTE;
		static const int MAJ_PLATEAU;
		static const int CHUTE_IMPOSEE; 
		static const int MOVE_DROITE; 
		static const int MOVE_GAUCHE;
		static const int TURN_DROITE;
		static const int TURN_GAUCHE;
		static const int FULL_SPEED;
		static const int STAND_BY;

/* ----------------------------------- */
/* --- Méthodes publiques standard --- */
/* ----------------------------------- */
      Tetris(int,int);
      ~Tetris();

/* -------------------------------------- */
/* --- Méthodes publiques d'interface --- */
/* -------------------------------------- */
      void selfDisplay(std::ostream&) const;
		void draw();
		int simul(int); 								// Renvoie l'etat dans lequel se trouve le jeu
		int get_state();
		bool touche_plateau(int*,int*);
		int get_score();
		int get_level();
		int get_time();


/* ====================== */
/* === Membres privés === */
/* ====================== */
   private:

/* ----------------------- */
/* --- Données privées --- */
/* ----------------------- */
      int currentGameLevel;                // Niveau courant du jeu
      int verticalCaseNumber;              // Nombre de cases dans la direction verticale
      int horizontalCaseNumber;            // Nombre de cases dans la direction horizontale
		int score;									// Se passe de commentaires...
      Plateau* plateau;                    // Le plateau
		int level_number;							// Nombre de niveau dans le jeu
		int* time_lap;								// Tableau d'intervalle de temps suivant le niveau en millisec
		int first_level_time_lap;				// Pas de temps du premier niveau
		int state;									// Etat dans lequel se trouve le jeu
      int time_lap_chute_libre;				// Pas de temps de la chute 
		Piece* piece_volante;
		Piece* piece_suivante;
		KernelSynchronizer noyau;
		struct timeb      initialTime;      // Heure physique au debut du jeu
		int nombre_lignes_cassees;				

/* ------------------------ */
/* --- Méthodes cachées --- */
/* ------------------------ */
      inline Tetris(const Tetris&);
      inline Tetris& operator = (const Tetris&);

/* --------------------------------- */
/* --- Méthodes privées internes --- */
/* --------------------------------- */
		Piece* creation();
		bool position_libre(int*,int*);
};

inline std::ostream& operator << (std::ostream& stream, const Tetris& objet){
   objet.selfDisplay(stream);
   return stream;
}

/////////////////////////////////////////////////////////////////////////////

#endif
