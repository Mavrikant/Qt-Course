#ifndef HUMAN_H
#define HUMAN_H
#include<iostream>

class Human{
public:
    enum m_property {Slow, Normal, Fast};

    Human(m_property m_walking=Normal,m_property m_running=Normal,m_property m_speaking=Normal,m_property m_eating=Normal,m_property m_sleeping=Normal,m_property m_reading=Normal);

    void setWalking(m_property m_walking);
    void setRunnig(m_property m_running);
    void setSpeaking(m_property m_speaking);
    void setEating(m_property m_eating);
    void setSleeping(m_property m_sleeping);
    void setReading(m_property m_reading);
    static std::string printProperty(m_property property);

    m_property getWalking();
    m_property getRunnig();
    m_property getSpeaking();
    m_property getEating();
    m_property getSleeping();
    m_property getReading();

private:       
    m_property m_walking;
    m_property m_running;
    m_property m_speaking;
    m_property m_eating;
    m_property m_sleeping;
    m_property m_reading;
};

#endif // HUMAN_H
