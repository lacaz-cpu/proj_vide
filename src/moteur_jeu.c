#include "game_structures.h"
#include "affichage.h"
#include "fct_jeu.h"



int main(int argc, char * argv[])
{
    
    tuile t[NB_TUILES];
    parseur_csv("./src/tuiles_base_simplifiees.csv",t);
    position position_possible[NB_TUILES];
    init_position(position_possible);
    printf("%d %d\n",position_possible[0].x,position_possible[0].y);
    //afficher_pile(t);
    melange(t);
    //afficher_pile(t);
    tuile grille[NB_GRILLE][NB_GRILLE];
    init_grille(grille);
    /*
    for(int i = 0; i < NB_GRILLE;i++){
        for(int j = 0; j < NB_GRILLE;j++){
            printf("%d",grille[i][j].posee);
        }
        printf("\n");
    }
    */
    affichage(grille);
    afficher_tuile(t[1]);
    t[1] = rotation_tuile(t[1]);
    afficher_tuile(t[1]);
    printf("%d \n",grille[71][71].posee);
    printf("%c\n",grille[71][71].cotes[0]);
    affiche_g();
    return 0;
}
