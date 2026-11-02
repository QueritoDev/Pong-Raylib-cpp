#pragma once
#include "raylib.h"

struct Paddle{
    Rectangle paddle;
    float speed;
};

void InitPaddle(Paddle& p, float x, float y);
void UpdatePaddle(Paddle& p, int keyUp, int keyDown);
void DrawPaddle(const Paddle& p);
Rectangle GetRec(const Paddle& p);
