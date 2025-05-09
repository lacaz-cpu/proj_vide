#include "affichage.h"
void affiche_g(){
    int espace = 15;
    sauter_espace(espace);
    printf("\x1b[31m           |>>>                        |>>>\x1b[0m\n");
    sauter_espace(espace);
    printf("           |                           |\n");
    sauter_espace(espace);
    printf("\x1b[34m       _  _|_  _                   _  _|_  _\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m      | |_| |_| |                 | |_| |_| |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m      \\  .      /                 \\ .    .  /\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m       \\_______/                   \\_______/\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m        |     |        _____        |     |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m        |     |       |     |       |     |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m        |     |       |[]   |       |     |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m        |     |       |     |       |     |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m       /|##!##|\\     /|##!##|\\     /|##!##|\\\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m      / |##!##| \\   / |##!##| \\   / |##!##| \\\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m     |  |##!##|  | |  |##!##|  | |  |##!##|  |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m     |  |##!##|  | |  |##!##|  | |  |##!##|  |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m     |  |##!##|  | |  |##!##|  | |  |##!##|  |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m     |  |##!##|  | |  |##!##|  | |  |##!##|  |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m     |  |##!##|  | |  |##!##|  | |  |##!##|  |\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[30m    /___|_____|_/__\\__|_____|__/__\\_|_____|___\\\x1b[0m\n");
    
}

void sauter_espace(int espace) {
    for(int i = 0; i < espace; i++)
        printf("    ");
}

void afficher_titre() {
    int espace = 10;
    sauter_espace(espace);
    printf("\x1b[33m_________     \x1b[0m\n");
    sauter_espace(espace);                                                                             
    printf("\x1b[33m\\_   ___ \\ _____   _______   ____  _____     ______  ______  ____    ____    ____    ____  \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[33m/    \\  \\/ \\__  \\  \\_  __ \\_/ ___\\ \\__  \\   /  ___/ /  ___/ /  _ \\  /    \\  /    \\ _/ __ \\ \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[33m\\     \\____ / __ \\_ |  | \\/\\  \\___  / __ \\_ \\___ \\  \\___ \\ (  <_> )|   |  \\|   |  \\\\  ___/ \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[33m \\______  /(____  / |__|    \\___  >(____  //____  >/____  > \\____/ |___|  /|___|  / \\___  > \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[33m        \\/      \\/              \\/      \\/      \\/      \\/              \\/      \\/      \\/ \x1b[0m\n");
}

void affichage_ecran_titre() {
    char chr;
    int espace = 15;
    system("clear");
    afficher_titre();
    printf("\n");
    printf("\n");
    affiche_g();
    printf("\n");
    sauter_espace(espace);
    printf("Appuyer sur entrée pour jouer :");
    scanf("%c", &chr);
}

void affichage_acceuil(){
    int espace = 15;
    system("clear");
    sauter_espace(espace);
    printf("\x1b[34m     _____                                   __  __   \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m    /  _  \\    ____    ____    ____   __ __ |__||  |  \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m   /  /_\\  \\ _/ ___\\ _/ ___\\ _/ __ \\ |  |  \\|  ||  |  \x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m  /    |    \\\\  \\___ \\  \\___ \\  ___/ |  |  /|  ||  |__\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m  \\____|__  / \\___  > \\___  > \\___  >|____/ |__||____/\x1b[0m\n");
    sauter_espace(espace);
    printf("\x1b[34m          \\/      \\/      \\/      \\/    \x1b[0m\n");
}

void afficher_ligne(int nbj) {
    printf("+");
    for(int j = 0; j < nbj; j++)
        printf("---------------------");
    printf("+ \n");
} 

void affichage_partie(joueur joueurs[], int nombreJoueurs) {
    system("clear");
    afficher_ligne(nombreJoueurs);
    printf("|");
    for(int j = 0; j < nombreJoueurs; j++) {
        printf(" Joueur %d :", joueurs[j].id + 1);
        printf("          ");
    }
    printf("| \n");
    printf("|");
    for(int j = 0; j < nombreJoueurs; j++) {
        printf(" Pions : %d / 6 ", joueurs[j].pion);
        printf("      ");
    }
    printf("| \n");
    printf("|");
    for(int j = 0; j < nombreJoueurs; j++) {
        printf(" Score : %d ", joueurs[j].score);
        printf("          ");
    }
    printf("| \n");
    afficher_ligne(nombreJoueurs);
}

void affichage(tuile grille[NB_GRILLE][NB_GRILLE]){
    for(int i = 0;i < NB_GRILLE ; i++){
        for(int j = 0; j < NB_GRILLE;j++){
            if(grille[i][j].posee ==1){
                printf("\n");
                printf("-----------\n");
                printf("|    %c    |\n", grille[i][j].cotes[0]);
                printf("| %c  %c  %c |\n", grille[i][j].cotes[3], grille[i][j].centre, grille[i][j].cotes[1]);
                printf("|    %c    |\n", grille[i][j].cotes[2]);
                printf("-----------\n\n");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}


void afficher_tuile(tuile tuile){
    printf("-----------\n");
    printf("|    %c    |\n", tuile.cotes[0]);
    printf("| %c  %c  %c |\n", tuile.cotes[3], tuile.centre, tuile.cotes[1]);
    printf("|    %c    |\n", tuile.cotes[2]);
    printf("-----------\n\n");
}