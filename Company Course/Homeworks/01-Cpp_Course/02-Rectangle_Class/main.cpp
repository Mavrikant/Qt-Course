#include <iostream>
#include "rectangle.h"


int main()
{
    Rectangle Rectangle_1 (3,4);
//    Rectangle_1.set_length(2);
    Rectangle_1.set_width(3);

    std::cout<<"Length: "<<Rectangle_1.get_length()<<std::endl;
    std::cout<<"Width: "<<Rectangle_1.get_width()<<std::endl;
    std::cout<<"Area: "<<Rectangle_1.get_area()<<std::endl;
    std::cout<<"Perimeter: "<<Rectangle_1.get_perimeter()<<std::endl;
}
