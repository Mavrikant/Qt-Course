#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "behavior.h"

class Customer:public Behavior
{
public:
    Customer();
    virtual void Behave(void) override;
};

#endif // CUSTOMER_H
