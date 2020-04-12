#include <iostream>
#include "dateclass.h"
using namespace std;


//TODO
//2 tarih arasındaki gün farkını hesaplayan fonk yaz.

int main()
{
    DateClass today { 2020, 01, 16 };
    DateClass birth_day{2000,01,15,"-"};

    //today.m_day = 17; // use member selection operator to select a member variable of the class
    today.SetDate(2020, 01, 17);
    today.print(); // use member selection operator to call a member function of the class
    birth_day.print();

    return 0;
}
