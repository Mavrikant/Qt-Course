# Jenerik Küme Sınıfı

Herhangi bir tür üzerinde küme işlemlerini yapabilen, aşağıda genel özellikleri verilmiş olan jenerik küme sınıfını yazınız.

## Özellikler

* << operatörünün sağ operandı olarak verilen sayıyı kümeye eklesin. (Örneğin: set << 3)
    * Kümeye daha önce eklenmiş bir sayı tekrar eklenmek istenirse eklemesin.
    * Kümenin maksimum eleman sayısı kümeye eklenen eleman sayısına eşitse, yeni bir ekleme isteği durumunda ekleme yapmasın.  
* Bir sayının daha önceden eklenip eklenmediği kontrol edilebilsin.
* Kümeye eklenen sayıları ekrana yazdırabilsin. **Print ederken küme elemanlarını küçükten büyüğe doğru sıralayınız ve ekrana yazdırınız.**
* İki küme arasında alt küme ilişkisinin olup olmadığını kontrol eden bir fonksiyonu olsun.
    * Bu işlemi < operatör ile gerçekleştirsin. (Örneğin set1, set2 kümesinin alt kümesi midir sorgusu: if (set1 < set2))
    * Boş kümenin tüm kümelerin alt kümesi olduğu unutulmamalıdır.

# Test Kodu

```cpp
 
#include <iostream>
#include <myset.h>

using namespace std;

int main()
{
    MySet<int> set1;

    for(int i = 0; i < 5; i++) {
        set1.insert(3 * i + 1);
    }

    cout << "set 1" << endl;
    set1.print();

    MySet<int> set2;

    for(int i = 0; i < 5; i++) {
        set2.insert(2 * i + 1);
    }

    cout << "set 2" << endl;
    set2.print();

    MySet<int> set3;

    for(int i = 0; i < 5; i++){
        set3.insert(2 * i + 1); // 1, 3, 5,  7,  9
        set3.insert(3 * i + 1); // 1, 4, 7, 10, 13
    }
    cout << "set3 = set1 + set2" << endl;
    set3.print();

    MySet<int> set4, set5;

    for(int i = 0; i < 5; i++) {
        set4 << 4 * i + 1;
    }
    cout << "set 4" << endl;
    set4.print();

    /* WARNING: set5 ve set4 un icerisinde 2, 3, 4 un bulunmasi gerekiyor. */
    /* Buna dikkat edin!                                           */
    set5 = set4 << 2 << 3 << 4;

    cout << "set 5" << endl;
    set5.print();

    cout << "set 4" << endl;
    set4.print();

    MySet<int> set6;
    set6 << 0;

    if(set4 < set5) {
        cout << "set4 is subset of set5" << endl;
    }
    else {
        cout << "set4 is not a subset of set5" << endl;
    }

    if(set6 < set5) {
        cout << "set6 is subset of set5" << endl;
    }
    else {
        cout << "set6 is not a subset of set5" << endl;
    }

    MySet<double> doubleSet1{}, doubleSet2{};
    doubleSet1.insert(10.9);
    doubleSet2.insert(10.9);

    doubleSet1.insert(8.3);
    doubleSet2.insert(8.3);

    doubleSet1.insert(10.1);

    if(doubleSet1 < doubleSet2) {
        cout << "doubleSet1 is subset of doubleSet2" << endl;
    }
    else {
        cout << "doubleSet1 is not a subset of doubleSet2" << endl;
    }

    if(doubleSet2 < doubleSet1) {
        cout << "doubleSet2 is subset of doubleSet1" << endl;
    }
    else {
        cout << "doubleSet2 is not a subset of doubleSet1" << endl;
    }

    return 0;
}
 
````

## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 01.04.2020 Saat: 12:00**