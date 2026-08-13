#include <raylib.h>
#include "Ball.hpp"
#include "GameConfig.hpp"
#include "Padle.hpp"
Vector2 initialPosition = {GameConfig::SCREEN_WIDTH / 2, GameConfig::SCREEN_HEIGHT / 2};
Padle padle;
Ball::Ball()
{
    position = initialPosition;
    speed_x = 300;
    speed_y = 300;
    radius = 15;
}


void Ball::Update(Padle padle, float dt)
{
    position.x += speed_x * dt;
    position.y += speed_y * dt;

    Collisions_Section(padle);

    if(position.x + radius >= GetScreenWidth() || position.x - radius <= 0)
        speed_x *= -1;

    if(position.y + radius >= GetScreenHeight()  || position.y - radius <= 0)
        speed_y *=-1;

    
}

bool Ball::CheckCollisionPlayer(Padle padlePlayer)
{
    bool IsCollide = CheckCollisionCircleRec(position, radius, padlePlayer.GetCollisionAABB());
    return IsCollide;
}

void Ball::Collisions_Section(Padle padle)
{
    if(CheckCollisionPlayer(padle))
    {
        speed_x *= -1;

        if (speed_x > 0)
            position.x = padle.GetCollisionAABB().x + padle.GetCollisionAABB().width + radius;
        else 
            position.x = padle.GetCollisionAABB().x - radius;
    }
}

Vector2 Ball::GetPosition()
{
    return position;
}

void Ball::Draw()
{
    DrawCircle(position.x, position.y, radius, WHITE);
}