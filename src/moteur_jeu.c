#include "game_structures.h"
#include "lecteur_csv.h"


int main(int argc, char * argv[])
{
    tuile t[NB_TUILES];
    parseur_csv("/home/lacaz/Bureau/proj_vide/src/tuiles_base_simplifiees.csv",&t);
    printf("%c",t[1].cotes[0]);
    return 0;
}
