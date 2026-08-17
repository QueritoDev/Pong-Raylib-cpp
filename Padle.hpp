#pragma once
#include <raylib.h>

class Padle
{
    public:
        Padle(Vector2 initialPosition);

        void Draw();
        void Update(float dt);
        Vector2 GetPosition();
        Rectangle GetCollisionAABB();

    private:
        Vector2 position;
        Vector2 direction;
        float speed;
        int padle_width, padle_height;
        void Input(float dt);
        void Collisions();
};