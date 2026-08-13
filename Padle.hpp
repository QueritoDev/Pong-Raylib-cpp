#pragma once
#include <raylib.h>

class Padle
{
    public:
        Padle();

        void Draw();
        void Update(float dt);
        Vector2 GetPosition();
        Rectangle GetCollisionAABB();

    private:
        void Input(float dt);
        Vector2 initialPosition;
        Vector2 position;
        int padle_width, padle_height;
        int speed_y;
        void Collisions();
};