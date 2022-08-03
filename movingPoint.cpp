#include "movingPoint.h"

#include <QDebug>
#include <math.h>
#include <random>

std::tuple<int, int> MovingPoint::rand_pos() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> randomized(0, _velocity);
    _x = _x + round((randomized(mt))-(_velocity/2));

    _y = _y + round((randomized(mt))-(_velocity/2));

    if (_x < 0){
        _x = 0;
    }
    if(_y < 0){
        _y = 0;
    }
    if(_x > 400){
        _x = 400;
    }
    if(_y > 400){
        _y = 400;
    }
    qDebug() << "_x=" << QString::number(_x) << "_y=" << QString::number(_y) << " | ";
    return std::make_tuple(_x, _y);
}

void MovingPoint::setVelocity(int vel)
{
    _velocity = vel;
}

int MovingPoint::getVelocity()
{
    return _velocity;
}

