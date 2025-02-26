#include "fct_jeu.h"

void initJoueurs(joueur joueurs[],int nombreJoueurs){
    for(int i = 0;i < nombreJoueurs;i++){
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7; 

        printf("coucou");
    }
}

void init_plateau(struct piece plateau[MAX_PLATEAU][MAX_PLATEAU]){
    struct piece p;
    p.n=-1;
    p.s=-1;
    p.e=-1;
    p.o=-1;
    p.c=-1;
    p.type_pion=0;
    p.evaluation=0;
    for (int i=0; i<143;++i){
        for (int j=0; j<143;++j){
                plateau[i][j]=p;
            
        }
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


