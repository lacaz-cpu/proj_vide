#ifndef GAME_STRUCTURES
#define GAME_STRUCTURES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NB_TUILES 72
#define NB_GRILLE 143

typedef struct{
    int id,pos;
}pion;

typedef struct{
    int id;
    int pion;
    int score;
    int ia;
    int pionsjouer;
}joueur;

typedef struct{
    int identifiant;
    char cotes[4];
    char centre;
    pion pions;
    int posee;
    int posable; 
}tuile;

typedef struct{
    int x,y;
}position;

#endif // GAME_STRUCTURES
