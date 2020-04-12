#include "pedestrian.h"
#include "movingobject.h"
#include <iostream>

Pedestrian::Pedestrian()
{
    m_objectType="Pedestrian";
}

void Pedestrian::go()
{
    std::cout<<"Pedestrian GO"<<std::endl;
}

void Pedestrian::stop()
{
    std::cout<<"Pedestrian STOP"<<std::endl;
}
