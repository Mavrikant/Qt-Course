# Matrix Operation Class

Aşağıda verilen test kodunun tamamen legal olması için gerekli olan Matrix Operation sınıfını oluşturunuz.  
**Önemli Not:** Sınıfı kolaylık olması açısından 2x2 kare matrix ile işlem yapacak şekilde oluşturun.

## 1  --> operator+
Vektörel toplama yapar. İki matrisin aynı indeksli olan elemanlarını toplar.
## 2  --> operator+=
Vektörel toplama yapar. İki matrisin aynı indeksli olan elemanlarını toplar.
## 3  --> operator-
Vektörel çıkarma yapar. İki matrisin aynı indeksli olan elemanlarını çıkarır.
## 4  --> operator-=
Vektörel çıkarma yapar. İki matrisin aynı indeksli olan elemanlarını çıkarır.
## 5  --> operator*
Vektörel çarpma yapar. İki matrisin aynı indeksli olan elemanlarını çarpar.
## 6  --> operator*=
Vektörel çarpma yapar. İki matrisin aynı indeksli olan elemanlarını çarpar.
## 7  --> operator/
Vektörel bölme yapar. İki matrisin aynı indeksli olan elemanlarını böler.
## 8  --> operator/=
Vektörel bölme yapar. İki matrisin aynı indeksli olan elemanlarını böler.
## 9  --> operator=
Sağ operandı olan matrisin içeriğini sol operandı olan matrisin içeriğine yazar.
## 10 --> operator==
İki matrisin aynı indeksli elemanlarının birebir eşit olması şartını kontrol eder.
## 11 --> operator!=
İki matrisin aynı indeksli elemanlarının birebir eşit olmaması şartını kontrol eder.
## 12 --> operator<
İki matrisi küçüklük yönünden karşılaştırır. Sol operand olarak verilen matrisin sağ operand olarak verilen matristen tüm indekslerindeki elemanların küçük olması şartını arar.
## 13 --> operator<=
İki matrisi küçüklük veya eşitlik yönünden karşılaştırır. Sol operand olarak verilen matrisin sağ operand olarak verilen matristen tüm indekslerindeki elemanların küçük veya eşit olması şartını arar.
## 14 --> operator>
İki matrisi büyüklük yönünden karşılaştırır. Sol operand olarak verilen matrisin sağ operand olarak verilen matristen tüm indekslerindeki elemanların büyük olması şartını arar.
## 15 --> operator>=
İki matrisi büyüklük veya eşitlik yönünden karşılaştırır. Sol operand olarak verilen matrisin sağ operand olarak verilen matristen tüm indekslerindeki elemanların büyük veya eşit olması şartını arar.
## 16 --> operator<<
Matrisi matris formatında konsola yazdırmak için kullanılır.
## 17 --> operator>>  
Konsoldan girilen değerleri matrisin içerisine alır.
## 18 --> operator++ (prefix)
Matrisin tüm elemanlarını 1 arttırır.
**Önemli Not:** Geri dönüş değeri yazdırıldığında artmış değer gözlemlenmelidir.
## 19 --> operator-- (prefix)
Matrisin tüm elemanlarını 1 azaltır.
**Önemli Not:** Geri dönüş değeri yazdırıldığında azalmış değer gözlemlenmelidir.
## 20 --> operator++ (postfix)
Matrisin tüm elemanlarını 1 arttırır.
**Önemli Not:** Geri dönüş değeri yazdırıldığında arttırma işlemi yapılmadan önceki değer gözlemlenmelidir.
## 21 --> operator-- (postfix)
Matrisin tüm elemanlarını 1 azaltır.
**Önemli Not:** Geri dönüş değeri yazdırıldığında azaltma işlemi yapılmadan önceki değer gözlemlenmelidir.


## Test Kodu

```cpp

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
 
```

## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 01.04.2020 Saat: 12:00**

