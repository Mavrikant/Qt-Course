#ifndef DATECLASS_H
#define DATECLASS_H

#include <iostream>
#include <string>

using namespace std;

class DateClass{
public:
    string m_date_sep = ".";
    DateClass(int y,int m,int d,string sep=".");
    /* NOTE: "(DateClass Diff)" Parametre ismi daha aciklayici olarak girilebilir. */
    /* Sinifin kullanicisini yaniltacak isimlendirmelerden kacinilmalidir.         */
    int64_t DiffDate(DateClass Diff);
    bool SetDate(int y,int m,int d);
    void print();
    /* NOTE: Operator overloading yapildiysa DiffDate fonksiyonu private bolume alinabilir. */
    /* Interface de ayni isi yapan birden cok fonksiyonun bulunmasi kafa karistirir.        */
    /* Sinifin interface i (arayuzu) olabildigi kadar sade olmalidir.                       */
    int64_t operator - (DateClass Diff){
        return DiffDate(Diff);
    }

    /* NOTE: Source ve header dosyalari icerisinde kullanilan indentation bir biri ile tutarlı olmalidir. */
private:
        int m_year;
        int m_month;
        int m_day;
};

#endif // DATECLASS_H
