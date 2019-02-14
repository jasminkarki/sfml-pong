#include "HeaderFiles/Enemy.h"
#include <cstdlib>

Enemy::Enemy(float startX,float startY){
    position.x = startX;
    position.y = startY;

    enemyShape.setSize(sf::Vector2f(100,200));
    enemyShape.setFillColor(sf::Color::Red);
    enemyShape.setPosition(position);
}

FloatRect Enemy::GetPosition(){
    return enemyShape.getGlobalBounds();
}

RectangleShape Enemy::GetShape(){
    return enemyShape;
}


void Enemy::Move(int dir){
    position.y += dir * enemySpeed;
}


void Enemy::Reset(){
    position.x = 830;
    position.y = rand() % 500 + 50;
}

void Enemy::Update(){
    enemyShape.setPosition(position);
}
