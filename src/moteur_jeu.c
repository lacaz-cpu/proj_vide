#include "game_structures.h"
#include "affichage.h"
#include "fct_jeu.h"
#include "raylib.h"


#define COLS 72
#define ROWS 72

const int screenWidth = 900;
const int screenHeight = 900;

const int tilesize = 100;

tuile tile_num[24];
tuile Pile[72];
Texture2D textures[24]={};

void tileDraw(tuile t,int x,int y){
    DrawTexture(textures[t.numero],x*tilesize,y*tilesize,WHITE);
}

int main(void){
    parseur_csv("./src/tuile_liste.csv",tile_num);
    parseur_csv("./src/tuiles_base_simplifiees.csv",Pile);
    find_num(Pile,tile_num);
    Camera2D camera = { 0 };
    camera.target = (Vector2){71*tilesize,71*tilesize};
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
    tuile tr = piocher(Pile,0);
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
        Vector2 mx = GetMousePosition();
        int I = mx.x / tilesize;
        int J = mx.y / tilesize;
        DrawText(TextFormat("[%i, %i]", I, J),150,150,0,BLACK);
        for(int i = 0; i < ROWS*2;i++){
            for(int j = 0; j < COLS*2;j++){
                DrawRectangleLines(i*tilesize,j*tilesize,tilesize,tilesize,BLACK);
            } 
        }
        tileDraw(tr,71,71);
        EndMode2D();

        //tileDraw(piocher(Pile,1),1,2);
        EndDrawing();
    }
    for(int i=0; i<24; i++){
        UnloadTexture(textures[i]);
    }
    CloseWindow();
    return 0;
}
