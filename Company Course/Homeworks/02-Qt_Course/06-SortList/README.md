# Sorting of List Elements

Bir alışveriş sitesinden alışveriş yapacak kişilerin, seçtiği ürünlerin sepette istenilen bir özelliğine göre sıralanması için gerekli olan işlemleri ve özellikleri barındıran sınıfı yazın.  
Sınıfın ismi **Device** olsun ve alınacak ürünün aşağıdaki özelliklerini içerisinde barındırsın.  
* Ürün İsmi
* Ürün İsmi için get fonksiyonu
* Ürün Fiyatı
* Ürün Fiyatı için get fonksiyonu
* Ürün Ağırlığı (kg)
* Ürün Ağırlığı için get fonksiyonu
* Ürün Hacmi (m3)
* Ürün Hacmi için get fonksiyonu

* Sepette bulunması istenen ürünler ve bu ürünlere ait bilgiler aşağıdaki gibidir. Bunların aşağıdaki sıra gözetilerek bir container içerisinde tutulması istenmektedir.  

|   Device Name   |    Price (TL)    |   Weight (kg)   |   Volume (m3)   |
|----------------:|:----------------:|:---------------:|:---------------:|
|    HDSSD2561    |      180.000     |       2.220     |       0.020     |
|    HDSSD1281    |       90.000     |       1.350     |       0.050     |
|    HDSSD1282    |       90.000     |       3.400     |       0.013     |
|    HDSSD2562    |      180.000     |       6.652     |       0.052     |
|    MNXWG191     |       97.500     |       7.545     |       0.045     |
|    MNXWG192     |       97.500     |      10.380     |       1.080     |

* Varsayılan olarak, cihazlar sepete eklendiğinde fiyata göre sıralanması için Device sınıfının <code>operator<</code> fonskiyonunu overload etmesi ve bu fonksiyonun fiyata göre sıralamayı gerçekleştirmesi gerekmektedir.
* İstenildiği zaman ürün ismi, ağırlık ve hacime göre sıralama yapılabilmesi için device sınıfına ait gerekli karşılaştırma fonksiyonlarını yazınız.
* Fiyat, ağırlık ve hacme göre sıralama yaparken virgülden sonra 3 karakter olacak şekilde ekrana çıktı verilmelidir.
* Fiyat, ağırlık ve hacme göre sıralama yaparken sağa yaslanmış bir şekilde sıralama yapılmaldır.
* Device sınıfı türünden bir değişkenin barındırdığı değerleri (ürün ismi, ürün fiyatı, ürün ağırlığı ve ürün hacmi) ekrana yazdırabilecek, geri dönüş değeri qDebug olan bir operator<< fonksiyonu yazın.

## Qt Test Konsol Çıktısı

Ödevin tipik bir konsol çıktısı aşağıdaki gibi olmalıdır.

<pre>

16:18:43: Debugging starts

All devices in the shopping cart: 
 Device Name    Price        Weight    Volume  
  HDSSD2561   180.000 TL    2.220 kg  0.020 m3 
  HDSSD1281    90.000 TL    1.350 kg  0.050 m3 
  HDSSD1282    90.000 TL    3.400 kg  0.013 m3 
  HDSSD2562   180.000 TL    6.652 kg  0.052 m3 
  MNXWG191     97.500 TL    7.545 kg  0.045 m3 
  MNXWG192     97.500 TL   10.380 kg  1.080 m3 

********* Start testing of TestListSorting *********
Config: Using QtTest library 5.11.3, Qt 5.11.3 (i386-little_endian-ilp32 shared (dynamic) debug build; by GCC 5.3.0)
PASS   : TestListSorting::initTestCase()

QDEBUG : TestListSorting::test_case1_sortingByPrice() 
Sorting by price: 
 Device Name    Price        Weight    Volume  
  HDSSD1281    90.000 TL    1.350 kg  0.050 m3 
  HDSSD1282    90.000 TL    3.400 kg  0.013 m3 
  MNXWG191     97.500 TL    7.545 kg  0.045 m3 
  MNXWG192     97.500 TL   10.380 kg  1.080 m3 
  HDSSD2561   180.000 TL    2.220 kg  0.020 m3 
  HDSSD2562   180.000 TL    6.652 kg  0.052 m3 
PASS   : TestListSorting::test_case1_sortingByPrice()

QDEBUG : TestListSorting::test_case2_sortingByDeviceName() 
Sorting by device name: 
 Device Name    Price        Weight    Volume  
  HDSSD1281    90.000 TL    1.350 kg  0.050 m3 
  HDSSD1282    90.000 TL    3.400 kg  0.013 m3 
  HDSSD2561   180.000 TL    2.220 kg  0.020 m3 
  HDSSD2562   180.000 TL    6.652 kg  0.052 m3 
  MNXWG191     97.500 TL    7.545 kg  0.045 m3 
  MNXWG192     97.500 TL   10.380 kg  1.080 m3 
PASS   : TestListSorting::test_case2_sortingByDeviceName()

QDEBUG : TestListSorting::test_case3_sortingByWeight() 
Sorting by weight: 
 Device Name    Price        Weight    Volume  
  HDSSD1281    90.000 TL    1.350 kg  0.050 m3 
  HDSSD2561   180.000 TL    2.220 kg  0.020 m3 
  HDSSD1282    90.000 TL    3.400 kg  0.013 m3 
  HDSSD2562   180.000 TL    6.652 kg  0.052 m3 
  MNXWG191     97.500 TL    7.545 kg  0.045 m3 
  MNXWG192     97.500 TL   10.380 kg  1.080 m3 
PASS   : TestListSorting::test_case3_sortingByWeight()

QDEBUG : TestListSorting::test_case4_sortingByVolume() 
Sorting by volume: 
 Device Name    Price        Weight    Volume  
  HDSSD1282    90.000 TL    3.400 kg  0.013 m3 
  HDSSD2561   180.000 TL    2.220 kg  0.020 m3 
  MNXWG191     97.500 TL    7.545 kg  0.045 m3 
  HDSSD1281    90.000 TL    1.350 kg  0.050 m3 
  HDSSD2562   180.000 TL    6.652 kg  0.052 m3 
  MNXWG192     97.500 TL   10.380 kg  1.080 m3 
PASS   : TestListSorting::test_case4_sortingByVolume()

PASS   : TestListSorting::cleanupTestCase()

Totals: 6 passed, 0 failed, 0 skipped, 0 blacklisted, 7ms
********* Finished testing of TestListSorting *********
16:18:48: Debugging has finished

</pre>

## Ödev Teslimi

**Önemli Not:** Ödev teslim edilmeden önce repo içerisinde bulunan QtTest projesi ile test edilmeli ve hata alınan kısımlar düzeltilmelidir. Interface de sunulan fonksiyon isimlerinde ve parametre listesinde farklılıklar varsa, bu isimlerde QtTest projesinde bulunan isimlere uyacak şekilde düzenlenmelidir. **QtTest projesi birden fazla kişi tarafından kullanılacağı için bu proje içerisinde bulunan kodlarda ve .pro dosyasında herhangi bir değişiklik yapılmamalıdır.**  
Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 22.04.2020 Saat: 12:00**

