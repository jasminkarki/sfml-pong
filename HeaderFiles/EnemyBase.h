#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class EnemyBase{

//TODO: ADD HEALTH SYSTEM

private:
    Vector2f position;
    RectangleShape enemyShape;
    int lifePoints = 100;

public:
    EnemyBase(float startX,float startY);
    FloatRect GetPosition();
    RectangleShape GetShape();
    void Update();
    void Reset();
};
