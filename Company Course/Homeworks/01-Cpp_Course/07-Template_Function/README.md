# Template Function

Şablonlar (templates) birden çok data türüne uygulanacak eş işlemlerin ayrı ayrı kod parçacıkları ile yazılması yerine türden bağımsız bir şekilde tek bir prototip kod yazılarak bu koddan her istenilen data türüne göre otomatik olarak yazılmasını sağlar. Böylelikle yazılan prototip kodun bakımı ve okunabilirliği kolaylaşır.

Test kodu aşağıdaki gibi olan, parametre listesinde verilen aynı türden 2 değişkenin değerlerini takas eden şablon fonksiyonu (template function) yazınız.

## Test Kodu

<pre>

int main(void)
{
    int i1 = 20, i2 = -10;
    double d1 = 13.5, d2 = -9.3;
    char ch1 = 'A', ch2 = 'C';

    cout << "i1: " << i1 << " i2: " << i2 << endl;
    cout << "d1: " << d1 << " d2: " << d2 << endl;
    cout << "ch1: " << ch1 << " ch2: " << ch2 << endl;

	/* TODO: Write swap operations. */

    cout << "i1: " << i1 << " i2: " << i2 << endl;
    cout << "d1: " << d1 << " d2: " << d2 << endl;
    cout << "ch1: " << ch1 << " ch2: " << ch2 << endl;
}

</pre>

## Ödev Teslimi

Ödevi derse katılan herkes kendisi için açılmış olan klasörlere yüklemelidir. **Ödev Teslim Tarihi: 18.03.2020 Saat: 08:00**