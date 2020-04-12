#ifndef HUMAN_H
#define HUMAN_H
#include "customer.h"
#include "passenger.h"
#include "son.h"
#include "student.h"

class Human:public Customer,public Passenger,public Son,public Student
{
public:
    Human();
    void Behave(void) override;
};

#endif // HUMAN_H
