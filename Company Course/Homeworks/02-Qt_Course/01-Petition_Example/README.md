# Dilekçe Örneği

Aşağıda verilen dilekçe örneğinde boş olan bölümleri öğrenci bilgileri ile doldurunuz.
* Dilekçe başlığı ve il bilgisinin tamamı büyük harfe çevrilmelidir.
* Öğrencinin bölümü girilmelidir.
* Öğrencinin numarası girilmelidir.
* Öğrencinin sınıfı girilmelidir.
* "Universitemiz Egitim-Ogretim ve Sinav Yonetmeliginin  6. Maddesinin 4. fikrasi geregi, " yazısının bulunduğu kısım silinmeli, virgülden sonraki kısım büyük harfle başlamalıdır.
* Eklenecek / çıkarılacak ders sayısı tek olmadığı için "dersi / " kısmı silinmelidir.
* Ders sayısına uygun olarak fazla olan "Ders 5:", ... silenmelidir.
* Ders bilgileri "Ders 1: Analog Circuit" gibi eklenmelidir.
* Ders ekleme yapılacaksa " / birakmak" kısmı silinmelidir.
* Ders çıkarma yapılacaksa "eklemek / " kısmı silinmelidir.
* Arz kısmının ilk harfi büyük diğer harfleri küçük olmalıdır.
* %1 argümanı yerine öğrencinin bilgileri girilmelidir.
* %2 argümanı yerine program çalıştırıldığı zamanda tarih neyse GG/AA/YYYY şeklinde formatlanarak girilmelidir. İpucu olarak [linkteki](https://doc.qt.io/qt-5/qdate.html) sınıf dökümanını inceleyebilirsiniz. Aşağıdaki fonksiyonların kullanımına bakmanız yeterli olacaktır.
```cpp
 
    #include <QDate>
    // QDate   currentDate()
    // QString QDate::toString(const QString &format) const
 
```
* Fakulteniz, gereğini bilgilerinize arz ederim ve Ders X: kısmına 4 karakter <pre>"    "</pre> boşluk eklenerek eklenerek paragraf başı yapılmalıdır.
  
Yazacağınız kod içerisinde QString sınıfı içerisinde bulunan ve ihtiyaç duyabileceğiniz bazı fonksiyonlar aşağıdaki gibidir. Aşağıdaki metodlara ve tüm QString sınıfına ait dokümantasyona [linkten](https://doc.qt.io/qt-5/qstring.html) ulaşabilirsiniz.

```cpp
 
    #include <QTextStream>
    // 1.  split
    // 2.  contains
    // 3.  toUpper
    // 4.  replace
    // 5.  prepend
    // 6.  toLower
    // 7.  remove
    // 8.  indexOf
    // 9.  arg
    // 10. insert
 
```
## Kod
Aşağıdaki dilekçe örneğini kopyalayarak ödeve başlayabilirsiniz.

```cpp
 
    QTextStream out(stdout);

    QString petition = "\
    \n--------------------------------------------------------------------------------\
    \n\
    \n\
    \n\
    \n\
    \n\
    \n\
    \n                  S. U. EDEBIYAT fakultesi DEKANLIGI'NA\
    \n                                                               konya\
    \n\
    \n\
    \n\
    \nFakulteniz ......... Bolumu, ......... numarali ......... sinif ogrencisiyim.\
    \nUniversitemiz Egitim-Ogretim ve Sinav Yonetmeliginin  6. Maddesinin 4. fikrasi geregi, universitemiz senatosunca her Egitim-Ogretim yilinda akademik takvimde belirtilen ders ekleme-birakma suresi icerisinde asagida belirtilen dersi / dersleri,              eklemek / birakmak  istiyorum.\
    \n\
    \nGEREGINI ARZ EDERIM.\
    \n\
    \n\
    \n\
    \nDers 1: \
    \nDers 2: \
    \nDers 3: \
    \nDers 4: \
    \nDers 5: \
    \nDers 6: \
    \nDers 7: \
    \n\
    \n\
    \n\
    \n                                                    %1\
    \n                                                     %2\
    \n\
    \n\
    \n\
    \n\
    \n\
    \n\
    \n--------------------------------------------------------------------------------\
    ";

    out << petition << endl;

    // ...
    // codes
    // ...

    out << petition << endl;
 
```

## Konsol Çıktıları

```
--------------------------------------------------------------------------------






                  S. U. EDEBIYAT fakultesi DEKANLIGI'NA
                                                               konya



Fakulteniz ......... Bolumu, ......... numarali ......... sinif ogrencisiyim.
Universitemiz Egitim-Ogretim ve Sinav Yonetmeliginin  6. Maddesinin 4. fikrasi geregi, universitemiz senatosunca her Egitim-Ogretim yilinda akademik takvimde belirtilen ders ekleme-birakma suresi icerisinde asagida belirtilen dersi / dersleri,              eklemek / birakmak  istiyorum.

GEREGINI ARZ EDERIM.



Ders 1:
Ders 2:
Ders 3:
Ders 4:
Ders 5:
Ders 6:
Ders 7:



                                                    %1
                                                     %2






--------------------------------------------------------------------------------
```

```
--------------------------------------------------------------------------------






                  S. U. EDEBIYAT FAKULTESI DEKANLIGI'NA
                                                               KONYA



    Fakulteniz Elektronik Muhendisligi Bolumu, 171021012 numarali 2. sinif ogrencisiyim.
Universitemiz senatosunca her Egitim-Ogretim yilinda akademik takvimde belirtilen ders ekleme-birakma suresi icerisinde asagida belirtilen dersleri, eklemek istiyorum.

    Geregini arz ederim.



    Ders 1: Analog Circuit
    Ders 2: Math 1
    Ders 3: Math 2
    Ders 4: Digital Circuit






                                                    Onder GORMEZ
                                                     04/04/2020






--------------------------------------------------------------------------------
```


## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 09.04.2020 Saat: 12:00**

