#ifndef CAR_H
#define CAR_H
#include "movingobject.h"

class Car : public MovingObject
{
public:
    Car();
    ~Car(){}
    void go();
    void stop();
};

#endif // CAR_H
