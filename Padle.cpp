#include <raylib.h>
#include <raymath.h>
#include "Padle.hpp"
#include "GameConfig.hpp"


Padle::Padle(Vector2 initialPosition)
{
    position = initialPosition;
    direction = {0.0f,0.0f};
    padle_width = 25;
    padle_height = 120;
    speed = 600.0f;
}

void Padle::Update(float dt)
{
    if(position.y <= 0)
    {
        position.y = 0; 
    }

    if(position.y + padle_height >= GetScreenHeight())
    {
        position.y = GetScreenHeight() - padle_height; 
    }

    direction.y = (IsKeyDown(KEY_S) ? 1:0) - (IsKeyDown(KEY_W) ? 1:0);
    position.y += direction.y * speed * dt;
}

void Padle::Input(float dt)
{
   
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