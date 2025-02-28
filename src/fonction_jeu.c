#include "fct_jeu.h"


void initJoueurs(joueur joueurs[],int nombreJoueurs){
    for(int i = 0;i < nombreJoueurs;i++){
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7; 
    }
}

void init_grille(tuile grille[NB_GRILLE][NB_GRILLE]){
    tuile p;
    p.centre = -1;
    for(int i = 0; i < 4;i++){
        p.cotes[i] = -1;
    }
    p.identifiant = -1;
    p.posee = 0;
    for (int i=0; i<143;++i){
        for (int j=0; j<143;++j){
                grille[i][j]=p;
            
        }
    }
    initTuileDepart(grille);
}

tuile define_tuiledepart(){ // creer la tuile de départ 
    tuile tuile;
    tuile.centre = 'r';
    tuile.cotes[0] = 'v';
    tuile.cotes[0] = 'r';
    tuile.cotes[0] = 'p';
    tuile.cotes[0] = 'r';
    tuile.posee = 1;
    return tuile;
}

void initTuileDepart(tuile grille[NB_GRILLE][NB_GRILLE]){ // assigne la tuile de départ au grille
    tuile t = define_tuiledepart();
    grille[mid][mid] = t;
}

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y){
    grille[x][y] = t;
    grille[x][y].posee = 1;
}

void placement_tuile(int x,int y,tuile grille[NB_GRILLE][NB_GRILLE],tuile tl){ // vérifie si la tuile peut etre placer 
    int nb = 0; // a vérifier car fonctionnement pas sur
    if(grille[x][y].posee == 0){
        if(grille[x-1][y].posee == 0 || grille[x-1][y].cotes[EST] == tl.cotes[OUEST])
            nb ++;
        if(grille[x+1][y].posee == 0 || grille[x+1][y].cotes[OUEST] == tl.cotes[EST])
            nb ++;
        if(grille[x][y-1].posee == 0 || grille[x][y-1].cotes[NORD] == tl.cotes[SUD])
            nb ++;
        if(grille[x][y+1].posee == 0 || grille[x][y+1].cotes[SUD] == tl.cotes[NORD])
            nb ++;
    }
    if(nb == 4)
        placer_tuile(grille,tl,x,y);
}
/*
int *positions_possibles(tuile grille[NB_GRILLE][NB_GRILLE],tuile piece_a_poser,int *curseur,int nb_pieces_deja_posees){//curseur est un simple entier, nb_deja_posees=72-cpt tuiles du main
    int *liste_positions_possibles=(int*)malloc(max_pos_possibles*sizeof(int));
    int rotation;
    int piece[4];
    piece[0]=piece_a_poser.n;
    piece[1]=piece_a_poser.e;
    piece[2]=piece_a_poser.s;
    piece[3]=piece_a_poser.o;
    for (int y=0; y<143;++y){
        for (int x=0; x<143;++x){
            if (grille[y][x].c==-1){
                //////////////////////////////////////////////////////
                if(y<1 || y==142 || x==0 || x==142){
                    //algo bordure
                    //côtés
                    int autour [4]={255,255,255,255};
                    if(x==0 && y==0){//coin haut gauche
                        if (grille[y][x+1].c!=-1 || grille[y+1][x].c!=-1){
                            if (grille[y][x+1].c!=-1){
                                autour[1]=grille[y][x+1].o;
                            }
                            if (grille[y+1][x].c!=-1){
                                autour[2]=grille[y+1][x].n;
                            }
                        }
                    }
                    else if(x==0 && y==142){//coin bas gauche
                        if (grille[y-1][x].c!=-1 || grille[y][x+1].c!=-1){
                            if (grille[y-1][x].c!=-1){
                                autour[0]=grille[y-1][x].s;
                            }
                            if (grille[y][x+1].c!=-1){
                                autour[1]=grille[y][x+1].o;   
                            }                        
                        }
                    }
                    else if(x==142 && y==0){//coin haut droit
                        if (grille[y][x-1].c!=-1 || grille[y+1][x].c!=-1){
                            if (grille[y][x-1].c!=-1){
                                autour[3]=grille[y][x-1].e;
                            }
                            if (grille[y+1][x].c!=-1){
                                autour[2]=grille[y+1][x].n;
                            }
                        }
                    }
                    else if(x==142 && y==142){//coin bas droit
                        if (grille[y][x-1].c!=-1 && grille[y-1][x].c!=-1){
                            if (grille[y][x-1].c!=-1){
                                autour[3]=grille[y][x-1].e;
                            }
                            if (grille[y-1][x].c!=-1){
                                autour[0]=grille[y-1][x].s;
                            }
                        }
                    }
                    //bordures//format[s,o,n,e]
                    else if(x==0 &&(y<142 || y>0)){//bordure gauche
                        if (grille[y-1][x].c!=-1 || grille[y+1][x].c!=-1 || grille[y][x+1].c!=-1){
                            if (grille[y-1][x].c!=-1){
                                autour[0]=grille[y-1][x].s;
                            }
                            if (grille[y][x+1].c!=-1){
                                autour[1]=grille[y][x+1].o;
                            }
                            if (grille[y+1][x].c!=-1){
                                autour[2]=grille[y+1][x].n;
                            }
                        }
                    }
                    else if(x==142 &&(y>0 || y<142)){//bordure haut
                        if (grille[y][x-1].c!=-1 || grille[y][x+1].c!=-1 || grille[y+1][x].c!=-1){
                              if (grille[y][x-1].c!=-1){
                                autour[3]=grille[y][x-1].e;
                            }
                            if (grille[y][x+1].c!=-1){
                                autour[1]=grille[y][x+1].o;
                            }
                            if (grille[y+1][x].c!=-1){
                                autour[2]=grille[y+1][x].n;
                            }  
                        }
                    }
                    else if(y==0 &&(x>0 || x<142)){//bordure droite
                        if (grille[y-1][x].c!=-1 || grille[y+1][x].c!=-1 || grille[y][x-1].c!=-1){
                              if (grille[y-1][x].c!=-1){
                                autour[0]=grille[y-1][x].s;
                            }
                            if (grille[y][x-1].c!=-1){
                                autour[3]=grille[y][x-1].e;
                            }
                            if (grille[y+1][x].c!=-1){
                                autour[2]=grille[y+1][x].n;
                            }  
                        }
                    }
                    else if(y==142 &&(x>0 || x<142)){//bordure bas
                        if (grille[y][x+1].c!=-1 || grille[y][x-1].c!=-1 || grille[y-1][x].c!=-1){
                                if (grille[y-1][x].c!=-1){
                                autour[0]=grille[y-1][x].s;
                            }
                            if (grille[y][x+1].c!=-1){
                                autour[1]=grille[y][x+1].o;
                            }
                            if (grille[y][x-1].c!=-1){
                                autour[3]=grille[y][x-1].e;
                            }
                        }
                    }
                    int cpt=0, i=1;
                    while (i<4){//////savoir si coin ou bordure
                        if (autour[i]!=255){
                            cpt+=1;
                        }
                        i++;
                    }
                    i=0;
                    int j=0;
                    if (cpt==2){
                        while (i<4){
                            while (j<4){
                                if (piece[i]==autour[j] && (piece[(i+1)%4]==autour[(j+1)%4] || autour[(j+1)%4]==255)){
                                    int rotation=j;
                                    liste_positions_possibles[*curseur]=x;
                                    liste_positions_possibles[*curseur+1]=y;
                                    liste_positions_possibles[*curseur+2]=rotation;
                                    *curseur+=3;
                                }
                            }
                        }
                    }
                    else{
                        while (i<4){
                            while (j<4){
                                if (piece[i]==autour[j] && (piece[(i+1)%4]==autour[(j+1)%4] || autour[(j+1)%4]==255) && (piece[(i+2)%4]==autour[(j+2)%4] || autour[(j+2)%4]==255)){
                                    int rotation=j;
                                    liste_positions_possibles[*curseur]=x;
                                    liste_positions_possibles[*curseur+1]=y;
                                    liste_positions_possibles[*curseur+2]=rotation;
                                    *curseur+=3;
                                }
                            }
                        }
                    }
                }
                ////////////////////////////////////////////////////////
                else{//algo cases centre
                    int autour [4];//format [s,o,n,e]
                    int i=0,cpt=0;
                    while (i<4){//cpt cases non-vides et stock de leur valeur
                        if(i==0 && grille[y-1][x].c!=-1){
                            autour[i]=grille[y-1][x].s;
                            cpt+=1;
                        }
                        else if(i==1 && grille[y][x+1].c!=-1){
                            autour[i]=grille[y][x+1].o;
                            cpt+=1;
                        }
                        else if(i==2 && grille[y+1][x].c!=-1){
                            autour[i]=grille[y+1][x].n;
                            cpt+=1;
                        }
                        else if(i==3 && grille[y][x-1].c!=-1){
                            autour[i]=grille[y][x-1].e;
                            cpt+=1;
                        }
                        else{
                            autour[i]=255;
                        }
                    }
                    if (cpt>0){//chercher possibilités
                        int flag=0,i=0,j=0;
                        while(i<4 && flag==0){
                            while(j<4 && flag==0){
                                if (piece[i]==autour[j]){
                                    if ((piece[(i+1)%4]==autour[(j+1)%4] || autour[(j+1)%4]==255) && (piece[(i+2)%4]==autour[(j+2)%4] || autour[(j+1)%4]==255) && (piece[(i+3)%4]==autour[(j+3)%4] || autour[(j+1)%4]==255)){
                                        flag=1;
                                        int rotation=j;
                                    }
                                }
                                j++;
                            }
                            i++;
                        }
                        if (flag==1){
                            liste_positions_possibles[*curseur]=x;
                            liste_positions_possibles[*curseur+1]=y;
                            liste_positions_possibles[*curseur+2]=rotation;
                            *curseur+=3;
                        }
                    }
                }
            }
        }
    }
    return liste_positions_possibles; //return au format =[x,y,z,x,y,z,x,y,z,....]//retourne le pointeur du tableau
}
*/

void parseur_csv(char* fileName, tuile* pile) {
    FILE* fichier = fopen(fileName, "r");
    int nb, index = 0;
    char temp[1024];
    while (fgets(temp, 1024, fichier)) {
        tuile tile;
        nb = 0;
        char* value = strtok(temp, ", ");
        while (value != NULL) {
            if (value[4] == 'a') {  // village
                if (nb == 4) tile.centre = 'f';
            } else {
                if (nb < 4)
                    tile.cotes[nb] = value[0];
                else
                    tile.centre = value[0];
            }
            nb++;

            value = strtok(NULL, ", ");
        }
        pile[index] = tile;
        pile[index].identifiant = index;
        index++;
    }
fclose(fichier);
}

void melange(tuile * pile){ // mélange la pile 
    srand(time(NULL));
    tuile tmp;
    int nb = 71;
    int r;
    while (nb > 0){
        r = rand()%71;
        tmp = pile[r];
        pile[r] = pile[nb];
        pile[nb] = tmp; 
        nb--;
    }
}

void afficher_pile(tuile * pile){ // affiche la pile qui permet de voir l'ordre dans laquel la pile a était melanger et si la pile a bien était melanger
    for(int i = 0; i < NB_TUILES;i++){
        printf("%d\n",pile[i].identifiant);
    }
}

tuile tuile_vide(){
    //renvoie une tuile vide
    tuile t;
    return t;
}
tuile piocher(tuile * Pile){ // pioche le premiere élément et décale le reste 
    tuile pc = Pile[0];
    for(int i = 1;i < NB_TUILES;i++){
        Pile[i-1] = Pile[i];
    }
    Pile[NB_TUILES] = tuile_vide(); // le nul est a modifier par une tuile vide
    return pc;
}