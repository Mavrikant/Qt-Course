#ifndef STUDENT_H
#define STUDENT_H
#include "human.h"

class Student : public Human{
public:
    Student(m_property studying = Normal, m_property m_walking = Normal, m_property m_running = Normal, m_property m_speaking = Normal, m_property m_eating = Normal, m_property m_sleeping = Normal, m_property m_reading = Normal);
    void setStudying(m_property studying=Normal);
    m_property getStudying();

private:
    m_property m_studying;
};

#endif // STUDENT_H
