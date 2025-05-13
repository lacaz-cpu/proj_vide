#include "fct_jeu.h"


void initJoueurs(joueur *joueurs,int *nb_joueurs){
    int i;
    for (i = 0; i < *nb_joueurs; i++){
        joueurs[i].ia = 0;
        joueurs[i].id = i;
        joueurs[i].score = 0;
        joueurs[i].pion = 7;
    }
}

void placer_tuile(tuile grille[NB_GRILLE][NB_GRILLE],tuile t,int x,int y){
    grille[x][y] = t;
    grille[x][y].posee = 1;
    grille[x][y].posable = 0;
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
                    if (((tl.cotes[NORD] == grille[i - 1][j].cotes[SUD] || grille[i - 1][j].posee == 0) || ((tl.cotes[NORD] == 'v' || tl.cotes[NORD] == 'b') && (grille[i - 1][j].cotes[SUD] == 'v' || grille[i - 1][j].cotes[SUD] == 'b' || grille[i - 1][j].posee == 0))) &&
                        ((tl.cotes[EST] == grille[i][j + 1].cotes[OUEST] || grille[i][j + 1].posee == 0) || ((tl.cotes[EST] == 'v' || tl.cotes[EST] == 'b') && (grille[i][j + 1].cotes[OUEST] == 'v' || grille[i][j + 1].cotes[OUEST] == 'b' || grille[i][j + 1].posee == 0))) &&
                        ((tl.cotes[SUD] == grille[i + 1][j].cotes[NORD] || grille[i + 1][j].posee == 0) || ((tl.cotes[SUD] == 'v' || tl.cotes[SUD] == 'b') && (grille[i + 1][j].cotes[NORD] == 'v' || grille[i + 1][j].cotes[NORD] == 'b' || grille[i + 1][j].posee == 0))) &&
                        ((tl.cotes[OUEST] == grille[i][j - 1].cotes[EST] || grille[i][j - 1].posee == 0) || ((tl.cotes[OUEST] == 'v' || tl.cotes[OUEST] == 'b') && (grille[i][j - 1].cotes[EST] == 'v' || grille[i][j - 1].cotes[EST] == 'b' || grille[i][j - 1].posee == 0))))
                    {   
                        printf("%d %d",i,j);
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


void parseur_csv(char* fname, tuile* pile){ // lis le fichier csv
    FILE* fichier = fopen(fname, "r");
    int nb, index = 0;
    char temp[1024];
    while (fgets(temp, sizeof(temp), fichier)) {
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
        pile[index].posee = 0;
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

void partie(tuile grille[NB_GRILLE][NB_GRILLE], int *nb_joueurs,joueur *Joueurs,tuile *Pile){ // définie le nombre de joueur et d'ia et initialise la partie
    if (*nb_joueurs < 2 || *nb_joueurs > 5)
    {
        //afficher sur le canva qu'il est ne peut y avoir max que 5 et joueur et min 2 joueur
        partie(grille, nb_joueurs,Joueurs,Pile);
    }
    initJoueurs(Joueurs,nb_joueurs);
    tuile depart = piocher(Pile,0);
    grille[NB_TUILES][NB_TUILES] = depart;
    melange(Pile);
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


void poser_tuile(tuile Grille[NB_GRILLE][NB_GRILLE],tuile t, int *nb_tours, int nb_joueurs,joueur *Joueurs, int x,int y)
{
    if (x > NB_GRILLE - 2 || y > NB_GRILLE - 2 || x < 0 || y < 0)
    {
        //afficher sur le canva coordonnées invalide 
    }
    if (Grille[x][y].posable == 1)
    {
        placer_tuile(Grille,t,x,y);

        if (Joueurs[(*nb_tours - 1) % nb_joueurs].pionsjouer < 6)
            poser_pion(Grille, Joueurs, *nb_tours, nb_joueurs, x, y);
        *nb_tours += 1;
    }
    else
    {
        printf("\nLa tuile ne peut etre placer ici\n\n");
        //afficher sur le canva que la tuile ne peut etre placer
    }
}


void poser_pion(tuile Grille[NB_GRILLE][NB_GRILLE], joueur *Joueurs, int nb_tours, int nb_joueurs, int x, int y)
{
    int position = 0;
    //demander sur le canva ou placer le pion (0,1,2,3,4,5)
    scanf("%d", &position);  
    if (position == 5)
        return;

    Grille[x][y].pions.id = (nb_tours - 1) % nb_joueurs;
    Grille[x][y].pions.pos = position;
    Joueurs[(nb_tours - 1) % nb_joueurs].pionsjouer++;
}



void find_num(tuile *Pile,tuile * tile){ // trouve le numero tuile affilié a l'image.png
    int nb;
    for(int w = 0; w < NB_TUILES;w++){
        for(int i = 0;i < 24;i++){
            nb = 0;
            if(Pile[w].centre == tile[i].centre)
                nb++;
            for(int j = 0;j < 4;j++){
                if(Pile[w].cotes[j] == tile[i].cotes[j]){
                    nb++;
                }
            }
            if(nb == 5){
                Pile[w].numero = i;
                break;
            }
        }
    }
}