#include "game_structures.h"
#include "affichage.h"
#include "fct_jeu.h"



int main(int argc, char * argv[])
{
    
    tuile t[NB_TUILES];
    parseur_csv("./src/tuiles_base_simplifiees.csv",t);
    tuile grille[NB_GRILLE][NB_GRILLE];
    int nb_joueur;
    joueur Joueurs[5];
    partie(grille,&nb_joueur,Joueurs);
    melange(t);
    afficher_tuile(grille[mid][mid]);
    int r = 1,x,y;
    while(r != 0){
        tuile tl = piocher(t,0);
        placement_tuile(grille,tl,71,71,73,73);
        poser_tuile(grille,tl,1,nb_joueur,Joueurs,x,y);
    }
    return 0;
}
