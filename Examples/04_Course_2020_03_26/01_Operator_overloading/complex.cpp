#include "complex.h"
#include <iostream>

Complex::Complex(double r, double i)
{
    this->real=r;
    this->imag=i;
}

Complex Complex::operator+(const Complex &obj)
{
    Complex result;
    result.real=this->real+obj.real;
    result.imag=this->imag+obj.imag;
    return result;
}

Complex Complex::operator-(const Complex &obj)
{
    Complex result;
    result.real=this->real-obj.real;
    result.imag=this->imag-obj.imag;
    return result;
}

bool Complex::operator<(const Complex &obj)
{
    if((this->real*this->real+this->imag*this->imag)<(obj.real*obj.real+obj.imag*obj.imag)){
        return true;
    }
    else{
        return false;
    }
}

Complex Complex::operator+(double In)
{
    Complex result;
    result.real=this->real+In;
    result.imag=this->imag+In;
    return result;
}

Complex Complex::operator-(double In)
{
    Complex result;
    result.real=this->real-In;
    result.imag=this->imag-In;
    return result;
}

void Complex::print()
{
    std::cout<<"("<<this->real<<","<<this->imag<<")"<<std::endl;
}
