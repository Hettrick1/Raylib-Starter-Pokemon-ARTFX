#include "Paddle.h"

Paddle::Paddle(Vector2 paddlePos, bool isPlayer1)
{
	mPaddlePos = paddlePos;
	mIsPlayer1 = isPlayer1;
}

Paddle::~Paddle()
{
}

void Paddle::Move(float deltaTime, const int HEIGHT)
{
	if (!mIsPlayer1) {
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

void Paddle::DrawPaddle()
{
	DrawRectangle(mPaddlePos.x, mPaddlePos.y, 20, 80, BLACK);
}
