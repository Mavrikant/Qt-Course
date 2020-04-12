#include "worker.h"
#include <iostream>

Worker::Worker(unsigned int salary,unsigned int workingHour,Worker::shiftType shift)
{
    m_salary=salary;
    m_workingHour=workingHour;
    m_shift=shift;
}

void Worker::setSalary(unsigned int salary)
{
    m_salary=salary;
}

void Worker::setWorkingHour(unsigned int workingHour)
{
    m_workingHour=workingHour;
}

void Worker::setShiftType(Worker::shiftType shift)
{
    m_shift=shift;
}

void Worker::printAllProperties()
{
    std::cout<<"Salary= "<<getSalary()<<std::endl;
    std::cout<<"Working Hour= "<<getWorkingHour()<<std::endl;
    std::cout<<"Shift= "<<shiftTypeToString(getShiftType())<<std::endl;
}

std::string Worker::shiftTypeToString(Worker::shiftType shift)
{
    if(shift == Normal){
        return "Normal";
    }
    else if(shift==Night){
        return "Night";
    }
    else{
        std::cerr<<"Error: shiftTypeToString unknown shift";
        return "Error";
    }
}

unsigned int Worker::getSalary()
{
    return m_salary;
}

unsigned int Worker::getWorkingHour()
{
    return m_workingHour;
}

Worker::shiftType Worker::getShiftType()
{
    return m_shift;
}
