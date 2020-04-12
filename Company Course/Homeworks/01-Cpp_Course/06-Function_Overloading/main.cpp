#include "mathoperations.h"
#include <iostream>
using namespace std;

int main(void)
{
    int i1 = 20, i2 = -10;
    float f1 = 13.5, f2 = -9.3f;
    double d1 = 15.3, d2 = 12.8;
    MathOperations mathOp{};

    /* QUESTION: Derleyici hata verdi mi? Verdiyse hatanın açıklamasını yazın. */
    /* Nedenini kendi cümlelerinizle ifade edin */
    cout << "absolute of " << f2 << " is: " << mathOp.absolute(f2) << endl;
    //Ansver: Hata yok. Fonsiyonun float versiyonu kullanıldı

    /* QUESTION: Derleyici hata verdi mi? Verdiyse hatanın açıklamasını yazın. */
    /* Nedenini kendi cümlelerinizle ifade edin */
    cout << "absolute of " << i2 << " is: " << mathOp.absolute(i2) << endl;
    //Ansver: Hata yok. Fonsiyonun integer versiyonu kullanıldı

    /* NOTE: Ambiguity durumu ile alakalı biraz daha detaylı açıklama yapılabilirdi.         */
    /* Aslında aday 2 fonksiyon var ve bu iki fonksiyondan hangisini kullanacağını derleyici */
    /* seçemiyor. Eğer bunlardan sadece 1 tanesi tanımlanmış olsaydı onu seçecekti.          */
    /* QUESTION: Derleyici hata verdi mi? Verdiyse hatanın açıklamasını yazın. */
    /* Nedenini kendi cümlelerinizle ifade edin */
    //cout << "absolute of " << d1 << " is: " << mathOp.absolute(d1) << endl;
    //Ansver: Hata verdi. Fonsiyonun dobule versiyonu yok.

    /* QUESTION: Derleyici hata verdi mi? Verdiyse hatanın açıklamasını yazın. */
    /* Nedenini kendi cümlelerinizle ifade edin */
    cout << "(" << i1 << ") + " << "(" << i2 << ") = " << mathOp.sum(i1, i2) << endl;
    //Ansver: Hata yok. Fonsiyonun integer versiyonu kullanıldı

    /* QUESTION: Derleyici hata verdi mi? Verdiyse hatanın açıklamasını yazın. */
    /* Nedenini kendi cümlelerinizle ifade edin */
    cout << "(" << d1 << ") + " << "(" << d2 << ") = " << mathOp.sum(d1, d2) << endl;
    //Ansver: Hata yok. Fonsiyonun double versiyonu kullanıldı

    /* QUESTION: Derleyici hata verdi mi? Verdiyse hatanın açıklamasını yazın. */
    /* Nedenini kendi cümlelerinizle ifade edin */
    cout << "(" << f1 << ") + " << "(" << f2 << ") = " << mathOp.sum(f1, f2) << endl;
    //Ansver: warning: implicit conversion increases floating-point precision: 'float' to 'double'
    // IDE uyarı verdi. Compiler floatları double olarak değiştirip kullanıyor.
}
