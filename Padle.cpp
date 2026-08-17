#include <raylib.h>
#include "Sprite.hpp"
#include "Padle.hpp"
#include "GameConfig.hpp"

float initialSpeed = 300.0f;
Padle::Padle(Vector2 initialPosition) : Sprite(initialPosition, initialSpeed)
{
    padle_width = 25;
    padle_height = 120;
    speed_y = initialSpeed;
    initialPosition = GetPosition();
    position = initialPosition;
}

void Padle::Input(float dt)
{
    direction.y = (IsKeyDown(KEY_S) ? 1:0) - (IsKeyDown(KEY_W) ? 1:0);
}



void Padle::Update(float dt)
{
    if(position.y >= 0)
    {
        position.y = 0; 
    }

    if(position.y + padle_height >= GetScreenHeight())
    {
        position.y = GetScreenHeight() - padle_height; 
    }
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