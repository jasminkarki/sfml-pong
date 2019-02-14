#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Enemy{

//TODO: ADD HEALTH SYSTEM

private:
    Vector2f position;
    RectangleShape enemyShape;
    int lifePoints = 100;
    float enemySpeed = 2;

public:
    Enemy(float startX,float startY);
    FloatRect GetPosition();
    RectangleShape GetShape();

    void Move(int);
    void Update();
    void Reset();
};
