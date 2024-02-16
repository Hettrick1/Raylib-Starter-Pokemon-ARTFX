#include "Ball.h"
#include "Paddle.h"
#include <iostream>

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Update(float deltaTime, const int WIDTH, const int HEIGHT, Paddle paddleL, Paddle paddleR)
{
    Move(deltaTime);
    CheckCollision(WIDTH, HEIGHT, paddleL, paddleR);
}

void Ball::Move(float deltaTime)
{
    ballPos.x += speed.x * deltaTime;
    ballPos.y += speed.y * deltaTime;

}

void Ball::CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddleL, Paddle paddleR)
{
    if (ballPos.x - BALLRADIUS < 0 || ballPos.x + BALLRADIUS > WIDTH) {
        BounceX();
    }
    else if (ballPos.y - BALLRADIUS < 0 || ballPos.y + BALLRADIUS > HEIGHT) {
        BounceY();
    }
    if (ballPos.x - BALLRADIUS/2 <= paddleL.GetPaddlePos().x + 10 && ballPos.y - BALLRADIUS/2 > paddleL.GetPaddlePos().y && ballPos.y + BALLRADIUS/2 < paddleL.GetPaddlePos().y + 80)
    {
        BounceX();
    }
    if (ballPos.x + BALLRADIUS/2 >= paddleR.GetPaddlePos().x && ballPos.y - BALLRADIUS/2 > paddleR.GetPaddlePos().y && ballPos.y + BALLRADIUS/2 < paddleR.GetPaddlePos().y + 80)
    {
        BounceX();
    }
        
}

void Ball::DrawBall()
{
    DrawCircle(ballPos.x, ballPos.y, BALLRADIUS, RED);
}

void Ball::BounceX()
{
    speed.x *= -1;
}

void Ball::BounceY()
{
    speed.y *= -1;
}

Vector2 Ball::GetPosition()
{
    return ballPos;
}