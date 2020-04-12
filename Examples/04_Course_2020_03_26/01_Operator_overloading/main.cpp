#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex complex1(1,2);
    Complex complex2(2,3);
    Complex complex3;
    Complex complex4;

    complex3=complex1+complex2;
    complex1.print();
    complex2.print();
    complex3.print();

    std::cout<<"-----------"<<std::endl;

    complex4=complex3 + 6.0;
    complex4.print();

    std::cout<<"-----------"<<std::endl;

    if(complex3<complex4){
        std::cout<<"True. c3 is smaller than c4"<<std::endl;
    }else{
         std::cout<<"False. c3 is not smaller than c4"<<std::endl;
    }
    std::cout<<"-----------"<<std::endl;



    return 0;
}
