#ifndef FCT_JEU
#define FCT_JEU
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define max_pos_possibles 432 //car ((71*2)+2)*3 car 71 tuiles posées au maximum ayandeux côtés+2 côtés des bouts multipliés par 3 car format x,y,z


struct joueur{
    int score;
    int pions;

};

struct piece{
    int evaluation;
    int n;
    int s;
    int e;
    int o;
    int c;
    int type_pion; //0 rien, nombre c'est le numéro du joueur
    //nord sud est ouest //1,2,3,4,5,6 pour chaque type de tuile (route,ville/blason,pre,abbaye,village)
};

struct joueur creer_joueur(){
    struct joueur j;
    j.score=0;
    j.pions=7;
    return j;
}

#endif // FCT_JEU