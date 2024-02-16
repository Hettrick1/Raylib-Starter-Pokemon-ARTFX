#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
#include <vector>
#include <list>

const int WIDTH = 800;
const int HEIGHT = 500;
float deltaTime;
std::vector<int>score = { 0, 0 };

void Load();
void Start();
void Update();
void Draw();
void Unload();
void center_window(float window_width, float window_height);
void DrawDottedLine();

Ball ball = Ball();
Paddle paddleL = Paddle(Vector2{ 30, HEIGHT / 2 }, true);
Paddle paddleR = Paddle(Vector2{ WIDTH-40, HEIGHT / 2 }, false);

int main() { 
    Load();
    Start();
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
    Unload();    
    return 0;
}

void Load()
{
    InitWindow(WIDTH, HEIGHT, "Pokemon");
    SetTargetFPS(60);
}

void Start()
{
    center_window(WIDTH, HEIGHT);
}

void Update()
{
    deltaTime = GetFrameTime();
    paddleL.Update(deltaTime, HEIGHT);
    paddleR.Update(deltaTime, HEIGHT);
    ball.Update(deltaTime, WIDTH, HEIGHT, paddleL, paddleR);
}

void Draw()
{
    BeginDrawing();
    ClearBackground(WHITE);

    DrawDottedLine();

    DrawText("Pong",WIDTH/2 - MeasureText("Pong", 100)/2, 40, 100, BLACK);
    DrawText(TextFormat("%02i", score[0]), 100, 55, 80, GRAY);
    DrawText(TextFormat("%02i", score[1]), WIDTH - 100 - MeasureText(TextFormat("%02i", score[1]), 80), 55, 80, GRAY);

    ball.DrawBall();
    paddleL.DrawPaddle();
    paddleR.DrawPaddle();
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}

void center_window(float window_width, float window_height)
{
    int monitor = GetCurrentMonitor();
    int monitor_width = GetMonitorWidth(monitor);
    int monitor_height = GetMonitorHeight(monitor);
    SetWindowPosition((int)(monitor_width / 2) - (int)(window_width / 2), (int)(monitor_height / 2) - (int)(window_height / 2));
}

void DrawDottedLine() {
    for (float i = 0; i < HEIGHT; i += 50) {
        DrawLineEx(Vector2{ WIDTH / 2, i }, Vector2{ WIDTH / 2, i + 25 }, 15, LIGHTGRAY);
    }
}


