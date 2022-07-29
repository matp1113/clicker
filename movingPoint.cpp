#include "movingPoint.h"

#include <QDebug>

std::tuple<int, int> MovingPoint::rand_pos() {
    x = x + round((rand()*velocity)-(velocity/2));
    y = y + round((rand()*velocity)-(velocity/2));
    if (x < 0){
        x = 0;
    }
    if(y < 0){
        y = 0;
    }
    qDebug() << "x=" << QString::number(x) << "y=" << QString::number(y) << " | ";
    return std::make_tuple(x, y);
}

