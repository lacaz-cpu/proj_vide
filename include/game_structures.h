#ifndef GAME_STRUCTURES
#define GAME_STRUCTURES



typedef struct{
    int id;
    int pion;
    int score;
}joueur;


typedef struct{
    int x,y;
}position;

typedef struct{
    int identifiant;
    char cote[5];
    position pos;
}tuile_s;

typedef struct{
    tuile_s tab[84]; // 84 = nombre de tuiles
}grille;

#endif // GAME_STRUCTURES
