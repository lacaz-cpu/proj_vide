#ifndef GAME_STRUCTURES
#define GAME_STRUCTURES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NB_TUILES 72

typedef struct{
    int id;
    int pion;
    int score;
}joueur;

typedef struct{
    int identifiant;
    char cotes[4];
    char centre;
    int posee;
}tuile;

typedef struct{
    tuile **plateau;
}Plateau;

#endif // GAME_STRUCTURES
