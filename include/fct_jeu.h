#ifndef FCT_JEU
#define FCT_JEU

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "game_structures.h"
#define MAX_PLATEAU 143
#define max_pos_possibles 432
#define mid 71
#define NORD 0 
#define EST 1 
#define SUD 2
#define OUEST 3


void initJoueurs(joueur *joueurs,int *nb_joueurs);

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y);

int placement_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile tl,int x,int y,int z,int w);

void parseur_csv(char * fname,tuile * Pile);

void afficher_pile(tuile * Pile);

void melange(tuile * Pile);

void partie(tuile grille[NB_GRILLE][NB_GRILLE], int *nb_joueurs,joueur *Joueurs,tuile *Pile);

tuile rotation_tuile(tuile t);

tuile piocher(tuile *pile,int nb_tour);

void poser_tuile(tuile Grille[NB_GRILLE][NB_GRILLE],tuile t, int *nb_tours, int nb_joueurs,joueur *Joueurs, int x,int y);

void poser_pion(tuile Grille[NB_GRILLE][NB_GRILLE], joueur *Joueurs, int nb_tours, int nb_joueurs, int x, int y);

void find_num(tuile *Pile,tuile *tile);

#endif // FCT_JEU