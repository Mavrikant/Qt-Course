#ifndef PASSENGER_H
#define PASSENGER_H
#include "behavior.h"

class Passenger:public Behavior
{
public:
    Passenger();
    virtual void Behave(void) override;
};

#endif // PASSENGER_H
