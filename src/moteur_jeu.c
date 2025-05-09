#include "game_structures.h"
#include "affichage.h"
#include "fct_jeu.h"
#include "raylib.h"


#define COLS 1
#define ROWS 1

const int screenWidth = 800;
const int screenHeight = 800;

const int tileWidth = screenWidth/COLS;
const int tileHeight = screenHeight/ROWS;

void tileDraw(tuile t ){

}
int main(void){
    tuile grid[ROWS][COLS];
    for(int i = 0; i < COLS;i++){
        for(int j = 0; j < ROWS;j++){
            grid[i][j].x = i;
            grid[i][j].y = j;
        } 
    }
    InitWindow(screenWidth, screenHeight, "Carcassone");
    Camera2D camera={0};
    camera.target=(Vector2){0,0};   // Point que la caméra suit
    camera.offset=(Vector2){400,300}; // Centre de l'écran
    Texture2D textures[24]={};
    char tmp[30];
    for(int i=0; i<24; i++){
        sprintf(tmp,"./src/tile/Tile_%d.png",i);
        textures[i]=LoadTexture(tmp);
    }
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)) camera.target.x+=5;
        if (IsKeyDown(KEY_LEFT)) camera.target.x-=5;
        if (IsKeyDown(KEY_UP)) camera.target.y-=5;
        if (IsKeyDown(KEY_DOWN)) camera.target.y+=5;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
        DrawLine((int)camera.target.x, -screenHeight*10, (int)camera.target.x, screenHeight*10, GREEN);
        DrawLine(-screenWidth*10, (int)camera.target.y, screenWidth*10, (int)camera.target.y, GREEN);

        EndMode2D();
        /*
        for(int i = 0; i < COLS;i++){
            for(int j = 0; j < ROWS;j++){
                DrawTexture(textures[0],i*tileWidth,j*tileHeight,WHITE);
            } 
        }
        */
        EndDrawing();
    }
    for(int i=0; i<24; i++){
        UnloadTexture(textures[i]);
    }
    CloseWindow();
    return 0;
}
