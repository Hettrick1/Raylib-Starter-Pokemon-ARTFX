#pragma once
#include "raylib.h"
#include "Paddle.h"

class Ball
{
private:
	Vector2 ballPos = { 400, 250 };
	Vector2 speed = { 200, 200 };
	const int BALLRADIUS = 10;
public:
	Ball();
	~Ball();
	void Update(float deltaTime, const int WIDTH, const int HEIGHT, Paddle paddleL, Paddle paddleR);
	void Move(float deltaTime);
	void CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddleL, Paddle paddleR);
	void DrawBall();
	void BounceX();
	void BounceY();
	Vector2 GetPosition();
};

