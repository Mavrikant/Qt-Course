#include <iostream>
#include "matrix.h"

using namespace std;

int main(void)
{
    Matrix<int> mi1(10, 20, 30, 40), mi2(5, 4, 3, 2), mi3;

    if (mi1 == mi1) {
        cout << "mi1:" << endl << mi1 << endl << "is equal to mi1:" << endl << mi1 << endl;
    }

    if (mi1 != mi2) {
        cout << "mi1:" << endl << mi1 << endl << "is not equal to mi2:" << endl << mi2 << endl;
    }

    if (mi2 <= mi1) {
        cout << endl << "mi2:" << endl << mi2 << endl << "is lower than or equal to mi1:" << endl << mi1 << endl;
    }

    if (mi2 < mi1) {
        cout << endl << "mi2:" << endl << mi2 << endl << "is lower than to mi1:" << endl << mi1 << endl;
    }

    if (mi1 >= mi2) {
        cout << endl << "mi1:" << endl << mi1 << endl << "is greater than or equal to mi2:" << endl << mi2 << endl;
    }

    if (mi1 > mi2) {
        cout << endl << "mi1:" << endl << mi1 << endl << "is greater than to mi2:" << endl << mi2 << endl;
    }

    mi3 = mi1 + mi2;
    /* WARNING: This should be compile time error! */
    //mi1 + mi2 = mi3;
    cout << mi3 << endl;

    mi3 = mi1 - mi2;
    /* WARNING: This should be compile time error! */
    //mi1 - mi2 = mi3;
    cout << mi3 << endl;

    mi3 = mi1 * mi2;
    /* WARNING: This should be compile time error! */
    //mi1 * mi2 = mi3;
    cout << mi3 << endl;

    mi3 = mi1 / mi2;
    /* WARNING: This should be compile time error! */
    //mi1 / mi2 = mi3;
    cout << mi3 << endl;

    mi1 += mi2;
    cout << mi1 << endl;

    mi1 -= mi2;
    cout << mi1 << endl;

    mi1 *= mi2;
    cout << mi1 << endl;

    mi1 /= mi2;
    cout << mi1 << endl;

    cout << ++mi1 << endl;
    cout << mi1 << endl;

    cout << --mi1 << endl;
    cout << mi1 << endl;

    cout << mi1++ << endl;
    /* WARNING: This should be compile time error! */
    //mi1++ = mi2;
    cout << mi1 << endl;

    cout << mi1-- << endl;
    /* WARNING: This should be compile time error! */
    //mi1-- = mi2;
    cout << mi1 << endl;

    cout << "Enter a Matrix<int> value: ";
    Matrix<int> mi4;
    cin >> mi4;
    cout << "You entered: " << mi4 << endl;

    Matrix<float> mf1(10.3f, 20.5f, 15.1f, 12.3f), mf2(5.2f, 3.3f, 4.1f, 3.2f), mf3;

    if (mf1 == mf1) {
        cout << "mf1:" << endl << mf1 << endl << "is equal to mf1:" << endl << mf1 << endl;
    }

    if (mf1 != mf2) {
        cout << "mf1:" << endl << mf1 << endl << "is not equal to mf2:" << endl << mf2 << endl;
    }

    if (mf2 <= mf1) {
        cout << endl << "mf2:" << endl << mf2 << endl << "is lower than or equal to mf1:" << endl << mf1 << endl;
    }

    if (mf2 < mf1) {
        cout << endl << "mf2:" << endl << mf2 << endl << "is lower than to mf1:" << endl << mf1 << endl;
    }

    if (mf1 >= mf2) {
        cout << endl << "mf1:" << endl << mf1 << endl << "is greater than or equal to mf2:" << endl << mf2 << endl;
    }

    if (mf1 > mf2) {
        cout << endl << "mf1:" << endl << mf1 << endl << "is greater than to mf2:" << endl << mf2 << endl;
    }

    mf3 = mf1 + mf2;
    cout << mf3 << endl;

    mf3 = mf1 - mf2;
    cout << mf3 << endl;

    mf3 = mf1 * mf2;
    cout << mf3 << endl;

    mf3 = mf1 / mf2;
    cout << mf3 << endl;

    mf1 += mf2;
    cout << mf1 << endl;

    mf1 -= mf2;
    cout << mf1 << endl;

    mf1 *= mf2;
    cout << mf1 << endl;

    mf1 /= mf2;
    cout << mf1 << endl;

    cout << ++mf1 << endl;
    cout << mf1 << endl;

    cout << --mf1 << endl;
    cout << mf1 << endl;

    cout << mf1++ << endl;
    cout << mf1 << endl;

    cout << mf1-- << endl;
    cout << mf1 << endl;

    cout << "Enter a Matrix<float> value: ";
    Matrix<float> mf4;
    cin >> mf4;
    cout << "You entered: " << mf4 << endl;
}
