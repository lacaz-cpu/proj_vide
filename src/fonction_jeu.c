#include "fct_jeu.h"
tuile depart;

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

void init_position(position tab[NB_TUILES]){
    for(int i = 1;i <NB_TUILES;i++){
        tab[i].x = -1;
        tab[i].y = -1;
    }
    tab[0].x = 71;
    tab[0].y = 71;
}


void initTuileDepart(tuile grille[NB_GRILLE][NB_GRILLE]){ // assigne la tuile de départ au grille
    tuile t = depart;
    t.posee = 1;
    grille[mid][mid] = t;
}

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y){
    grille[x][y] = t;
    grille[x][y].posee = 1;
}

/*
int placement_tuile(int x,int y,tuile grille[NB_GRILLE][NB_GRILLE],tuile tl){ // vérifie si la tuile peut etre placer 
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
        return 1;
    return 0;
}
*/
int placement_tuile(int x,int y,tuile grille[NB_GRILLE][NB_GRILLE],tuile tl){ // vérifie si la tuile peut etre placer 
    int nb = 0; // a vérifier car fonctionnement pas sur
    if(grille[x][y].posee == 0){
        if(grille[x-1][y].posee == 0)
            if((grille[x-1][y].cotes[EST] == 'p' && tl.cotes[OUEST]!= 'r' && tl.cotes[OUEST]!= 'v') ||(grille[x-1][y].cotes[EST] == 'r' && tl.cotes[OUEST]== 'r') ||(grille[x-1][y].cotes[EST] == 'v' && tl.cotes[OUEST]== 'v'))
                nb ++;
        if(grille[x+1][y].posee == 0 || grille[x+1][y].cotes[OUEST] == tl.cotes[EST])
            nb ++;
        if(grille[x][y-1].posee == 0 || grille[x][y-1].cotes[NORD] == tl.cotes[SUD])
            nb ++;
        if(grille[x][y+1].posee == 0 || grille[x][y+1].cotes[SUD] == tl.cotes[NORD])
            nb ++;
    }
    if(nb == 4)
        return 1;
    return 0;
}
/*
position * position_possible(){
    
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
        if(index == 0){
            depart = tile;
            depart.identifiant = index;
        }
        else{
            pile[index] = tile;
            pile[index].identifiant = index;
        }
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

/*
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
*/