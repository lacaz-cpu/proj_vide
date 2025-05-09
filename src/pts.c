#include "pts.h"


int check_road(tuile grille[NB_GRILLE][NB_GRILLE],pion p,int x,int y){
    // regarde si la route sur lequel le pion est poser est finis
    int direction_road = NORD;
    if(grille[x][y].centre != 'r'){
        direction_road = p.pos;
    }
}


int check_abbaye(tuile grille[NB_GRILLE][NB_GRILLE],int x,int y){
    //check si l'abbaye est bien entourée de tuile et donne les points au pions situer au centre
    int check;
    for(int i = 0;i < 3;i++){
        for(int j = 0; j < 3;j++){
            check += grille[x-1+i][y-1+j].posee;
        }
    }
    if(check == 9)
        return 1;
    else 
        return 0;
}

int ville_pts(tuile grille[NB_GRILLE][NB_GRILLE],int x,int y){
    //vérifie si la ville est finie est si oui renvoie 1 sinon 0
    
}
