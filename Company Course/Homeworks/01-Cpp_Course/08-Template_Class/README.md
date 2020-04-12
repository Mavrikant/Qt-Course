# Template Class

Şablonlar (templates) birden çok data türüne uygulanacak eş işlemlerin ayrı ayrı kod parçacıkları ile yazılması yerine türden bağımsız bir şekilde tek bir prototip kod yazılarak bu koddan her istenilen data türüne göre otomatik olarak yazılmasını sağlar. Böylelikle yazılan prototip kodun bakımı ve okunabilirliği kolaylaşır.

Test kodu aşağıdaki gibi olan toplama, çıkarma, çarpma ve bölme işlemlerini türden bağımsız olarak yapabilen **fonksiyonları statik** olan hesap makinesi sınıfını yazınız.

Şablon fonksiyonların (template functions) içerisine hangi data türü için şablonun açıldığını belirten kodları ekleyiniz. 

## Test Kodu

<pre>

int main(void)
{
    int i1 = 20, i2 = -10;
    double d1 = 13.5, d2 = -9.3;
    float f1 = 12.8f, f2 = 13.8f;

    cout << "i1 + i2 = " << ??? << endl;
    cout << "i1 - i2 = " << ??? << endl;
    cout << "i1 * i2 = " << ??? << endl;
    cout << "i1 / i2 = " << ??? << endl;

    cout << "d1 + d2 = " << ??? << endl;
    cout << "d1 - d2 = " << ??? << endl;
    cout << "d1 * d2 = " << ??? << endl;
    cout << "d1 / d2 = " << ??? << endl;

    cout << "f1 + f2 = " << ??? << endl;
    cout << "f1 - f2 = " << ??? << endl;
    cout << "f1 * f2 = " << ??? << endl;
    cout << "f1 / f2 = " << ??? << endl;
}

</pre>

## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasörlere yüklemelidir. **Ödev Teslim Tarihi: 18.03.2020 Saat: 08:00**