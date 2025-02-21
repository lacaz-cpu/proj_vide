#include "game_structures.h"
#define MAX_PLATEAU 143
#define max_pos_possibles 432


void initPlateau(Plateau *plateau);

tuile define_tuiledepart();

void initTuileDepart(Plateau *plateau);

void free_plateau(Plateau * plateau);

void initJoueurs(joueur joueurs[],int nombreJoueurs);