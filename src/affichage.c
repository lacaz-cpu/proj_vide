#include "affichage.h"

void affiche_g(){
    printf("           |>>>                    |>>>\n");
    printf("           |                        |\n");
    printf("       _  _|_  _                _  _|_  _\n");
    printf("      | |_| |_| |              | |_| |_| |\n");
    printf("      \\  .      /              \\ .    .  /\n");
    printf("       \\_______/                \\_______/\n");
    printf("        |     |      ____        |     |\n");
    printf("        |     |     |    |       |     |\n");
    printf("        |     |     |[]  |       |     |\n");
    printf("        |     |     |    |       |     |\n");
    printf("       /|##!##|\\   /|##!##|\\     /|##!##|\\\n");
    printf("      / |##!##| \\ / |##!##| \\   / |##!##| \\\n");
    printf("     |  |##!##|  |  |##!##|  | |  |##!##|  |\n");
    printf("     |  |##!##|  |  |##!##|  | |  |##!##|  |\n");
    printf("     |  |##!##|  |  |##!##|  | |  |##!##|  |\n");
    printf("     |  |##!##|  |  |##!##|  | |  |##!##|  |\n");
    printf("     |  |##!##|  |  |##!##|  | |  |##!##|  |\n");
    printf("    /___|_____|__\\_|_____|__/___|_____|__\\\n");
    
}

void affichage(tuile grille[NB_GRILLE][NB_GRILLE]){
    for(int i = 0;i < NB_GRILLE ; i++){
        for(int j = 0; j < NB_GRILLE;j++){
            if(grille[i][j].posee == 1){
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


void afficher_tuile(tuile tuile){
    printf("-----------\n");
    printf("|    %c    |\n", tuile.cotes[0]);
    printf("| %c  %c  %c |\n", tuile.cotes[3], tuile.centre, tuile.cotes[1]);
    printf("|    %c    |\n", tuile.cotes[2]);
    printf("-----------\n\n");
}
