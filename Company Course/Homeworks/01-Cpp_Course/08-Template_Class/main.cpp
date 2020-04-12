#include <iostream>
#include "calculator.h"

using namespace std;

/* NOTE: Nice job :) */
/* NOTE: Type bilgisi yazdırılabilirdi. */

int main(void)
{
    int i1 = 20, i2 = -10;
    double d1 = 13.5, d2 = -9.3;
    float f1 = 12.8f, f2 = 13.8f;

    cout << "i1 + i2 = " << Calculator<int>::sum(i1,i2) << endl;
    cout << "i1 - i2 = " << Calculator<int>::sub(i1,i2) << endl;
    cout << "i1 * i2 = " << Calculator<int>::mul(i1,i2) << endl;
    cout << "i1 / i2 = " << Calculator<int>::div(i1,i2) << endl;

    cout << "---------------------------------------------"<<endl;
    cout << "d1 + d2 = " << Calculator<double>::sum(d1,d2) << endl;
    cout << "d1 - d2 = " << Calculator<double>::sub(d1,d2) << endl;
    cout << "d1 * d2 = " << Calculator<double>::mul(d1,d2) << endl;
    cout << "d1 / d2 = " << Calculator<double>::div(d1,d2) << endl;

    cout << "---------------------------------------------"<<endl;
    cout << "f1 + f2 = " << Calculator<float>::sum(f1,f2) << endl;
    cout << "f1 - f2 = " << Calculator<float>::sub(f1,f2) << endl;
    cout << "f1 * f2 = " << Calculator<float>::mul(f1,f2) << endl;
    cout << "f1 / f2 = " << Calculator<float>::div(f1,f2) << endl;
}
