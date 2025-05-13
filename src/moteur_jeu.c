#include "game_structures.h"
#include "raylib.h"
#include "fct_jeu.h"

#define COLS 72
#define ROWS 72

const int screenWidth = 800;
const int screenHeight = 800;

const int tilesize = 100;

tuile tile_num[24];
tuile Pile[72];
Texture2D textures[24]={};
tuile grille[143][143];
joueur Joueur[5];
int nb_joueur = 2;

void tileDraw(tuile t,int x,int y){
    DrawTexture(textures[t.numero],x*tilesize,y*tilesize,WHITE);
}

int main(void){
    parseur_csv("./src/tuiles_base_simplifiees.csv",Pile);
    parseur_csv("./src/tuile_liste.csv",tile_num);
    find_num(Pile,tile_num);
    Camera2D camera = { 0 };
    camera.target = (Vector2){72*tilesize,72*tilesize};
    camera.offset = (Vector2){screenHeight/2,screenWidth/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    InitWindow(screenWidth, screenHeight, "Carcassone");
    char tmp[30];
    for(int i=0; i<24; i++){
        sprintf(tmp,"./src/tile/Tile_%d.png",i);
        textures[i]=LoadTexture(tmp);
    }
    int x,y;
    partie(grille,&nb_joueur,Joueur,Pile);
    tuile jouer = piocher(Pile,1);
    placement_tuile(grille,jouer,1,140,1,140);
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)) camera.target.x+=5;
        if (IsKeyDown(KEY_LEFT)) camera.target.x-=5;
        if (IsKeyDown(KEY_UP)) camera.target.y-=5;
        if (IsKeyDown(KEY_DOWN)) camera.target.y+=5;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mPos = GetScreenToWorld2D(GetMousePosition(),camera);
            int indexI = mPos.x / tilesize;
            int indexJ = mPos.y / tilesize;
            if(indexI >= 0  && indexI < COLS*2 && indexJ >= 0 && indexJ < ROWS*2){
                x = indexI;
                y = indexJ;
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        for(int i = 0; i < NB_GRILLE;i++){
            for(int j = 0; j < NB_GRILLE;j++){
                DrawRectangleLines(i*tilesize,j*tilesize,tilesize,tilesize,BLACK);
                if(grille[i][j].posee == 1){
                    tileDraw(grille[i][j],i,j);
                }
                if(grille[i][j].posable == 1){
                    DrawRectangle(i*tilesize,j*tilesize,tilesize,tilesize,LIGHTGRAY);
                }
            } 
        }
        EndMode2D();
        tileDraw(jouer,0,0);
        EndDrawing();
    }
    for(int i=0; i<24; i++){
        UnloadTexture(textures[i]);
    }
    CloseWindow();
    return 0;
}
