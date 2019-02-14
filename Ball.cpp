#include "HeaderFiles/Ball.h"

Ball::Ball(float startX, float startY){
    position.x = startX;
    position.y = startY;
    xAngle = 45;
    yAngle = 45;
    SetSprite();
    ballSprite.setPosition(position);
}

float Ball::GetVelocity(){
    return velocity;
}

Vector2f Ball::GetDirection(){
    return Vector2f(xDirection,yDirection);
}

FloatRect Ball::GetPosition(){
    return ballSprite.getGlobalBounds();
}

Sprite Ball::GetSprite(){
    return ballSprite;
}

void Ball::SetSprite(){
    ballTexture.loadFromFile("Images/ball.png");
    ballSprite.setTexture(ballTexture);
    ballSprite.scale(0.35,0.35);
}

void Ball::ReboundTopBottom(){
    yAngle +=180;
}

void Ball::ReboundRight(){
    xAngle += 180;
}

void Ball::ReboundBat(float portion){
    if(velocity < 9)
    velocity += 0.075 * velocity;

    yAngle = portion;
    xAngle = portion * (xAngle > 0 ? -1:1);

}
void Ball::HitLeft(){
    velocity = 5;
    xAngle = 45;
    yAngle = 45;
    position.x = 30;
    position.y = 500;
}

void Ball::SetPosition(float x, float y){
    position.x = x;
    position.y = y;
}

void Ball::Update(){
    yDirection = sin(3.14/180 * yAngle);
    xDirection = cos(3.14/180 * xAngle);
    position.y += velocity * yDirection;
    position.x += velocity * xDirection;

    ballSprite.setPosition(position);
}
