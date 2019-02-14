#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Controller{
    private:
        int playerLives;
        int enemyLives;
        int currentLevel;
        int playerScore;

    public:
        Controller(int);

        int GetScore();
        int GetLives();

        void IncreaseScore();
        void SetLives(int);

        void KillPlayer();
        void KillEnemy();

        void ChangeLevel();
        void Pause();
        void Update();
        void Restart();
};
