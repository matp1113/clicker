#include "player.h"

#include <QDebug>
#include <QDir>
#include <QFile>

Player::Player(QObject *parent)
    : QObject{parent}
{
    qDebug() << QDir().absolutePath();
}

void Player::setName(QString name)
{
    _name = name;
}

void Player::setTime(QString time)
{
    _time = time;
    save();
}

void Player::setSupport(int support)
{
    _support = support;
}

void Player::save()

{
    QFile file("C:/Users/Mateusz/Desktop/soft_int_qt/build-clicker-Desktop_Qt_6_3_1_MinGW_64_bit-Debug/results.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file);

            stream << "Player name: " << _name << " | " << "time achieved: " << _time << " | " << "ranking points: " << _support << '\n';

            file.close();
            qDebug() << "Writing finished";
        }
}
