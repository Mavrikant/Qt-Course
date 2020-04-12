#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include "movingobject.h"

class Pedestrian : public MovingObject
{
public:
    Pedestrian();
    ~Pedestrian(){}
    void go();
    void stop();
};

#endif // PEDESTRIAN_H
