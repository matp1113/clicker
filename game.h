#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <stdlib.h>
#include <QPointF>
#include "movingPoint.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    int getX();
    int getY();

signals:
    void randomized();

public slots:
    void start();
    void stop();

private:
    MovingPoint *point;
    bool play = false;
    std::tuple<int, int> xy;
};

#endif // GAME_H
