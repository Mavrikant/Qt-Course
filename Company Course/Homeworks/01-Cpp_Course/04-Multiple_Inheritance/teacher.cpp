#include "teacher.h"
#include <iostream>

Teacher::Teacher(teachingProperty teaching,unsigned int salary, unsigned int workingHour):Human(), Worker (salary, workingHour, Worker::Normal)
{
    m_teaching=teaching;
}

Teacher::teachingProperty Teacher::getTeaching()
{
    return m_teaching;
}

std::string Teacher::teachingPropertyToString(Teacher::teachingProperty property)
{
    if(property == Low){
        return "Low";
    }
    else if(property==Average){
        return "Average";
    }
    else if(property==Excellent){
        return "Excellent";
    }
    else{
        std::cerr<<"Error: printPropert unknown property";
        return "Error";
    }
}

void Teacher::printAllProperties()
{
    std::cout<<"----Teacher----"<<std::endl;
    std::cout<<"Teaching= "<<teachingPropertyToString(getTeaching())<<std::endl;
    std::cout<<"----Worker----"<<std::endl;
    Worker::printAllProperties();
    std::cout<<"----Human----"<<std::endl;
    Human::printAllProperties();
}
