#ifndef SON_H
#define SON_H
#include "behavior.h"

class Son:public Behavior
{
public:
    Son();
    virtual void Behave(void) override;
};

#endif // SON_H
