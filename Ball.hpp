#pragma once
#include <raylib.h>
#include "Padle.hpp"
class Ball
{
    private:     
        Padle& padlePlayer;
        Padle& padleRight;    
        
        Vector2 position;
        float bSpeed;
        float speed_x, speed_y;
        int radius;
        bool CheckCollisionPlayer(Padle padle);
        void Collisions_Section(Padle padle);
    
    public:
        Ball(Padle& padlePlayer, Padle& padleRight);        
        void Update(float dt);
        void Draw();
        Vector2 GetPosition();
};