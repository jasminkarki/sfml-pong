#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Bullet{

private:
    Vector2f position;
    Vector2f initPosition;
    RectangleShape shape;
    int lifePoints = 100;
    float speed = 6;

public:
    Bullet(float startX,float startY);
    FloatRect GetPosition();
    RectangleShape GetShape();

   //void Move(int);
    void Update();
    void Reset(float,float);
};
