#include "raylib.h"
#include "Ball.h"
#include <iostream>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 500;
float deltaTime;
std::vector<int>score = { 0, 0 };

void Load();
void Start();
void Update();
void Draw();
void Unload();

Ball ball = Ball();

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

}

void Update()
{
    deltaTime = GetFrameTime();
    ball.Update(deltaTime, WIDTH, HEIGHT);
}

void Draw()
{
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Pong",WIDTH/2 - MeasureText("Pong", 100)/2, 40, 100, BLACK);
    DrawText(TextFormat("%02i", score[0]), 100, 55, 80, GRAY);
    DrawText(TextFormat("%02i", score[1]), WIDTH - 100 - MeasureText(TextFormat("%02i", score[1]), 80), 55, 80, GRAY);
    ball.DrawBall();
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}



