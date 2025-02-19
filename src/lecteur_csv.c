#include <stdio.h>

#include "game_structures.h"


void parseur_csv(char * fname,tuile * Pile)
{
    // lecture du fichier CSV
    FILE *fichier = fopen(fname, "r");
    char *ligne;
    int i, j;
    size_t len = 0; // pour le getline
    char *choixCentre;
    if (fichier != NULL)
    { // on s'assure que la lecture de fichier s'est bien faite
        for (i = 0; i < NB_TUILES; i++)
        {
            getline(&ligne, &len, fichier);
            Pile[i].cotes[0] = strtok(ligne, ",")[0]; // on fait explicitement le premier strtok
            for (j = 1; j < 4; j++)
            {
                Pile[i].cotes[j] = strtok(NULL, ",")[0];
            }

            choixCentre = strtok(NULL, "");
            if (choixCentre[0] == 'v' && choixCentre[4] == 'a')
            {
                Pile[i].centre = 'V'; // si c'est une village
            }
            else
                Pile[i].centre = choixCentre[0]; // si ça ne commence pas par v

        }
    }

    else
        printf("Erreur d'ouverture du fichier.");

    fclose(fichier);
}

