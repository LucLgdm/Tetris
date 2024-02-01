#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include <stdlib.h>
#include <time.h> 

#include "Brique.h"
#include "Tetris.h"

/* ++++++++++++++++++++++++++ */
/* +++ Variables globales +++ */
/* ++++++++++++++++++++++++++ */
GLenum  errCodeOpenGL;               // Code erreur OpenGL
int     width;                       // Largeur de la fenêtre graphique
int     height;                      // Hauteur de la fenêtre graphique
Tetris* tetris;
int etat;
int action;


/* +++++++++++++++++++++++++++ */
/* +++ Fonction principale +++ */
/* +++++++++++++++++++++++++++ */
int main(){

/* ===================================== */
/* === Paramètres de rendu graphique === */
/* ===================================== */
      width = 1000;
      height = 1000;

/* ========================== */
/* === Initialisation SDL === */
/* ========================== */
    	SDL_Surface* ecran;
      SDL_Init(SDL_INIT_VIDEO);
    	TTF_Init();
      SDL_WM_SetCaption("Tetris",NULL);
      ecran = SDL_SetVideoMode(width,height,32,SDL_OPENGL | SDL_DOUBLEBUF | SDL_HWSURFACE);
      SDL_EnableKeyRepeat(100,10);
    	SDL_Color couleur = {0.4, 0.4, 0.4};
		TTF_Font* police = TTF_OpenFont("solid_3d.ttf", 65);
		char texte_level[11] = "level =   ";
		char texte_score[20] = "score =   ";
		char texte_time[20] = "time =   "  ;
    	SDL_Surface* texte1;
    	SDL_Surface* texte2;
    	SDL_Surface* texte3;
		SDL_Rect position1, position2, position3;
		position1.x = 500;
		position1.y = 210;

		position2.x = 500;
		position2.y = 200;

		position3.x = 500;
		position3.y = 150;
		

/* ============================================================ */
/* === Spécification de la couleur de vidage (fond d'écran) === */
/* ============================================================ */
      glClearColor(0.0,0.0,0.0,1.0);

/* ============================= */
/* === Construction du Monde === */
/* ============================= */
		tetris = new Tetris(22,10);
		etat = tetris->get_state();
		std::cout << *tetris;
		srand(time(NULL));

/* ==================================== */
/* === Transformation de projection === */
/* ==================================== */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D((GLdouble)0.0,(GLdouble)20.0,(GLdouble)0.0,(GLdouble)24.0);
   
/* ==================================================== */
/* === Transformation de modélisation/visualisation === */
/* ==================================================== */
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

/* ====================================== */
/* === Activation des fonctionnalités === */
/* ====================================== */
      glEnable(GL_DEPTH_TEST);

/* =========================== */
/* === Rectangle de dessin === */
/* =========================== */
      glViewport(0,0,(GLsizei)width,(GLsizei)height);

/* ========================== */
/* === Boucle d'affichage === */
/* ========================== */
      while (true){
      
/* ------------------------------ */
/* --- Gestion des évènements --- */
/* ------------------------------ */
            SDL_Event event;
				action = Tetris :: STAND_BY;
            while (SDL_PollEvent(&event)){
                  switch (event.type){
                  case SDL_QUIT: // ferme la fenetre
								delete tetris;
                        exit(1);
                  case SDL_KEYDOWN:
                        switch (event.key.keysym.sym){
                        case SDLK_ESCAPE:
									delete tetris;
                           exit(1);
                  		case SDLK_LEFT: /* décale à gauche*/
									if(etat == Tetris :: PIECE_VOLANTE) action = Tetris :: MOVE_GAUCHE;
									break;
                  		case SDLK_RIGHT: /* décale à droite*/
									if(etat == Tetris :: PIECE_VOLANTE) action = Tetris :: MOVE_DROITE;
									break;
                  		case SDLK_SPACE: /* Accelère la descente */
									if(etat == Tetris :: PIECE_VOLANTE) action = Tetris :: FULL_SPEED;
									break;
                  		case SDLK_q: /* Tourne la pièce à gauche */
									if(etat == Tetris :: PIECE_VOLANTE) action = Tetris :: TURN_GAUCHE;
									break;
                  		case SDLK_d: /* Tourne la piece à droite */
									if(etat == Tetris :: PIECE_VOLANTE) action = Tetris :: TURN_DROITE;
									break;
                  			
                        }
                  }
            }

/* --------------- */
/* ---  Simul  --- */
/* --------------- */
				etat = tetris->simul(action);
		
/* -------------- */
/* --- Dessin --- */
/* -------------- */
				tetris->draw();

/* ------------------------------- */
/* --- Dessin des infos utiles --- */
/* ------------------------------- */
				int level = tetris->get_level();
				sprintf( &(texte_level[8]), "%d", level );
				int score = tetris->get_score();
				sprintf( &(texte_score[8]), "%d", score );
				int time = tetris->get_time();
				sprintf( &(texte_time[8]), "%d", time );

				texte1 = TTF_RenderText_Blended(police, texte_level, couleur);
				texte2 = TTF_RenderText_Blended(police, texte_score, couleur);
				texte3 = TTF_RenderText_Blended(police, texte_time, couleur);

     			SDL_BlitSurface(texte1, NULL, ecran, &position1);     /* Blit du texte */
   	   	SDL_BlitSurface(texte2, NULL, ecran, &position2);     /* Blit du texte */
      		SDL_BlitSurface(texte3, NULL, ecran, &position3);     /* Blit du texte */

			   SDL_Flip(ecran);

	
/* ------------------------------------------- */
/* --- Il y a-t-il eu des erreurs OpenGL ? --- */
/* ------------------------------------------- */
            if ((errCodeOpenGL = glGetError()) != GL_NO_ERROR){
                  std::cerr << "ERROR: Problème lors du rendu visuel OpenGL : " << (char*)gluErrorString(errCodeOpenGL) << std::endl;
                  exit(0);
            }

/* ----------------------------------- */
/* --- Réclenchement du traitement --- */
/* ----------------------------------- */
            glFlush();
            SDL_GL_SwapBuffers();

      }

/* ======================== */
/* === Fin du programme === */
/* ======================== */
      return 1;
}
