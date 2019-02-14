#include "HeaderFiles/EnemyBase.h"
#include <cstdlib>

EnemyBase::EnemyBase(float startX,float startY){
    position.x = startX;
    position.y = startY;

    enemyShape.setSize(sf::Vector2f(60,600));
    enemyShape.setPosition(position);
}

FloatRect EnemyBase::GetPosition(){
    return enemyShape.getGlobalBounds();
}

RectangleShape EnemyBase::GetShape(){
    return enemyShape;
}

void EnemyBase::Reset(){
    position.x = 830;
    position.y = rand() % 500 + 50;
}

void EnemyBase::Update(){
    enemyShape.setPosition(position);
}
