#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
#include <iostream>
#include <string.h>

class MovingObject
{
public:
    MovingObject(std::string objectType="unknown");
    virtual ~MovingObject(){}
    virtual void go()=0;
    virtual void stop()=0;
    std::string m_objectType;
};

#endif // MOVINGOBJECT_H
