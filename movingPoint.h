#ifndef MOVINGPOINT_H
#define MOVINGPOINT_H

#include <stdlib.h>
#include <tuple>

class MovingPoint{
private:
    int _x = 50;
    int _y = 50;
    int _velocity = 10;

public:
    std::tuple<int, int> rand_pos();
    MovingPoint() = default;
    void setVelocity(int vel);
    int getVelocity();
};

#endif // MOVINGPOINT_H
