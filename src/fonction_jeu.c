#include "fct_jeu.h"

void initJoueurs(joueur joueurs[],int nombreJoueurs){
    for(int i = 0;i < nombreJoueurs;i++){
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7; 
    }
}

void init_grille(tuile grille[NB_GRILLE][NB_GRILLE]){
    tuile p;
    p.centre = -1;
    for(int i = 0; i < 4;i++){
        p.cotes[i] = -1;
    }
    p.identifiant = -1;
    p.posee = -1;
    for (int i=0; i<143;++i){
        for (int j=0; j<143;++j){
                grille[i][j]=p;
            
        }
    }
    initTuileDepart(grille);
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

void initTuileDepart(tuile grille[NB_GRILLE][NB_GRILLE]){ // assigne la tuile de départ au plateau
    tuile t = define_tuiledepart();
    grille[0][0] = t;
}


