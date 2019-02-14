#include "HeaderFiles/Controller.h"

Controller::Controller(int startLives){
    playerScore = 0;
    SetLives(startLives);
}

void Controller::SetLives(int lives){
    playerLives = lives;
}

void Controller::IncreaseScore(){
    playerScore++;
}

void Controller::KillPlayer(){
    sleep(seconds(2));
    Restart();
}

void Controller::KillEnemy(){

}

void Controller::Pause(){

}

void Controller::Restart(){
    playerScore = 0;
}

void Controller::Update(){

}

void Controller::ChangeLevel(){

}

int Controller::GetScore(){
    return playerScore;
}

int Controller::GetLives(){
    return playerLives;
}
