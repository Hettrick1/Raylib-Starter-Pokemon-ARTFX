#pragma once
#include "raylib.h"
#include "Paddle.h"

class Ball
{
private:
	Vector2 ballPos = { 400, 250 };
	Vector2 speed = { 160, 160 };
	const int BALLRADIUS = 20;
public:
	Ball();
	~Ball();
	void Update(float deltaTime, const int WIDTH, const int HEIGHT, Paddle paddle1, Paddle paddle2);
	void Move(float deltaTime);
	void CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddle1, Paddle paddle2);
	void DrawBall();
};

