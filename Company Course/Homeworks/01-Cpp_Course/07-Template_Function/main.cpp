#include <iostream>

using namespace std;

/* NOTE: Nice job :) */

template <class T>
void mySwap (T &a, T &b) {
    T temp;
    temp =a;
    a=b;
    b=temp;
}

int main(void)
{
    int i1 = 20, i2 = -10;
    double d1 = 13.5, d2 = -9.3;
    char ch1 = 'A', ch2 = 'C';

    cout << "---------- Initial ----------"<<endl;
    cout << "i1: " << i1 << "\t\t i2: " << i2 << endl;
    cout << "d1: " << d1 << "\t d2: " << d2 << endl;
    cout << "ch1: " << ch1 << "\t\t ch2: " << ch2 << endl;

    mySwap(i1,i2);
    mySwap(d1,d2);
    mySwap(ch1,ch2);

    cout << "---------- Swapped ----------"<<endl;
    cout << "i1: " << i1 << "\t\t i2: " << i2 << endl;
    cout << "d1: " << d1 << "\t d2: " << d2 << endl;
    cout << "ch1: " << ch1 << "\t\t ch2: " << ch2 << endl;
}
