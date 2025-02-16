#include "fct_jeu.h"

int numero_piece(char mot){
        if strcmp(mot,"route"){
            return 0;
        }
        else if strcmp(mot,"ville"){
            return 1;
        }
        else if strcmp(mot,"blason"){
            return 2;
        }
        else if strcmp(mot,"pre"){
            return 3;
        }
        else if strcmp(mot,"abbaye"){
            return 4;
        }
        else if strcmp(mot,"village"){
            return 5;
        }
}

void rotation(struct piece *tuile){
    int n;
    n=tuile->n;
    tuile->n=tuile->o;
    tuile->o=tuile->s;
    tuile->s=tuile->e;
    tuile->e=n;
}

void charger_tuiles(struct piece *carca){
    char mot[10];
    FILE *file = fopen("tuiles_bases_simplifiees.csv", "r");
    for(int i=0;i<360;++i){
        char chaine;
        fscanf(file, "%c",&chaine);
        int cpt=0;
        while(chaine !="," && chaine !="\n"){
            mot[cpt]=chaine;
            ++cpt;
            fscanf(file, "%c",&chaine);
        }
        if (i%5==0){
            carca[i/5].n=numero_piece(mot);
        }
        if (i%5==1){
            carca[i/5].e=numero_piece(mot);
        }
        if (i%5==2){
            carca[i/5].s=numero_piece(mot);
        }
        if (i%5==3){
            carca[i/5].o=numero_piece(mot);
        }
        if (i%5==4){
            carca[i/5].c=numero_piece(mot);
        }
    }
    fclose(file);
}

void melange(struct piece *liste_tuile){
    struct piece tmp;
    int nb;
    for(int i=1; i<72;++i){
        srand(time(NULL));
        nb = rand()%72;
        if (nb==0){
            nb+=1;
        }
        tmp=liste_tuile[i];
        liste_tuile[i]=liste_tuile[nb];
        liste_tuile[nb]=tmp;
    }
}

void placer_tuile(struct piece tuile,struct piece **plateau,int x, int y){//fonction appelée si la tuile peut être placée
    plateau[y][x]=tuile;
}

void aff_score(struct joueur *j, int nb_joueurs){
    for (int i=0; i<nb_joueurs;++i){
        printf("joueur %d = %d",i+1,j[i].score);
    }
}

void pose_pion(int cote,struct piece *plateau){//cote=n,s,e,o,c
}

void evaluer(int x, int y, struct joueur *liste_joueurs, struct piece *plateau){//liste des joueurs,x,y,plateau//parametre pion a la piece prenant cote et la couleur du pion//revérifier algo bordures
    int tuile_cotes [5];
    tuile_cotes[0]=plateau[y][x]->n;
    tuile_cotes[1]=plateau[y][x]->e;
    tuile_cotes[2]=plateau[y][x]->s;
    tuile_cotes[3]=plateau[y][x]->o;
    tuile_cotes[4]=plateau[y][x]->c;
    for (int i=0; i<5;i++){//1,2,3,4,5,6 pour chaque type de tuile (route,ville/blason,pre,abbaye,village)
        if(i==4 && tuile_cotes[i]==5){
            //abbaye rajouter sécurité des bordures//routes aussi//idee char liste[5]={"n","s"...} importé dans ->liste[i]
            //////////////////////////////////////////////////abbaye
            if (plateau[y-1][x-1]!=NULL && plateau[y-1][x]!=NULL && plateau[y-1][x+1]!=NULL && plateau[y][x-1]!=NULL && plateau[y][x+1]!=NULL && plateau[y+1][x-1]!=NULL && plateau[y+1][x]!=NULL && plateau[y+1][x+1]!=NULL){
                liste_joueurs[plateau[y][x]->couleur_pion]->score+=9;
            }
            ////////////////////////////////////////////////////////////////routes
            if (tuile_cotes[i]==1){
                int flag=1, mouv_x=0, mouv_y=0, cpt_route=1;
                while(flag==1){
                    if (plateau[y+mouv_y][x+mouv_x]->c==1){
                        //trouver le côté adjacent ou rien flag=0
                    }
                    else if (plateau[y+mouv_y][x+mouv_x]->n==1){
                        //regarder si sud autre piece ==route sinon si void flag=0 sinon points
                    }
                    else if (plateau[y+mouv_y][x+mouv_x]->s==1){
                        mouv_y+=1;
                        if (plateau[y+mouv_y][x+mouv_x]->n==1){
                            cpt_route+=1;
                        }
                        else{
                            if(plateau[y+mouv_y][x+mouv_x]==NULL){
                                flag=0;
                            }
                            else{
                                liste_joueurs[plateau[y][x]->couleur_pion]->score+=cpt_route;
                            }
                        }
                    }
                    else if (plateau[y+mouv_y][x+mouv_x]->e==1){
                        //trouver le côté adjacent ou rien flag=0
                    }
                    else if (plateau[y+mouv_y][x+mouv_x]->o==1){
                        //trouver le côté adjacent ou rien flag=0
                    }
                }

            }
            //////////////////////////////////////////////ville ou blason
        }
    }
}

void aff_placements(int tableau_positions, int taille_tableau){
    int curseur=0;
    for (int i=0; i<taille_tableau;i+3){
        printf("position %d: x: %d,y: %d\n",i%3,tableau_positions[i],tableau_positions[i+1])
    }
}


int *positions_possibles(struct piece *plateau,struct piece piece_a_poser,int *curseur,int nb_pieces_deja_posees){//curseur est un simple entier, nb_deja_posees=72-cpt tuiles du main
    int liste_positions_possibles=(int)malloc(max_pos_possibles*sizeof(int));
    int piece[4];
    piece[0]=piece_a_poser.n;
    piece[1]=piece_a_poser.e;
    piece[2]=piece_a_poser.s;
    piece[3]=piece_a_poser.o;
    for (int y=0; y<143;++y){
        for (int x=0; x<143;++x){
            if (plateau[y][x]==NULL){//si case vide peut être utilisée à ce tour mais si au moins une case adjacente != void
                //////////////////////////////////////////////////////
                if(y<1 || y==n || x==0 || x==n){
                    //algo bordure
                    //côtés
                    int autour [4]={255,255,255,255};
                    if(x==0 && y==0){//coin haut gauche
                        if (plateau[y][x+1]!=NULL || plateau[y+1][x]!=NULL){
                            if (plateau[y][x+1]!=NULL){
                                autour[1]=plateau[y][x+1]->o;
                            }
                            if (plateau[y+1][x]!=NULL){
                                autour[2]=plateau[y+1][x]->n;
                            }
                        }
                    }
                    else if(x==0 && y==142){//coin bas gauche
                        if (plateau[y-1][x]!=NULL || plateau[y][x+1]!=NULL){
                            if (plateau[y-1][x]!=NULL){
                                autour[0]=plateau[y-1][x]->s;
                            }
                            if (plateau[y][x+1]!=NULL){
                                autour[1]=plateau[y][x+1]->o;   
                            }                        
                        }
                    }
                    else if(x==142 && y==0){//coin haut droit
                        if (plateau[y][x-1]!=NULL || plateau[y+1][x]!=NULL){
                            if (plateau[y][x-1]!=NULL){
                                autour[3]=plateau[y][x-1]->e;
                            }
                            if (plateau[y+1][x]!=NULL){
                                autour[2]=plateau[y+1][x]->n;
                            }
                        }
                    }
                    else if(x==142 && y==142){//coin bas droit
                        if (plateau[y][x-1]!=NULL && plateau[y-1][x]!=NULL){
                            if (plateau[y][x-1]!=NULL){
                                autour[3]=plateau[y][x-1]->e;
                            }
                            if (plateau[y-1][x]!=NULL){
                                autour[0]=plateau[y-1][x]->s;
                            }
                        }
                    }
                    //bordures//format[s,o,n,e]
                    else if(x==0 &&(y<142 || y>0)){//bordure gauche
                        if (plateau[y-1][x]!=NULL || plateau[y+1][x]!=NULL || plateau[y][x+1]!=NULL){
                            if (plateau[y-1][x]!=NULL){
                                autour[0]=plateau[y-1][x]->s;
                            }
                            if (plateau[y][x+1]!=NULL){
                                autour[1]=plateau[y][x+1]->o;
                            }
                            if (plateau[y+1][x]!=NULL){
                                autour[2]=plateau[y+1][x]->n;
                            }
                        }
                    }
                    else if(x==142 &&(y>0 || y<142)){//bordure haut
                        if (plateau[y][x-1]!=NULL || plateau[y][x+1]!=NULL || plateau[y+1][x]!=NULL){
                              if (plateau[y][x-1]!=NULL){
                                autour[3]=plateau[y][x-1]->e;
                            }
                            if (plateau[y][x+1]!=NULL){
                                autour[1]=plateau[y][x+1]->o;
                            }
                            if (plateau[y+1][x]!=NULL){
                                autour[2]=plateau[y+1][x]->n;
                            }  
                        }
                    }
                    else if(y==0 &&(x>0 || x<142)){//bordure droite
                        if (plateau[y-1][x]!=NULLd || plateau[y+1][x]!=NULL || plateau[y][x-1]!=NULL){
                              if (plateau[y-1][x]!=NULL){
                                autour[0]=plateau[y-1][x]->s;
                            }
                            if (plateau[y][x-1]!=NULL){
                                autour[3]=plateau[y][x-1]->e;
                            }
                            if (plateau[y+1][x]!=NULL){
                                autour[2]=plateau[y+1][x]->n;
                            }  
                        }
                    }
                    else if(y==142 &&(x>0 || x<142)){//bordure bas
                        if (plateau[y][x+1]!=NULL || plateau[y][x-1]!=NULL || plateau[y-1][x]!=NULL){
                                if (plateau[y-1][x]!=NULL){
                                autour[0]=plateau[y-1][x]->s;
                            }
                            if (plateau[y][x+1]!=NULL){
                                autour[1]=plateau[y][x+1]->o;
                            }
                            if (plateau[y][x-1]!=NULL){
                                autour[3]=plateau[y][x-1]->e;
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
                                    liste_positions_possibles[curseur]=x;
                                    liste_positions_possibles[curseur+1]=y;
                                    liste_positions_possibles[curseur+2]=rotation;
                                    curseur+=3;
                                }
                            }
                        }
                    }
                    else{
                        while (i<4){
                            while (j<4){
                                if (piece[i]==autour[j] && (piece[(i+1)%4]==autour[(j+1)%4] || autour[(j+1)%4]==255) && (piece[(i+2)%4]==autour[(j+2)%4] || autour[(j+2)%4]==255)){
                                    int rotation=j;
                                    liste_positions_possibles[curseur]=x;
                                    liste_positions_possibles[curseur+1]=y;
                                    liste_positions_possibles[curseur+2]=rotation;
                                    curseur+=3;
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
                        if(i==0 && plateau[y-1][x]!=NULL){
                            autour[i]=plateau[y-1][x]->s;
                            cpt+=1;
                        }
                        else if(i==1 && plateau[y][x+1]!=NULL){
                            autour[i]=plateau[y][x+1]->o;
                            cpt+=1;
                        }
                        else if(i==2 && plateau[y+1][x]!=NULL){
                            autour[i]=plateau[y+1][x]->n;
                            cpt+=1;
                        }
                        else if(i==3 && [y][x-1]!=NULL){
                            autour[i]=plateau[y][x-1]->e;
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
                            liste_positions_possibles[curseur]=x;
                            liste_positions_possibles[curseur+1]=y;
                            liste_positions_possibles[curseur+2]=rotation;
                            curseur+=3;
                        }
                    }
                }
            }
        }
    }
    return liste_positions_possibles; //return au format =[x,y,z,x,y,z,x,y,z,....]//retourne le pointeur du tableau
}

//fonction qui regarde si position voulue par joueur est bonne
int check_placement(int x,int y,int *liste_possibles,int taille){//taille= curseur-1
    int flag=0;
    for (int i=0;i<taille-1;i+2){
        if (x==liste_possibles[i] && y==liste_possibles[i+1]){
            flag=1;
            return flag;
        }
    }
    return flag;
}

//fonction remplir plateau avec piece contenant NULL
//struct piece emplacement_vide(){
//    struct piece p;
//    p.evaluation=0;
//    p.n=NULL;
//    p.s=NULL;
//    p.e=NULL;
//    p.o=NULL;
//    p.c=NULL;
//    p.type_pion=0;
//    return p;
//}

void init_plateau(struct piece *plateau,struct piece piece_de_depart){
    for (int i=0; i<143;++i){
        for (int j=0; j<143;++j){
            if(i==71 && j==71){
                //pose tuile de depart
                plateau[i][j]=piece_de_depart;
            }
            else{
                //remplissage de vide
                plateau[i][j]=NULL;//ou avec fonction :plateau[i][j]=emplacement_vide();
            }
        }
    }
}

//rajouter lecture des positions_possibles dans play_IA//corriger tourner selon besoins(rajouter un paramètre sens à la liste possible par rapport à position de départ)
void play_ia(int *liste_possibles,struct piece *plateau,struct piece p,int taille){//positions possibles;plateau;piece à poser;taille possibilités
    int nb;
    srand(time(NULL));  
    nb = rand()%taille;//on tombe sur un x,y ou donnée de position
    //on cherche la prochaine donnée de position
    while(nb%3!=2){
        nb+=1;
    }
    //on est sur la rotation pour cette position possible x,y sélectionnée donc on tourne la piece
    for(int i=0; i<liste_possibles[nb];i++){
        rotation(p);
    }//puis on remplit le plateau avec la piece tournée
    plateau[liste_possibles[nb-1]][liste_possibles[nb-2]]->c=p->c;
    plateau[liste_possibles[nb-1]][liste_possibles[nb-2]]->s=p->s;
    plateau[liste_possibles[nb-1]][liste_possibles[nb-2]]->e=p->e;
    plateau[liste_possibles[nb-1]][liste_possibles[nb-2]]->o=p->o;
    plateau[liste_possibles[nb-1]][liste_possibles[nb-2]]->n=p->n;
    
}
//améliorer recherche savoir si 4 CASES sont vides autour avec prototype démineur filtré
//define pour valeur 143
//vérifier cohérence entre fonction rotation et calcul de la rotation dans positions possibles
//refaire la structure piece avec tableau n,s,e,o