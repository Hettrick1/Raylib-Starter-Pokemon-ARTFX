#include "Paddle.h"

Paddle::Paddle(Vector2 paddlePos, bool isPaddleL)
{
	mPaddlePos = paddlePos;
	mIsPaddleL = isPaddleL;
}

Paddle::~Paddle()
{
}

void Paddle::Move(float deltaTime, const int HEIGHT)
{
	if (!mIsPaddleL) {
		if (IsKeyDown(KEY_UP) && mPaddlePos.y > 0) {
			mPaddlePos.y -= mPaddleSpeed.y * deltaTime;
		}
		if (IsKeyDown(KEY_DOWN) && mPaddlePos.y < HEIGHT-80) {
			mPaddlePos.y += mPaddleSpeed.y * deltaTime;
		}
	}
	else {
		if (IsKeyDown(KEY_W) && mPaddlePos.y > 0) {
			mPaddlePos.y -= mPaddleSpeed.y * deltaTime;
		}
		if (IsKeyDown(KEY_S) && mPaddlePos.y < HEIGHT-80) {
			mPaddlePos.y += mPaddleSpeed.y * deltaTime;
		}
	}
}

void Paddle::Update(float deltaTime, const int HEIGHT)
{
	Move(deltaTime, HEIGHT);
}

void Paddle::DrawPaddle()
{
	DrawRectangle(mPaddlePos.x, mPaddlePos.y, 10, 80, BLACK);
}

