#include "Ball.h"

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Update(float deltaTime, const int WIDTH, const int HEIGHT)
{
    Move(deltaTime);
    CheckCollision(WIDTH, HEIGHT);
}

void Ball::Move(float deltaTime)
{
    ballPos.x += speed.x * deltaTime;
    ballPos.y += speed.y * deltaTime;

}

void Ball::CheckCollision(const int WIDTH, const int HEIGHT)
{
    if (ballPos.x - BALLRADIUS < 0 || ballPos.x + BALLRADIUS > WIDTH) {
        speed.x = -speed.x;
    }
    else if (ballPos.y - BALLRADIUS < 0 || ballPos.y + BALLRADIUS > HEIGHT) {
        speed.y = -speed.y;
    }
}

void Ball::DrawBall()
{
    DrawCircle(ballPos.x, ballPos.y, BALLRADIUS, RED);
}
