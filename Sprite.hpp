#pragma once
#include <raylib.h>

class Sprite
{
    public:
        void Update(float dt);
        Vector2 pos;
        Vector2 direction;
        float speed;

        Sprite(Vector2 initialPosition, float initalSpeed);
        Rectangle GetCollisionAABB();

    private:
        void Move(float dt);
        Vector2 initialPosition;
        void Collisions();
};