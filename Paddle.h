#pragma once
#include "raylib.h"
class Paddle
{
private:
	Vector2 mPaddlePos;
	Vector2 mPaddleSpeed = { 0, 250 };
	bool mIsPlayer1;
public:
	Paddle(Vector2 paddlePos, bool isPlayer1);
	~Paddle();
	void Move(float deltaTime, const int HEIGHT);
	void DrawPaddle();
	Vector2 GetPaddlePos() { return mPaddlePos; }
};

