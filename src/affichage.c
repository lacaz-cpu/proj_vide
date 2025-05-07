#include "affichage.h"


void affichage(tuile grille[NB_GRILLE][NB_GRILLE]){
    for(int i = 0;i < NB_GRILLE ; i++){
        for(int j = 0; j < NB_GRILLE;j++){
            if(grille[i][j].posee ==1){
                printf("\n");
                printf("-----------\n");
                printf("|    %c    |\n", grille[i][j].cotes[0]);
                printf("| %c  %c  %c |\n", grille[i][j].cotes[3], grille[i][j].centre, grille[i][j].cotes[1]);
                printf("|    %c    |\n", grille[i][j].cotes[2]);
                printf("-----------\n\n");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}