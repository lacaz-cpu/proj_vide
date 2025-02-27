#include "game_structures.h"
#include "fct_jeu.h"

int main(int argc, char * argv[])
{
    
    tuile t[NB_TUILES];
    parseur_csv("./src/tuiles_base_simplifiees.csv",t);
    //afficher_pile(t);
    melange(t);
    afficher_pile(t);
    /*
    tuile grille[NB_GRILLE][NB_GRILLE];
    init_grille(grille);
    placement_tuile(71,72,grille,t[0]);
    printf("%d\n",grille[71][72].posee);
    */
    //printf("%c",t[1].cotes[0]);
    
    return 0;
}
