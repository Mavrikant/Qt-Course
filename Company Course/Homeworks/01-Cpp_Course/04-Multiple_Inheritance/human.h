#ifndef HUMAN_H
#define HUMAN_H
#include<iostream>

class Human{
public:
    enum property {Slow, Normal, Fast};

    Human(property m_walking=Normal,property m_running=Normal,property m_speaking=Normal,property m_eating=Normal,property m_sleeping=Normal,property m_reading=Normal);

    void setWalking(property m_walking);
    void setRunnig(property m_running);
    void setSpeaking(property m_speaking);
    void setEating(property m_eating);
    void setSleeping(property m_sleeping);
    void setReading(property m_reading);
    static std::string propertyToString(property property);
    void printAllProperties();

    property getWalking();
    property getRunning();
    property getSpeaking();
    property getEating();
    property getSleeping();
    property getReading();

private:
    property m_walking;
    property m_running;
    property m_speaking;
    property m_eating;
    property m_sleeping;
    property m_reading;
};

#endif // HUMAN_H
