#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class bat{
private:
    Vector2f position;
    Sprite testSprite;
    Texture testTexture;
    int lives = 3;
    float batSpeed = 10;

public:
    bat(float startX,float startY);
    FloatRect GetPosition();
    Sprite GetSprite();

    void SetLives(int);
    int GetLives();
    void TakeDamage();
    void MoveUp();
    void SetSprite();
    void MoveDown();
    void Update();
    void ResetPosition(int dir);
};
