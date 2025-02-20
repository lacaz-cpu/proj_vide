#include "game_structures.h"
#include "fct_jeu.h"
#include "lecteur_csv.h"

int main(int argc, char * argv[])
{
    tuile t[NB_TUILES];
    parseur_csv("/home/lacaz/Bureau/proj_vide/src/tuiles_base_simplifiees.csv",&t);
    Plateau * plateau = initPlateau(plateau);
    initTuileDepart(plateau);
    printf("%d\n",plateau->plateau[0][0].posee);
    printf("%c",t[1].cotes[0]);
    return 0;
}
