#ifndef MOVINGPOINT_H
#define MOVINGPOINT_H

#include <stdlib.h>
#include <math.h>
#include <tuple>

class MovingPoint{
private:
    int x = 50;
    int y = 50;
    int velocity = 100;

public:
    std::tuple<int, int> rand_pos();
    MovingPoint() = default;
};

#endif // MOVINGPOINT_H
