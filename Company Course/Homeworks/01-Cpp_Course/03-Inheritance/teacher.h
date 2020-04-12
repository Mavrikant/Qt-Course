#ifndef TEACHER_H
#define TEACHER_H
#include "human.h"

class Teacher : public Human{
public:
    Teacher(Human::m_property teaching = Normal, m_property m_walking = Normal, m_property m_running = Normal, m_property m_speaking = Normal, m_property m_eating = Normal, m_property m_sleeping = Normal, m_property m_reading = Normal);
    void setTeaching(m_property studying=Normal);
    m_property getTeaching();

private:
    m_property m_teaching;
};

#endif // TEACHER_H
