#include "device.h"
#include <iostream>

Device::Device(std::string serial, unsigned int price)
{
    this->m_serial=serial;
    this->m_price=price;
}

void Device::print(){
    std::cout<<"Serial Number: " << m_serial<<std::endl;
    std::cout<<"Price: " <<m_price <<std::endl;
}
