#include "ball.h"
#include "constants.h"

void InitBall(Ball& b){
    b.position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
    b.speed_x = 300.0f;
    b.speed_y = 300.0f;
    b.radius = 20;
}


void UpdateBall(Ball& b, const Paddle& player, const Paddle& bot){
    b.position.x += b.speed_x * GetFrameTime();
    b.position.y += b.speed_y * GetFrameTime();

    if(b.position.y + b.radius >= SCREEN_HEIGHT) {
        b.position.y = SCREEN_HEIGHT - b.radius;
        b.speed_y *= -1;
    }
    if(b.position.y - b.radius <= 0) {
        b.position.y = b.radius;
        b.speed_y *= -1;
    }

    Collision(b, player, bot);
}

void DrawBall(const Ball& b){
    DrawCircleV(b.position, b.radius, WHITE);
}

void Collision(Ball&b, const Paddle& player, const Paddle& bot){
    if(CheckCollisionCircleRec(b.position, b.radius, player.paddle)){
        b.position.x = player.paddle.x + player.paddle.width + b.radius;
        b.speed_x *= -1;
    }

    if(CheckCollisionCircleRec(b.position, b.radius, bot.paddle)){
        b.position.x = bot.paddle.x - b.radius;
        b.speed_x *= -1;
    }
}
