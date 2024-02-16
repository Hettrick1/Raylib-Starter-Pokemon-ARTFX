#pragma once
#include "raylib.h"
class Paddle
{
private:
	Vector2 mPaddlePos;
	Vector2 mPaddleSpeed = { 0, 250 };
	bool mIsPaddleL;
public:
	Paddle(Vector2 paddlePos, bool isPaddleL);
	~Paddle();
	void Move(float deltaTime, const int HEIGHT);
	void Update(float deltaTime, const int HEIGHT);
	void DrawPaddle();
	Vector2 GetPaddlePos() { return mPaddlePos; }
};

