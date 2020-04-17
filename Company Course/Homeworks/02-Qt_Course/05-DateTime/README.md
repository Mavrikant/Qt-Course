# QDebug & Date Time Functions

Aşağıda bir GPS aygıtından gelen örnek bir mesaj gösterilmektedir. Bir gömülü sistemde daha önce yazılmış yüksek performanslı bir c kütüphanesinin arayüzü QT/C++ programcısına bu dizgeyi sunmaktadır. Programcıdan aşağıdaki şıklardaki isterleri yerine getirmesi istenmektedir.

**a.** Programcı $GPRMC mesajıyla ilklenen bir GPRMCDateTime sınıfını yazacaktır. Sınıfın  prototipi <code>GPRMCDateTime (const char *gprmcMessage)</code> olan bir kurucu fonksiyonu olacaktır.  

**b.** Programcı fonksiyondan gelen tarih saatin geçerli olup olmadığına dair bir debug mesajı fırlatacaktır.  

**c.**  Programcı bu mesaja dair iki farklı isteği karşılayacak şekilde uygun bir arayüz sağlayacaktır. Aşağıda toString üye fonksiyonunun prototipi verilmiştir.  
<code>QString toString(int frmt=0)</code>  
**frmt** tam sayısı 0 ise ISO tarih formatında bir dizge döndürülecektir.  
**frmt** tam sayısı 1 ise istek yapılan sunucudaki sistem lokali (uzun) formatında bir tarih saat dizgesi döndürülecektir.  

**d.**  Programcı GPRMCDateTime sınıfı için iki mesaj arasındaki zaman farkını saniye cinsinden (long long) veren çıkarma operatörünü sağlamalıdır.  
Örnek GPS Verisi:

<pre>
    eg3. $GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70
                  1    2    3    4    5     6   7     8      9    10   11 12
</pre>

| No |  Value   |        Explanation           |
|:--:|---------:|:-----------------------------|
| 1  | 220516   |  Time Stamp (hhmmss UTC)     |
| 2  | A        |  validity - A-ok, V-invalid  |
| 3  | 5133.82  |  current Latitude            |
| 4  | N        |  North/South                 |
| 5  | 00042.24 |  current Longitude           |
| 6  | W        |  East/West                   |
| 7  | 173.8    |  Speed in knots              |
| 8  | 231.8    |  True course                 |
| 9  | 130694   |  Date Stamp(ddMMyy)          |
| 10 | 004.2    |  Variation                   |
| 11 | W        |  East/West                   |
| 12 | *70      |  checksum                    |
  

## Ödev Teslimi

**Önemli Not:** Ödev teslim edilmeden önce repo içerisinde bulunan QtTest projesi ile test edilmeli ve hata alınan kısımlar düzeltilmelidir. Interface de sunulan fonksiyon isimlerinde ve parametre listesinde farklılıklar varsa, bu isimlerde QtTest projesinde bulunan isimlere uyacak şekilde düzenlenmelidir. **QtTest projesi birden fazla kişi tarafından kullanılacağı için bu proje içerisinde bulunan kodlarda ve .pro dosyasında herhangi bir değişiklik yapılmamalıdır.**  
Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 15.04.2020 Saat: 12:00**

