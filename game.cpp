#include "game.h"
#include <stdlib.h>
#include <QDebug>
#include <thread>
#include <chrono>

Game::Game(QObject *parent)
    : QObject{parent}
{
    _point = new MovingPoint();
    _timer = new Timer();
    _player = new Player();
    _player->setName("Mat");
    connect(this, SIGNAL(changeTime()), _timer, SLOT(changeTime()));
    connect(_timer, SIGNAL(timeChanged(QString)), this, SLOT(receiveTime(QString)));
}

bool Game::isPlay() const
{
    return _play;
}

void Game::setPlay(bool play)
{
    _play = play;
    emit playChanged();
    if(play){
        start();
    }
}

void Game::start(){
    _play = true;
    int i = 0;
    while(true){
        QCoreApplication::processEvents();
        if(_play == false){
            break;
        }
        i++;
        if(i == 10){
            i = 0;
            _points -= 1;
            _supportTimer += 1;
            emit dockingPoints(_points);
            emit changeTime();
            if(_points == 0){
                stop();
                _player->setSupport(_supportTimer);
                _player->setTime(_timer->toString());
            }
        }
        xy = _point->rand_pos();
        qDebug() << "from game: " << "x=" << QString::number(getX()) << "y=" << QString::number(getY()) << " | ";
        emit randomized(getX(), getY());
        std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
    }
}

void Game::stop()
{
    setPlay(false);
}

void Game::addPoint()
{
    if(_play == true){
        _points = _points + 1;
    }
}

int Game::receivePoints()
{
    return _points;
}

void Game::receiveTime(QString timeString)
{
    emit changedTime(timeString);
}

int Game::getX()
{
    return std::get<0>(xy);
}

int Game::getY()
{
    return std::get<1>(xy);
}

void Game::setPointVelocity(int vel)
{
    _point->setVelocity(vel);
}

int Game::getPointVelocity()
{
    return _point->getVelocity();
}
