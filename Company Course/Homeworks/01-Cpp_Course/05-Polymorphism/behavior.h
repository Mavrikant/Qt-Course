#ifndef BEHAVIOR_H
#define BEHAVIOR_H


class Behavior
{
public:
    Behavior();
    virtual ~Behavior();
    virtual void Behave(void) = 0;
};

#endif // BEHAVIOR_H
