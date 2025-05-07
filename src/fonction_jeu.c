#include "fct_jeu.h"
#include "affichage.h"
tuile depart;

void initJoueurs(joueur *joueurs,int *nb_joueurs,int *nb_ia){
    int i;
    for (i = 0; i < *nb_joueurs; i++){
        joueurs[i].ia = 0;
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7;
    }
    for (i = *nb_joueurs; i < *nb_joueurs + *nb_ia; i++){
        joueurs[i].ia = 1;
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7; 
    }

}

void initTuileDepart(tuile grille[NB_GRILLE][NB_GRILLE]){ // assigne la tuile de départ au grille
    tuile t = depart;
    t.posee = 1;
    t.posable = 0;
    grille[mid][mid] = t;
}

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y,int z,int w){
    grille[x][y] = t;
    grille[x][y].posee = 1;
}

void init_grille(tuile grille[NB_GRILLE][NB_GRILLE]){
    for(int i = 0; i < NB_GRILLE;i++){
        for(int j = 0;j < NB_GRILLE;j++){
            grille[i][j].posee = 0;
        }
    }
}

int placement_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile tl,int x,int z,int y,int w){ // vérifie si la tuile peut etre placer 
    int nb = 0;
    for (int i = x - 1; i <= z + 1; i++)
    {
        for (int j = y - 1; j <= w + 1; j++)
        {
            if (grille[i][j].posee == 0)
            {
                if (grille[i - 1][j].posee == 1 || grille[i][j + 1].posee == 1 || grille[i + 1][j].posee == 1 || grille[i][j - 1].posee == 1)
                {
                    //vérifie si chaque bord de la tuiles et compatible 
                    if (((tl.cotes[0] == grille[i - 1][j].cotes[2] || grille[i - 1][j].posee == 0) || ((tl.cotes[0] == 'v' || tl.cotes[0] == 'b') && (grille[i - 1][j].cotes[2] == 'v' || grille[i - 1][j].cotes[2] == 'b' || grille[i - 1][j].posee == 0))) &&
                        ((tl.cotes[1] == grille[i][j + 1].cotes[3] || grille[i][j + 1].posee == 0) || ((tl.cotes[1] == 'v' || tl.cotes[1] == 'b') && (grille[i][j + 1].cotes[3] == 'v' || grille[i][j + 1].cotes[3] == 'b' || grille[i][j + 1].posee == 0))) &&
                        ((tl.cotes[2] == grille[i + 1][j].cotes[0] || grille[i + 1][j].posee == 0) || ((tl.cotes[2] == 'v' || tl.cotes[2] == 'b') && (grille[i + 1][j].cotes[0] == 'v' || grille[i + 1][j].cotes[0] == 'b' || grille[i + 1][j].posee == 0))) &&
                        ((tl.cotes[3] == grille[i][j - 1].cotes[1] || grille[i][j - 1].posee == 0) || ((tl.cotes[3] == 'v' || tl.cotes[3] == 'b') && (grille[i][j - 1].cotes[1] == 'v' || grille[i][j - 1].cotes[1] == 'b' || grille[i][j - 1].posee == 0))))
                    {
                        grille[i][j].posable = 1;
                        nb++;
                    }
                    else
                        grille[i][j].posable = 0;
                }
                else
                    grille[i][j].posable = 0;
            }
            else
                grille[i][j].posable = 0;
        }
    }
    return nb;
}

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
            pile[index-1] = tile;
            pile[index-1].identifiant = index;
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

void partie(tuile grille[NB_GRILLE][NB_GRILLE], int *nb_joueurs,int *nb_ia,joueur *Joueurs){ // définie le nombre de joueur et d'ia et initialise la partie
    printf("\v\v\v\v\v\tNombre de joueurs : ");
    scanf("%d", nb_joueurs);
    printf("\n\n\tNombre d'IA : ");
    scanf("%d", nb_ia);
    printf("\n");
    if (*nb_joueurs + *nb_ia < 2 || *nb_joueurs + *nb_ia > 5)
    {
        printf("\tLe nombre de joueurs doit être compris entre 2 et 5.\n");
        partie(grille, nb_joueurs, nb_ia, Joueurs);
    }
    init_grille(grille);
    initJoueurs(Joueurs,nb_joueurs,nb_ia);
    initTuileDepart(grille);
}


tuile rotation_tuile(tuile T){ // rotation de la tuile de 90 degrès sur la droite
    int i, tmp = T.cotes[3];

    for (i = 3; i > 0; i--)
        T.cotes[i] = T.cotes[i - 1];
    T.cotes[0] = tmp;
    return T;
}

tuile piocher(tuile *pile,int nb_tour){// pioche le premiere élément et décale le reste 
    pile[0].posee = 1;
    pile[0].posable = 0;
    tuile tmp = pile[0];
    for(int i = 1;i < NB_TUILES-nb_tour;i++){
        pile[i-1] = pile[i];
    } 
    return tmp;
}


