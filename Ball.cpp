#include "Ball.h"
#include "Paddle.h"

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Update(float deltaTime, const int WIDTH, const int HEIGHT, Paddle paddle1, Paddle paddle2)
{
    Move(deltaTime);
    CheckCollision(WIDTH, HEIGHT, paddle1, paddle2);
}

void Ball::Move(float deltaTime)
{
    ballPos.x += speed.x * deltaTime;
    ballPos.y += speed.y * deltaTime;

}

void Ball::CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddle1, Paddle paddle2)
{
    if (ballPos.x - BALLRADIUS < 0 || ballPos.x + BALLRADIUS > WIDTH) {
        speed.x = -speed.x;
    }
    else if (ballPos.y - BALLRADIUS < 0 || ballPos.y + BALLRADIUS > HEIGHT) {
        speed.y = -speed.y;
    }
    if (ballPos.x - BALLRADIUS < paddle1.GetPaddlePos().x + 20 || ballPos.x - BALLRADIUS > paddle2.GetPaddlePos().x) {
        speed.x = -speed.x;
    }
    else if ((ballPos.y - BALLRADIUS > paddle1.GetPaddlePos().y || ballPos.y - BALLRADIUS > paddle2.GetPaddlePos().y + 80) && (ballPos.y - BALLRADIUS < paddle1.GetPaddlePos().y|| ballPos.y - BALLRADIUS < paddle2.GetPaddlePos().y + 80)) {
        speed.y = -speed.y;
    }
}

void Ball::DrawBall()
{
    DrawCircle(ballPos.x, ballPos.y, BALLRADIUS, RED);
}
