#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include <stdlib.h>

typedef struct {
    Rectangle square;
    Color colour;
    Color highlighted_colour;
    Color current_colour;
} Tile;

Tile Tiles[4];

const int Tile_Red=0;
const int Tile_Blue=1;
const int Tile_Green=2;
const int Tile_Yellow=3;

int gamerun=1;
int level=0;
int level_track;
int Players_turn=0;
int Game_Sequence[50]; 
int player_step=0;
int Menu = 1; 

void Add_Sequence(){
    level_track = level + 1;
    Game_Sequence[level] = rand() % 4;
}

void computersequence(int Game_Sequence[50]){
    Add_Sequence();
    for(int i=0; i<=level; i++){
        Tiles[Game_Sequence[i]].current_colour = Tiles[Game_Sequence[i]].highlighted_colour;
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Watch!", 50, 50, 40, GRAY); 
            DrawText(TextFormat("Level : %d", level_track), 300, 650, 40, WHITE);
            for(int j=0; j<4; j++){
                DrawRectangleRec(Tiles[j].square, Tiles[j].current_colour);
            }
        EndDrawing();
        WaitTime(0.5f);

        Tiles[Game_Sequence[i]].current_colour = Tiles[Game_Sequence[i]].colour;
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Watch!", 50, 50, 40, GRAY);
            DrawText(TextFormat("Level : %d", level_track), 300, 650, 40, WHITE);
            for(int j=0; j<4; j++){
                DrawRectangleRec(Tiles[j].square, Tiles[j].current_colour);
            }
        EndDrawing();
        WaitTime(0.5f);
    }
    Players_turn = 1;
    player_step = 0;
}

void player_sequence(void){
    if(Players_turn){
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse_position = GetMousePosition();
            for (int i=0; i<4; i++) {
                if (CheckCollisionPointRec(mouse_position, Tiles[i].square)) {
                    if(i == Game_Sequence[player_step]){
                        Tiles[i].current_colour = Tiles[i].highlighted_colour;
                        BeginDrawing();
                            ClearBackground(BLACK);
                            DrawText(TextFormat("Level : %d", level_track), 300, 650, 40, WHITE);
                            DrawText("Your Turn", 50, 50, 40, WHITE);
                        for(int j=0; j<4; j++){
                            DrawRectangleRec(Tiles[j].square, Tiles[j].current_colour);
                        }
                        EndDrawing();
                        WaitTime(0.2f);
                        
                        Tiles[i].current_colour = Tiles[i].colour;
                        BeginDrawing();
                        ClearBackground(BLACK);
                        DrawText(TextFormat("Level : %d", level_track), 300, 650, 40, WHITE);
                        DrawText("Your Turn", 50, 50, 40, WHITE);
                        for(int j=0; j<4; j++){
                            DrawRectangleRec(Tiles[j].square, Tiles[j].current_colour);
                        }
                        EndDrawing();
                        WaitTime(0.5f);

                        player_step++;
                        if(player_step == level+1){
                            level++;
                            player_step = 0;
                            Players_turn = 0;
                        }
                    } else {
                        gamerun = 0;
                    }
                }    
            }
        }
    }
}

int main(){
    srand(time(NULL));
    InitWindow(800,800,"Colour sequence game");

    Tiles[Tile_Red].square=(Rectangle){200,200,200,200};
    Tiles[Tile_Red].colour=MAROON;
    Tiles[Tile_Red].highlighted_colour=RED;
    Tiles[Tile_Red].current_colour = Tiles[Tile_Red].colour;

    Tiles[Tile_Blue].square=(Rectangle){400,200,200,200};
    Tiles[Tile_Blue].colour=DARKBLUE;
    Tiles[Tile_Blue].highlighted_colour=SKYBLUE;
    Tiles[Tile_Blue].current_colour = Tiles[Tile_Blue].colour;

    Tiles[Tile_Green].square=(Rectangle){200,400,200,200};
    Tiles[Tile_Green].colour=DARKGREEN;
    Tiles[Tile_Green].highlighted_colour=GREEN;
    Tiles[Tile_Green].current_colour = Tiles[Tile_Green].colour;

    Tiles[Tile_Yellow].square=(Rectangle){400,400,200,200};
    Tiles[Tile_Yellow].colour=GOLD;
    Tiles[Tile_Yellow].highlighted_colour=YELLOW;
    Tiles[Tile_Yellow].current_colour = Tiles[Tile_Yellow].colour;

    level_track = 1;

    while(!WindowShouldClose()){
        if(Menu) {
            if(IsKeyPressed(KEY_ENTER)){
                Menu = 0;
            }
        }
        else if(gamerun == 1){
            if(Players_turn == 0){
                computersequence(Game_Sequence);
            }
            else{
                player_sequence();
            }
        }
        BeginDrawing();
            ClearBackground(BLACK);
            if(Menu){
                DrawText("COLOUR SEQUENCE GAME", 150, 200, 40, GOLD);
                DrawText("Instructions:", 300, 300, 30, WHITE);
                DrawText("1. Watch the computer's sequence", 200, 360, 20, LIGHTGRAY);
                DrawText("2. Click the tiles in the SAME order", 200, 400, 20, LIGHTGRAY);
                DrawText("3. The Sequence increases by one after every level", 200, 440, 20, LIGHTGRAY);
                DrawText("3. Complete 50 levels to win!", 200, 480, 20, LIGHTGRAY);
                DrawText("PRESS ENTER TO START", 250, 550, 25, YELLOW);
            }
            else{
                if(gamerun == 1){
                    DrawText(TextFormat("Level : %d", level_track), 300, 650, 40, WHITE);
                    if(Players_turn == 1){
                        DrawText("Your Turn", 50, 50, 40, WHITE);
                    }
                }
                for (int i=0; i<4; i++){
                    DrawRectangleRec(Tiles[i].square, Tiles[i].current_colour);
                }
                if(!gamerun && level < 50){
                    DrawText("GAME OVER!", 300, 100, 40, RED);
                    DrawText("Press Space to Play Again", 260, 150, 20, WHITE);
                    if(IsKeyPressed(KEY_SPACE)){
                        gamerun = 1; 
                        level = 0; 
                        level_track = 1; 
                        player_step = 0; 
                        Players_turn = 0; 
                        Menu = 1;
                    }
                }
                if(level >= 50){
                    gamerun = 0;
                    DrawText("You Win!", 300, 100, 40, GREEN);
                    DrawText("Press Space to Play Again", 260, 150, 20, WHITE);
                    if(IsKeyPressed(KEY_SPACE)){
                        gamerun = 1; 
                        level = 0; 
                        level_track = 1; 
                        player_step = 0; 
                        Players_turn = 0; 
                        Menu = 1;
                    }
                }
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}