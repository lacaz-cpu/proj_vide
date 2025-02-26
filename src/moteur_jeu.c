#include "game_structures.h"
#include "fct_jeu.h"
#include "lecteur_csv.h"

int main(int argc, char * argv[])
{
    
    tuile t[NB_TUILES];
    parseur_csv("./src/tuiles_base_simplifiees.csv",&t);
    
    tuile grille[NB_GRILLE][NB_GRILLE];
    init_grille(grille);
    placement_tuile(71,72,grille,t[71]);
    printf("%d\n",grille[72][72].posee);
    //printf("%c",t[1].cotes[0]);
    
    return 0;
}
