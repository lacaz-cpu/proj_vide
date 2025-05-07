#include "game_structures.h"
#include "affichage.h"
#include "fct_jeu.h"



int main(int argc, char * argv[])
{
    
    tuile t[NB_TUILES];
    parseur_csv("./src/tuiles_base_simplifiees.csv",t);
    tuile grille[NB_GRILLE][NB_GRILLE];
    int nb_joueur, nb_ia;
    joueur Joueurs[5];
    partie(grille,&nb_joueur,&nb_ia,Joueurs);
    melange(t);
    affichage(grille);
    tuile tr = piocher(t,0);
    afficher_tuile(tr);
    printf("%d",placement_tuile(grille,tr,71,71,71,71));
    if(placement_tuile(grille,tr,71,71,71,71) > 0){
        int x,y;
        printf("entrez les coordonnée");
        scanf("%d %d",&x,&y);
        placer_tuile(grille,tr,x,y);
        affichage(grille);
    }
    return 0;
}
