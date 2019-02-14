#include "HeaderFiles/Bullet.h"
#include <cstdlib>

Bullet::Bullet(float startX,float startY){
    position.x = startX;
    position.y = startY;
    initPosition = position;
    shape.setSize(sf::Vector2f(60,10));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
}

FloatRect Bullet::GetPosition(){
    return shape.getGlobalBounds();
}

RectangleShape Bullet::GetShape(){
    return shape;
}

void Bullet::Reset(float posX, float posY){
    position.x = posX;
    position.y = posY;
}

void Bullet::Update(){
    position.x -= speed;
    shape.setPosition(position);
}
