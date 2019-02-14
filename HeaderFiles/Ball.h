#pragma once
#include<SFML/Graphics.hpp>
#include<Math.h>

using namespace sf;

class Ball{
private:
    Vector2f position;
    Sprite ballSprite;
    Texture ballTexture;

    float velocity = 5;
    float xAngle;
    float yAngle;
    float xDirection;
    float yDirection;

public:
    Ball(float startX,float startY);
    FloatRect GetPosition();
    Sprite GetSprite();

    void ReboundRight();
    void SetPosition(float,float);
    Vector2f GetDirection();
    float GetVelocity();
    void ReboundBat(float);

    void SetSprite();
    void ReboundTopBottom();
    void ReboundEnemyTopBottom(FloatRect, FloatRect);
    void ReboundBar(FloatRect,FloatRect);
    void HitLeft();
    void Update();
};
