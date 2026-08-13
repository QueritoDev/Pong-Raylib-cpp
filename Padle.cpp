#include <raylib.h>
#include "Padle.hpp"
#include "GameConfig.hpp"

Padle::Padle()
{
    padle_width = 25;
    padle_height = 120;
    speed_y = 300;
    Vector2 initialPosition = {10.0f, (GameConfig::SCREEN_HEIGHT / 2.0f) - (padle_height/2.0f)};
    position = initialPosition;
}

void Padle::Input(float dt)
{
    if(IsKeyDown(KEY_W))
        position.y -= speed_y * dt;
    if(IsKeyDown(KEY_S))
        position.y += speed_y * dt;
}

void Padle::Update(float dt)
{
    Input(dt);
}

void Padle::Draw()
{
    DrawRectangleV(position, {(float)padle_width, (float)padle_height}, WHITE);
}


Vector2 Padle::GetPosition()
{
    return position;
}

Rectangle Padle::GetCollisionAABB()
{
    return Rectangle {position.x, position.y, (float)padle_width, (float)padle_height};
}