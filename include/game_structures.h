#ifndef GAME_STRUCTURES
#define GAME_STRUCTURES
#include <string.h>
#include "lecteur_csv.h"

#define NB_TUILES 72

typedef struct{
    int id;
    int pion;
    int score;
}joueur;


typedef struct{
    int x,y;
}position;

typedef struct{
    int identifiant;
    char cotes[4];
    char centre;
    position pos;
}tuile;

#endif // GAME_STRUCTURES
