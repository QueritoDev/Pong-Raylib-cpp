#include "paddle.h"
#include "constants.h"
#include <raylib.h>

void InitPaddle(Paddle& p, float x, float y){
    float width = 15;
    float height = 80;
    p.paddle = {x, y, width, height};
    p.speed = 400.0f;
}


void UpdatePaddle(Paddle& p, int keyUp, int keyDown){
    if(IsKeyDown(keyUp)) p.paddle.y -= p.speed * GetFrameTime();
    if(IsKeyDown(keyDown)) p.paddle.y += p.speed * GetFrameTime();

    if(p.paddle.y < 0) p.paddle.y = 0;
    if(p.paddle.y > SCREEN_HEIGHT - p.paddle.height){
        p.paddle.y = SCREEN_HEIGHT - p.paddle.height;
    }
}

void DrawPaddle(const Paddle& p){
    DrawRectangleRec(p.paddle, WHITE);
}

Rectangle GetRec(const Paddle& p){
    return Rectangle({p.paddle.x, p.paddle.y, p.paddle.width, p.paddle.height});
}
