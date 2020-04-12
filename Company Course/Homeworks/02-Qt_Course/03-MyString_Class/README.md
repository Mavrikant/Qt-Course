# MyString Class Implementation

Qt’nin QString sınıfından MyString adında bir sınıf türetiniz. MyString sınıfı için eksi (-) operatörüne yeni bir işlev yükleyiniz. Bu işlev yüklemesi bir s1 dizgesinde s2 dizgesi yer alıyorsa onu siler ve yeni bir kopya olarak döndürür.  
* Kodunuzu test etmek için aşağıdaki kod parçasını kullanınız.
* Soruda farklı yöntemler izlenebilir. İstediğiniz metodları kullanarak implementasyonu gerçekleştirebilirsiniz.
* IndexOf fonksiyonuna ihtiyacınız olabilir. Fonksiyon ile alakalı bilgilere **Qt üzerinde fonksiyonun isminin üzerine gelerek F1 tuşu ile ulaşabilirsiniz**.

## Kod
Aşağıdaki kaynak kodu kopyalayarak ödeve başlayabilirsiniz.

```cpp
 
    #include <QCoreApplication>

    #include "mystring.h"

    int main(void)
    {
        QTextStream out(stdout);

        MyString str1("Mycarcarcar");
        MyString str2("car");
        MyString str3;
        str3 = str1 - str2;

        //str3 = "My"
        out << "str3 = \"" << str3 << "\"" << endl;

        //QCOMPARE(str3, MyString("My"));

        return 0;
    }
 
```

## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 09.04.2020 Saat: 12:00**

