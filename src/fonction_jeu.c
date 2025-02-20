#include "fct_jeu.h"

void initJoueurs(joueur joueurs[],int nombreJoueurs){
    for(int i = 0;i < nombreJoueurs;i++){
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7; 
    }
}


void initPlateau(Plateau *plateau){
    Plateau * plateau = (Plateau*)malloc(sizeof(Plateau));
    plateau->plateau = (tuile**)malloc(NB_TUILES*sizeof(tuile*));
    for(int i = 0; i < NB_TUILES;i++){
        plateau->plateau[i] = (tuile*)malloc(NB_TUILES*sizeof(tuile));
    }
}

void free_plateau(Plateau * plateau){
    for(int i = 0; i < NB_TUILES;i++)
        free(plateau->plateau[i]);
    free(plateau->plateau);
    free(plateau);
}

tuile define_tuiledepart(){ // creer la tuile de départ 
    tuile tuile;
    tuile.centre = 'r';
    tuile.cotes[0] = 'v';
    tuile.cotes[0] = 'r';
    tuile.cotes[0] = 'p';
    tuile.cotes[0] = 'r';
    tuile.posee = 1;
    return tuile;
}

void initTuileDepart(Plateau *plateau){ // assigne la tuile de départ au plateau
    tuile t = define_tuiledepart();
    plateau->plateau[0][0] = t;
}


