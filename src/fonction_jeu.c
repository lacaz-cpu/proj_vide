#include "game_structures.h"

void initJoueurs(joueur joueurs[],int nombreJoueurs){
    for(int i = 0;i < nombreJoueurs;i++){
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7; 
    }
}


void initPlateau(Plateau *plateau){
    for(int i = 0; i < NB_TUILES;i++){
        
    }
}
