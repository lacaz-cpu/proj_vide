#include "game_structures.h"
#define MAX_PLATEAU 143
#define max_pos_possibles 432
#define mid 71
#define NORD 0 
#define EST 1 
#define SUD 2
#define OUEST 3


void initJoueurs(joueur *joueurs,int *nb_joueurs);

void initTuileDepart(tuile grille[NB_GRILLE][NB_GRILLE]);

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y);

void init_grille(tuile grille[NB_GRILLE][NB_GRILLE]);

int placement_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile tl,int x,int y,int z,int w);

void parseur_csv(char * fname,tuile * Pile);

void afficher_pile(tuile * Pile);

void melange(tuile * Pile);

void init_position(position tab[NB_TUILES]);

void partie(tuile grille[NB_GRILLE][NB_GRILLE], int *nb_joueurs,joueur *Joueurs);

tuile rotation_tuile(tuile t);

tuile piocher(tuile *pile,int nb_tour);

void poser_tuile(tuile Grille[NB_GRILLE][NB_GRILLE],tuile t, int *nb_tours, int nb_joueurs,joueur *Joueurs, int x,int y);

void poser_pion(tuile Grille[NB_GRILLE][NB_GRILLE], joueur *Joueurs, int nb_tours, int nb_joueurs, int x, int y);