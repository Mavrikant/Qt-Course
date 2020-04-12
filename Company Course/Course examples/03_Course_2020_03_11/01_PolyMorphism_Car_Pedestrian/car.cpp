#include "car.h"
#include <iostream>

Car::Car()
{
    m_objectType="Car";
}

void Car::go()
{
    std::cout<<"Car cross"<<std::endl;
}

void Car::stop()
{
    std::cout<<"Car STOP"<<std::endl;
}
