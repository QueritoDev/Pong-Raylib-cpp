#include <raylib.h>
#include "raymath.h"
#include "Sprite.hpp"


Sprite::Sprite(Vector2 initialPosition, float initialSpeed)
{
    pos = initialPosition;
    speed = initialSpeed;
    direction = Vector2{0.0f,0.0f};
}


void Sprite::Move(float dt)
{
   if(direction!=Vector2Zero())
   {
        direction = Vector2Normalize(direction);

        pos.x += direction.x * speed * dt;
        pos.y += direction.y * speed * dt;
   }
}