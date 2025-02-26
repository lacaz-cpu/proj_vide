#include "game_structures.h"
#define MAX_PLATEAU 143
#define max_pos_possibles 432
#define mid 71
#define NORD 0 
#define EST 1 
#define SUD 2
#define OUEST 3


void initJoueurs(joueur joueurs[],int nombreJoueurs);

void init_grille(tuile grille[NB_GRILLE][NB_GRILLE]);

tuile define_tuiledepart();

void initTuileDepart(tuile grille[NB_GRILLE][NB_GRILLE]);

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y);

void placement_tuile(int x,int y,tuile grille[NB_GRILLE][NB_GRILLE],tuile tl);