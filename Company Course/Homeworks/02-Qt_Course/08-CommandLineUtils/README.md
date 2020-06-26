# Command Line Utils

Windows'ta ve Linux'ta komut satırından çalışan aşağıda listesi verilen uygulamaları implemente eden programı yazınız.

* Program çalıştırıldığı zaman ekrana  
  <code>WorkingDirectoryPath> </code>  
şeklinde bir prompt basacaktır.
* Kullanıcı aşağıda belirtilen Linux veya Windows komutlarından birini konsola girerek enter tuşuna bastığı zaman, komutun yapması gereken işlem yapılacaktır.  
Örneğin **dir** komutu girildiyse WorkingDirectoryPath dizini içerisinde bulunan klasörler ve dosyalar listelenecektir.
* Komutun icrası bittikten sonra yine  
<code>WorkingDirectoryPath> </code>  
prompt una geri dönülecektir.
* **"CTRL + C"** tuş kombinasyonuna basılıp program sonlandırılana kadar kullanıcıdan gelen komutlara göre program işlemeye devam edecektir.


| Fonksiyon                  | Windows Komutu | Linux Komutu |
|:--------------------------:|:--------------:|:------------:|
| Dizin İçeriğini Listeleme  |  dir           |    ls        |
| Çalışma Dizini Değiştirme  |   cd           |    cd        |
| Dosya Kopyalama            |  copy          |    cp        |
| Dosya Taşıma               |  move          |    mv        |
| Dosya Silme                |  del           |    rm        |

* Yukarıdaki komutlar dışında işlevi olmayan bir komut girildiğinde aşağıdaki konsol çıktısı oluşturulmalıdır.  
<pre>
C:/01-AR-GE/02-Software/02-Desktop/QtCourse/02-Homeworks/build-CommandLineUtils-Desktop_Qt_5_14_1_MinGW_32_bit-Debug> deneme
'deneme' is not recognized as an internal or external command,
operable program or batch file.

C:/01-AR-GE/02-Software/02-Desktop/QtCourse/02-Homeworks/build-CommandLineUtils-Desktop_Qt_5_14_1_MinGW_32_bit-Debug>
</pre>


## Ödev Teslimi
 
Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 13.05.2020 Saat: 12:00**

