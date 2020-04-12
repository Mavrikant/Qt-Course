#ifndef WORKER_H
#define WORKER_H
#include <iostream>

class Worker
{
public:
    enum shiftType {Normal, Night};
    Worker(unsigned int salary, unsigned int workingHour, Worker::shiftType shift);

    void setSalary(unsigned int salary);
    void setWorkingHour(unsigned int workingHour);
    void setShiftType(shiftType shift);

    void printAllProperties();

    unsigned int getSalary();
    unsigned int getWorkingHour();
    shiftType getShiftType();

    std::string shiftTypeToString(Worker::shiftType shift);

private:
    unsigned int m_salary;
    unsigned int m_workingHour;
    shiftType m_shift;
};

#endif // WORKER_H
