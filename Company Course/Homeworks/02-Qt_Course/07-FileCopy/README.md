# File Copy Program

İşletim sisteminin sağladığı kopyalama işlemi gerçekleştiren programlara benzer şekilde, kaynak olarak olarak verilen bir dosyayı hedef olarak gösterilen bir konuma kopyalayan programı yazınız.  
Bu program yaptığı kopyalama işlemi sonunda hedef dizine kopyaladığı dosyanın içerisinde bulunan ilk satırı okuyarak konsola bu satırda yazan bilgileri yazdıracaktır.

Program Kullanımı: filecopy.exe SourcePath DestinationPath

Program geri dönüş değerleri aşağıdaki gibi olacaktır.  
0 : Success  
1 : Invalid argument count!  
2 : Source file does not exist!  
3 : Destination file already exist!  
4 : Copy operation failed!  

## Qt Test Konsol Çıktısı

Ödevin tipik bir konsol çıktısı aşağıdaki gibi olmalıdır.

<pre>
14:14:40: Debugging starts
********* Start testing of TestFileCopy *********
Config: Using QtTest library 5.11.3, Qt 5.11.3 (i386-little_endian-ilp32 shared (dynamic) debug build; by GCC 5.3.0)

PASS   : TestFileCopy::initTestCase()

Invalid argument count!
Usage: filecopy.exe SourcePath DestinationPath
PASS   : TestFileCopy::test_case1_missingArgument()

Invalid argument count!
Usage: filecopy.exe SourcePath DestinationPath
PASS   : TestFileCopy::test_case2_moreArgument()

PASS   : TestFileCopy::test_case3_invalidSource()
Source file "Makefilex" does not exist!

Destination file "Makefile" already exist!
PASS   : TestFileCopy::test_case4_destinationFileExist()

Copy operation failed!
PASS   : TestFileCopy::test_case5_copyOperationFail()

First Line of Makefile2 is:
#############################################################################
PASS   : TestFileCopy::test_case6_copyOperationSuccess()

PASS   : TestFileCopy::cleanupTestCase()
Totals: 8 passed, 0 failed, 0 skipped, 0 blacklisted, 88ms
********* Finished testing of TestFileCopy *********
14:14:44: Debugging has finished
</pre>

## Ödev Teslimi

**Önemli Not:** Ödev teslim edilmeden önce repo içerisinde bulunan QtTest projesi ile test edilmeli ve hata alınan kısımlar düzeltilmelidir. Interface de sunulan fonksiyon isimlerinde ve parametre listesinde farklılıklar varsa, bu isimlerde QtTest projesinde bulunan isimlere uyacak şekilde düzenlenmelidir. **QtTest projesi birden fazla kişi tarafından kullanılacağı için bu proje içerisinde bulunan kodlarda ve .pro dosyasında herhangi bir değişiklik yapılmamalıdır.**  
Ödevi derse katılan herkes kendisi için açılmış olan klasöre yüklemelidir. **Ödev Teslim Tarihi: 29.04.2020 Saat: 12:00**

