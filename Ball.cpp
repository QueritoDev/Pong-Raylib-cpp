#include <raylib.h>
#include "Ball.hpp"
#include "GameConfig.hpp"
#include "Padle.hpp"

Ball::Ball(Padle& padlePlayer, Padle& padleRight)
    : padlePlayer(padlePlayer), padleRight(padleRight)
{ 
    position = {GameConfig::SCREEN_WIDTH/2.0f, GameConfig::SCREEN_HEIGHT/2.0f};
    speed_x = 300;
    speed_y = 300;
    radius = 15;
}

void Ball::Update(float dt)
{
    position.x += speed_x * dt;
    position.y += speed_y * dt;

    if(position.x + radius >= GetScreenWidth() || position.x - radius <= 0)
        speed_x *= -1;

    if(position.y + radius >= GetScreenHeight()  || position.y - radius <= 0)
        speed_y *=-1;
}


Vector2 Ball::GetPosition()
{
    return position;
}

void Ball::Draw()
{
    DrawCircle(position.x, position.y, radius, WHITE);
}