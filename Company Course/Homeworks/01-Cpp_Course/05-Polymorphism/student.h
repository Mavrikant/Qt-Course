#ifndef STUDENT_H
#define STUDENT_H
#include "behavior.h"

class Student:public Behavior
{
public:
    Student();
    virtual void Behave(void) override;
};

#endif // STUDENT_H
