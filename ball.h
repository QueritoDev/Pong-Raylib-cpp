#pragma once
#include "raylib.h"
#include "paddle.h"

struct Ball{
    Vector2 position;
    float speed_x;
    float speed_y;
    float radius;
};

void InitBall(Ball& b);
void UpdateBall(Ball& b, const Paddle& p1, const Paddle& p2);
void DrawBall(const Ball& b);
void Collision(Ball&b, const Paddle& player, const Paddle& bot);
