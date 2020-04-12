#ifndef TEACHER_H
#define TEACHER_H

#include "human.h"
#include "worker.h"

class Teacher:public Human, public Worker{

public:
    enum teachingProperty {Low, Average, Excellent};

    Teacher(teachingProperty teaching, unsigned int salary, unsigned int workingHour);
    void setTeaching(teachingProperty teaching);
    teachingProperty getTeaching();

    void printAllProperties();
    static std::string teachingPropertyToString(Teacher::teachingProperty property);

private:
    teachingProperty m_teaching;

};

#endif // TEACHER_H
