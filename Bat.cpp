#include "HeaderFiles/bat.h"

//Constructor Function
bat::bat(float startX,float startY){
    position.x = startX;
    position.y = startY;
    testSprite.setPosition(position);
    SetSprite();
}

FloatRect bat::GetPosition(){
    return testSprite.getGlobalBounds();
}

Sprite bat::GetSprite(){
    return testSprite;
}

int bat::GetLives(){
    return lives;
}

void bat::TakeDamage(){
    lives--;
}

void bat::SetLives(int newLives){
    lives = newLives;
}

void bat::SetSprite(){
    testTexture.loadFromFile("Images/glasspaddle1.png");
    testSprite.setTexture(testTexture);
    testSprite.scale(0.35,0.6);
}

void bat::MoveUp(){
    position.y -= batSpeed;
}

void bat::MoveDown(){
    position.y += batSpeed;
}

void bat::Update(){
    testSprite.setPosition(position);
}

void bat::ResetPosition(int dir){
    position.y += dir * 10;
}
