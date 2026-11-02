#include "raylib.h"
#include "constants.h"
#include "ball.h"
#include "paddle.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Meu primeiro jogo com Raylib");
    SetTargetFPS(60);

    Paddle player;
    Paddle bot;
    Ball ball;

    int scorePlayer = 0;
    int scoreBot = 0;


    InitPaddle(player, 20, SCREEN_HEIGHT/2);
    InitPaddle(bot, SCREEN_WIDTH-35, SCREEN_HEIGHT/2);
    InitBall(ball);

    while (!WindowShouldClose()) {
        UpdatePaddle(player, KEY_W, KEY_S);
        UpdatePaddle(bot, KEY_UP, KEY_DOWN);
        UpdateBall(ball, player, bot);

        if (ball.position.x - ball.radius > SCREEN_WIDTH) {
            InitPaddle(player, 20, SCREEN_HEIGHT/2);
            InitPaddle(bot, SCREEN_WIDTH-35, SCREEN_HEIGHT/2);
            InitBall(ball);

            scorePlayer++;
            ball.speed_x *= -1;

        }else if(ball.position.x + ball.radius < 0){
            InitPaddle(player, 20, SCREEN_HEIGHT/2);
            InitPaddle(bot, SCREEN_WIDTH-35, SCREEN_HEIGHT/2);
            InitBall(ball);

            scoreBot++;
            ball.speed_x *= -1;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawPaddle(player);
        DrawPaddle(bot);
        DrawBall(ball);
        DrawText(TextFormat("%i", scorePlayer), 250, 10, 40, WHITE);
        DrawText(TextFormat("%i", scoreBot), 550, 10, 40, WHITE);
        DrawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, GRAY);
        DrawText("Raylib funcionando no CachyOS!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
