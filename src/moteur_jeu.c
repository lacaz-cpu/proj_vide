#include "game_structures.h"
#include "affichage.h"
#include "fct_jeu.h"
#include "raylib.h"


#define COLS 3
#define ROWS 3

const int screenWidth = 300;
const int screenHeight = 300;

const int tileWidth = 100;
const int tileHeight = 100;

tuile tile_num[24];
tuile Pile[72];
Texture2D textures[24]={};

void tileDraw(tuile t,int x,int y){
    DrawTexture(textures[t.numero],x*tileWidth,y*tileHeight,WHITE);
}

int main(void){
    parseur_csv("./src/tuile_liste.csv",tile_num);
    parseur_csv("./src/tuiles_base_simplifiees.csv",Pile);
    find_num(Pile,tile_num);
    Camera2D camera={0};
    camera.target=(Vector2){0,0};   // Point que la caméra suit
    camera.offset=(Vector2){150,150}; // Centre de l'écran
    InitWindow(screenWidth, screenHeight, "Carcassone");
    char tmp[30];
    for(int i=0; i<24; i++){
        sprintf(tmp,"./src/tile/Tile_%d.png",i);
        textures[i]=LoadTexture(tmp);
    }
    tuile tr = piocher(Pile,0);
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)) camera.target.x+=5;
        if (IsKeyDown(KEY_LEFT)) camera.target.x-=5;
        if (IsKeyDown(KEY_UP)) camera.target.y-=5;
        if (IsKeyDown(KEY_DOWN)) camera.target.y+=5;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        for(int i = 0; i < 72;i++){
            for(int j = 0; j < 72;j++){
                DrawRectangleLines(i*tileWidth,j*tileHeight,tileWidth,tileHeight,BLACK);
            } 
        }
        EndMode2D();
        tileDraw(tr,1,1);
        //tileDraw(piocher(Pile,1),1,2);
        EndDrawing();
    }
    for(int i=0; i<24; i++){
        UnloadTexture(textures[i]);
    }
    CloseWindow();
    return 0;
}
