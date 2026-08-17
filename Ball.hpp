#pragma once
#include <raylib.h>
#include "Padle.hpp"
class Ball
{
    public:
         
        Ball();
        
        void Update(Padle padle, float dt);
        void Draw();
        Vector2 GetPosition();
        
    
        private:
            Vector2 position;
            float bSpeed;
            int speed_x, speed_y;
            int radius;
            bool CheckCollisionPlayer(Padle padle);
            void Collisions_Section(Padle padle);
};