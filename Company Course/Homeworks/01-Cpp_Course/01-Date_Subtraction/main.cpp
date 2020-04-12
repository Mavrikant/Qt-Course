#include <iostream>
#include "dateclass.h"
using namespace std;

int main()
{
    DateClass today { 2020, 2, 26,"-" };
    DateClass birth_day{1993,5,12,"-"};
    cout << "Today: ";
    today.print();
    cout <<"Birth Day: ";
    birth_day.print();
    cout << endl << "Differance between two date" << endl;
    cout << "Method: " << birth_day.DiffDate(today) << endl;
    cout << "Operator overloading: " << birth_day-today << endl;
    cout << endl << "Age: " << (birth_day-today)/365.0 << endl;
    return 0;
}
