#include <iostream>
#include "raylib.h"
#include "GameConfig.hpp"

int player_score = 0;
int cpu_score = 0;

class Ball
{
    public: 
    float x = GameConfig::SCREEN_WIDTH / 2;
    float y = GameConfig::SCREEN_HEIGHT / 2;
    float radius = 20;
    int speed_x = 280; 
    int speed_y = 280;

    void ResetPosition()
    {
        if(x + radius > GameConfig::SCREEN_WIDTH)
        {
            x = GameConfig::SCREEN_WIDTH / 2;
            y = GameConfig::SCREEN_HEIGHT / 2;
        }
        if(x - radius < 0)
        {
            x = GameConfig::SCREEN_WIDTH / 2;
            y = GameConfig::SCREEN_HEIGHT / 2;
        }
    }
    void Update(float _deltatime)
    {
        x+= speed_x * _deltatime;
        y+= speed_y * _deltatime;

        if(y + radius >= GameConfig::SCREEN_HEIGHT || y - radius <=0)
        {
            speed_y *= -1;
        }   
    
        if(x + radius >= GameConfig::SCREEN_WIDTH || x - radius <=0) // Cpu Wins
        {
            player_score++;
            ResetPosition();
        }
        if(x - radius <= 0)
        {
            cpu_score++;
            ResetPosition();
        }
    }
    
    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);   
    }

};

class Padle
{
    protected:

    void LimitMovement()
    {
        if(y <= 0)
        {
            y = 0;
        }
        if (y + height >= GameConfig::SCREEN_HEIGHT)
        {
            y = GameConfig::SCREEN_HEIGHT - height;
        }
    }

    public:
    float x,y;
    float width = 25;
    float height = 120;
    int speed = 270;

    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update(float _deltatime)
    {
        if(IsKeyDown(KEY_UP))
        {
            y -= speed * _deltatime;
        }
        if(IsKeyDown(KEY_DOWN))
        {
            y += speed * _deltatime;
        }

        LimitMovement();
    }

    Rectangle GetRec()
    {
        return Rectangle({x, y, width, height});
    }
};

class CPUPadle : public Padle
{
    public:

    void Update(float _deltatime, int ball_y)
    {
        if(y + height/2 > ball_y)
        {
            y -= speed * _deltatime;
        }
        if(y + height/2 <= ball_y)
        {
            y += speed * _deltatime;
        }
        LimitMovement();
    }
};

Ball ball;
Padle player;
CPUPadle cpu;


int main() 
{
    InitWindow(GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, "Pong Game Raylib C++");
    SetTargetFPS(200);
    
    ball.x = GameConfig::SCREEN_WIDTH / 2;
    ball.y = GameConfig::SCREEN_HEIGHT / 2;
    
    player.x = 10;
    player.y = GameConfig::SCREEN_HEIGHT / 2 - player.height/2;
    
    cpu.x = GameConfig::SCREEN_WIDTH - cpu.width - 10;
    cpu.y = GameConfig::SCREEN_HEIGHT / 2 - cpu.height/2;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        //INPUT
        
        //UPDATE
        ball.Update(dt);
        player.Update(dt);
        cpu.Update(dt, ball.y);
        
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, player.GetRec()))
        {
            ball.speed_x *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, cpu.GetRec()))
        {
            ball.speed_x *= -1;
        }
        //DRAWING
        BeginDrawing();
        ClearBackground(BLACK);
        ball.Draw();
        player.Draw();
        cpu.Draw();
        DrawFPS(0,0);
        DrawLine(0, GameConfig::SCREEN_HEIGHT/2, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT/2, BLUE);
        DrawText("It's working!", 350, 200, 20, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}