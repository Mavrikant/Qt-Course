# QString Sınıfı Kullanımı
  
* Listede verilen tüm fonksiyonları ve sınıfın diğer özelliklerini kapsayacak şekilde, aşağıda doldurmanız istenen kod kısımlarını doldurunuz.  
* Bu bilgilerin hepsi dersimizde anlatıldı. Ders notlarının içerisinden kullanım örneklerine erişebilirsiniz. Daha detaylı bilgi için tüm QString sınıfına ait dokümantasyona [linkten](https://doc.qt.io/qt-5/qstring.html) ulaşabilirsiniz.  

**Önemli Not:** Yazacağınız kodda aşağıda verilenler en az 1 kez kullanılmalıdır.  

```cpp
 
    // 1.  operator==
    // 2.  begin
    // 3.  append
    // 4.  toLower
    // 5.  count
    // 6.  operator[]
    // 7.  left
    // 8.  insert
    // 9.  size
    // 10. clear
    // 11. at
    // 12. arg
    // 13. mid
    // 14. prepend
    // 15. chop
    // 16. compare
    // 17. replace
    // 18. toUpper
    // 19. right
    // 20. isEmpty
    // 21. remove
    // 22. end
    // 23. QString::Iterator
    // 24. operator+=
    // 25. length
 
```

## Kod
Aşağıdaki kaynak kodu kopyalayarak ödeve başlayabilirsiniz.

```cpp
 
    #include <QCoreApplication>
    #include <QTextStream>

    int main(void)
    {
        QTextStream out(stdout);
        QString str = "";

        /* code... */
        /* OUTPUT: "str: ogreniyoruz." */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: OGRENIYORUZ." */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: OGRENIYORUZ. Egitimleri" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: OGRENIYORUZ. Egitimleri her cuma saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: ogreniyoruz. egitimleri her cuma saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: Qt ogreniyoruz. egitimleri her cuma saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: Qt ogreniyoruz. egitimleri her PERSEMBE saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: egitimleri her PERSEMBE saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: Egitimleri her PERSEMBE saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str is not empty!" */

        /* code... */
        /* OUTPUT: "str: " */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str is empty!" */

        /* code... */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << "str: " << str << endl;

        /* Range based for loop code... */
        /* OUTPUT: "Q*t* *o*g*r*e*n*i*y*o*r*u*z*.*" */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << endl;
        out << "str: " << str << endl;

        /* foreach loop code... */
        /* OUTPUT: "Q-t- -o-g-r-e-n-i-y-o-r-u-z-.-" */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << endl;
        out << "str: " << str << endl;

        /* for loop code with iterator... */
        /* OUTPUT: "Q.t. .o.g.r.e.n.i.y.o.r.u.z..." */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << endl;
        out << "str: " << str << endl;

        /* traditional for loop code with usage of string size... */
        /* OUTPUT: "Q`t` `o`g`r`e`n`i`y`o`r`u`z`.`" */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << endl;
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "ruz." */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "Qt og" */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "reniy" */
        /* OUTPUT: "str: Qt ogreniyoruz." */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: str: Qt ogreni" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str: Egitimleri her cuma saat %1:%2'da %3!" */
        out << "str: " << str << endl;

        int hh = 14, mm = 30;
        /* code... */
        /* OUTPUT: "str: Egitimleri her cuma saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str contains 44 characters!"; */
        /* OUTPUT: "str: Egitimleri her cuma saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;

        /* code... */
        /* OUTPUT: "str contains 44 characters!"; */
        /* OUTPUT: "str: Egitimleri her cuma saat 14:30'da yapiyoruz!" */
        out << "str: " << str << endl;


        QString str1 = "Egitimleri her cuma saat 14:30'da yapiyoruz!";
        /* code... */
        /* OUTPUT: "str, str1 are equal"; */

        /* code... */
        /* OUTPUT: "str, str1 are equal"; */

        return 0;
    }


```

## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 09.04.2020 Saat: 12:00**

