#include "raylib.h"
#include "GameConfig.hpp"
#include "Ball.hpp"

int main() 
{
   
    InitWindow(GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, "Pong Game Raylib C++");
    SetTargetFPS(200);
    Ball bolas;
    Padle padlePlayer(padlePlayer.GetPosition());
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        //INPUT

        //UPDATE
        
        bolas.Update(padlePlayer, dt);
        padlePlayer.Update(dt);
        //DRAWING
        BeginDrawing();
        ClearBackground(BLACK);
        padlePlayer.Draw();
        DrawRectangle(GameConfig::SCREEN_WIDTH-35, GameConfig::SCREEN_HEIGHT / 2 - 60, 25, 120, WHITE);
        bolas.Draw();
        DrawFPS(0,0);
        DrawText("It's working!", 350, 200, 20, DARKGRAY);
        EndDrawing();
    }
 
    CloseWindow();
    return 0;
}