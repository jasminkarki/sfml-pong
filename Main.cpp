#include "HeaderFiles/Bat.h"
#include "HeaderFiles/Ball.h"
#include "HeaderFiles/EnemyBase.h"
#include "HeaderFiles/Enemy.h"
#include "HeaderFiles/Controller.h"
#include "HeaderFiles/Bullet.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

float windowWidth = 800;
float windowHeight = 600;

int main(){

    enum EnemyStates{
        GoUp,
        GoDown,
        Stop
    };

    float enemyTime = 0;

    //Set Window Height and Width

    Enemy enemy(600,windowHeight/2);
    EnemyStates currState = GoUp;
    Bullet bullet(enemy.GetPosition().left,enemy.GetPosition().top + enemy.GetPosition().height/2);

    Clock clock;
    Clock enemyClock;
    Time time;
    float timeDelay = 4;
    //Create a window capable of rendering
    RenderWindow window(VideoMode(windowWidth,windowHeight),"Tuk-Tuk");

    //Create the interactive components
    bat Bat(1,windowHeight/2);                      //Player Bat
    Ball ball(30,windowHeight/2);    //Ball
    Controller controller(Bat.GetLives());
    EnemyBase enemyBase(650,0);                           //Enemy

    FloatRect ballPos;
    FloatRect enemyBasePos;


    //Create the game's HUD (User Viewable Text)
    Text hud;
    Font font;

    //TODO: Move the font file to fonts folder
    font.loadFromFile("DS-DIGIT.ttf");
    hud.setFont(font);
    hud.setPosition(windowWidth/3,0);
    hud.setCharacterSize(50);
    hud.setOutlineThickness(2);
    hud.setFillColor(Color::White);
    hud.setOutlineColor(Color::Black);

    //Core game play and user interaction
    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
           if(event.type == Event::Closed)
                window.close();
        }

        time = clock.getElapsedTime();

        //Check that PLAYER does not EXIT the SCREEN
        if(Bat.GetPosition().top < 0){
            Bat.ResetPosition(1);
        }else if(Bat.GetPosition().top + Bat.GetPosition().height > windowHeight){
            Bat.ResetPosition(-1);
        }
        else{

            //MOVE the Player
            if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
                Bat.MoveUp();
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
                Bat.MoveDown();
            }

            if(Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }

        if (ball.GetPosition().intersects(enemy.GetPosition()))
        {

            float batHeight = enemy.GetPosition().height;
            float batTop = enemy.GetPosition().top;

            float ballPos = ball.GetPosition().top;


            if(ball.GetPosition().left + 5 >= enemy.GetPosition().left + enemy.GetPosition().width){
                ball.ReboundRight();
            }else{
                if(ballPos < batTop + batHeight/4){
                    ball.ReboundBat(-120);
                }

                else if(ballPos < batTop + batHeight/3){
                    ball.ReboundBat(-150);
                }

                else if(ballPos < batTop + batHeight/2){
                    ball.ReboundBat(180);
                }

                else if(ballPos > batTop + 3 * batHeight/4){
                    ball.ReboundBat(120);
                }

                else if(ballPos > batTop + 2 * batHeight/3){
                    ball.ReboundBat(150);
                }

                else if(ballPos > batTop + batHeight/2){
                    ball.ReboundBat(180);
                }
            }

        }

        //Check Ball COLLISIONS
        if(ball.GetPosition().left < 0){        //Reduce Player 'Lives' if reaches left screen edge
            ball.HitLeft();
            sleep(seconds(0.3));
            //Bat.TakeDamage();
        }

        if (ball.GetPosition().left + ball.GetPosition().width > windowWidth)
        {
            ball.ReboundRight();
        }

        if (ball.GetPosition().top <= 0 || ball.GetPosition().top + ball.GetPosition().height >= windowHeight)
        {
            ball.ReboundTopBottom();
        }

        if(bullet.GetPosition().intersects(Bat.GetPosition())){
            //Bat.TakeDamage();
            bullet.Reset(enemy.GetPosition().left+20 ,enemy.GetPosition().top + enemy.GetPosition().height/2);
        }

        if(bullet.GetPosition().left + bullet.GetPosition().width/2< 0){
            bullet.Reset(enemy.GetPosition().left+20 ,enemy.GetPosition().top + enemy.GetPosition().height/2);
        }

        if (ball.GetPosition().intersects(Bat.GetPosition()))
        {
            float batHeight = Bat.GetPosition().height;
            float batTop = Bat.GetPosition().top;
            float ballPos = ball.GetPosition().top;

            if(ballPos < batTop + batHeight/4){
                ball.ReboundBat(-30);
            }

            else if(ballPos < batTop + batHeight/3){
                ball.ReboundBat(-60);
            }

            else if(ballPos < batTop + batHeight/2){
                ball.ReboundBat(0);
            }

            else if(ballPos > batTop + 3 * batHeight/4){
                ball.ReboundBat(30);
            }

            else if(ballPos> batTop + 2 * batHeight/3){
                ball.ReboundBat(60);
            }

            else if(ballPos> batTop + batHeight/2){
                ball.ReboundBat(0);
            }
        }

    //ENEMY COLLISION!!
         //if(ball.GetPosition().intersects(Enemy.GetPosition())){

        if(ball.GetPosition().intersects(enemy.GetPosition())){

            controller.IncreaseScore();
        }



        int dir;
            enemyTime = enemyClock.getElapsedTime().asSeconds();

            if(enemy.GetPosition().top <= 10){
                currState = Stop;

                if(enemyTime >= timeDelay){
                    currState = GoDown;
                    enemyClock.restart().asSeconds();
                }
            }

            if(enemy.GetPosition().top + enemy.GetPosition().height >= windowHeight - 10){
                currState = Stop;

                if(enemyTime >= timeDelay){
                    currState = GoUp;
                    enemyClock.restart().asSeconds();
                }

            }
        switch (currState){
        case GoUp:
            dir = -1;
            break;
        case GoDown:
            dir = 1;
            break;
        case Stop:
            dir = 0;
            break;
        }
        enemy.Move(dir);

        //UPDATE the game components
        Bat.Update();
        ball.Update();
        enemyBase.Update();
        enemy.Update();
        bullet.Update();
        clock.restart().asSeconds();

        //Set info to the HUD
        std::stringstream hudString;
        hudString<< "Score: " << controller.GetScore() << "     Lives: " << controller.GetLives();
        hud.setString(hudString.str());

        //KILL player
        if(Bat.GetLives() < 1){
                controller.KillPlayer();
                Bat.SetLives(3);
        }
        //Actual DRAWING on the window.
        controller.SetLives(Bat.GetLives());
        window.clear(Color(0,0,0,255));
        window.draw(Bat.GetSprite());
        window.draw(ball.GetSprite());
       // window.draw(enemyBase.GetShape());
        window.draw(enemy.GetShape());
        window.draw(bullet.GetShape());
        window.draw(hud);
        window.display();

        //LIMIT FrameRate to 60
        window.setFramerateLimit(60);
    }

    return 0;
}
