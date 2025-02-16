#include "game_structures.h"
#include "lecteur_csv.h"
#include "fct_jeu.h"
/*
int main(int argc, char * argv[])
{
    struct tuile_s t;
    parseur_csv();

    return 0;
}
*/

/////////////////////////////////////////////////////////////////////////////////////main
int main(){
    ////////////////////////////////////////////////////déclaration des joueurs
        int flag=0;
        while (flag==0){
            int n,ia,nb_participants=0;
            printf("Entrez le nombre de joueurs:\n");
            scanf("%d",n);
            printf("Entrez le nombre d'IA:\n");
            scanf("%d",ia);
            nb_participants=n+ia;
            if (nb_participants>=2){
                flag=1;
            }
            else{
                printf("Il n'y a pas assez de participants !");
            }
        }
    ////////////////////////////////////////créer joueurs
        struct joueur *liste_joueurs=malloc(sizeof(struct joueur)*nb_part(icipants));
        for(int i=0;i<nb_participants,++i){
            struct joueur new_player;
            new_player=creer_joueur();
            liste_joueurs[i]=new_player;
        }
    /////////////////////////////////////////charger tuiles et mélanger
        int plateau[143][143];
        char carcassonne[72];
        charger_tuiles(&carcassonne);
        plateau[83][83]=liste_tuiles[0];
        carcassonne=melange(&carcassonne);
    //////////////////////////////////////boucle de jeu
        int cpt_tuiles=72, tuile=1;
        while cpt_tuiles>0{
            trouver_placement(carcassonne[tuile],&tab);
            if ((tuile-1) %nb_joueurs<n){
                //aff_placements(tab);
                int flag=0;
                while (flag==0){
                    printf("Entrez les coordonnées x,y de placement:\n")
                    scanf("%d %d",x,y)
                    rep=check_placement( x,y,liste_possibles, taille)///////
                    if rep==1{
                        flag=1;
                    }
                    else{
                       printf("Saisissez une position valide!\n") 
                    }
                }
            }
            else{
                play_ia(tab,&plateau,carcassonne[tuile]);
            }
            evaluation();
            affichage(plateau);
            cpt_tuiles-=1;
            tuile+=1;
        }
        evaluation_finale();
        aff_score();
        free(liste_joueurs);
        return 0;
    }
