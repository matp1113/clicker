#include "timer.h"
#include <QDebug>

Timer::Timer(QObject *parent)
    : QObject{parent}
{

}

QString Timer::toString()
{
    return QString::number(_time[0]) + ":" + QString::number(_time[1]) + QString::number(_time[2]) + ":" + QString::number(_time[3]) + QString::number(_time[4]);
}

void Timer::changeTime()
{
    _time[4]++;
    for(int i = 4; i >= 0; i--){
       if(_time[i] == _timeLimit[i]){
           _time[i] = 0;
           _time[i-1] += 1;
       }
    }
    emit timeChanged(toString());
}
