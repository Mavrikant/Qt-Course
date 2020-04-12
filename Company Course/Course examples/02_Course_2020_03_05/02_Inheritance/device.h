#ifndef DEVICE_H
#define DEVICE_H
#include <string.h>
#include <iostream>

class Device
{
public:
    Device(std::string m_serial, unsigned int m_price);
    void print();

protected:
    std::string m_serial;
    unsigned int m_price;
};

#endif // DEVICE_H
