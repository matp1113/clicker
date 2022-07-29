#include "game.h"
#include <stdlib.h>
#include <thread>
#include <chrono>

Game::Game(QObject *parent)
    : QObject{parent}
{
    point = new MovingPoint();
}

int Game::getX()
{
   return std::get<0>(this->xy);
}

int Game::getY()
{
    return std::get<1>(this->xy);
}

void Game::start(){
    play = true;
    for(;;){
        if(!play){
            break;
        }
        xy = point->rand_pos();
        emit randomized();
        std::this_thread::sleep_for(std::chrono::nanoseconds(10000));
    }
}

void Game::stop()
{
    play = false;
}
