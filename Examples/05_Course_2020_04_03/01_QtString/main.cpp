#include <QCoreApplication>
#include <QTextStream>

#define STR_EQUAL 0

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);
    QString a="Sönmez bu";
    a.append(" şafaklarda yüzen ");
    a.append("al sancak");
    a.append(".");
    out<<a.toUpper()<<endl;
    out<<a.count()<<endl;

out<<"#########################################"<<endl;


       QString aa = "Rain";
       QString b = "rain";
       QString c = "rain\n";

       if (QString::compare(aa, b) == STR_EQUAL) {
         out << "a, b are equal" << endl;
       } else {
         out << "a, b are not equal" << endl;
       }

out << "In case insensitive comparison:" << endl;

       if (QString::compare(aa, b, Qt::CaseInsensitive) == STR_EQUAL) {
         out << "a, b are equal" << endl;
       } else {
         out << "a, b are not equal" << endl;
       }

       if (QString::compare(b, c) == STR_EQUAL) {
         out << "b, c are equal" << endl;
       } else {
         out << "b, c are not equal" << endl;
       }

       c.chop(1);

       out << "After removing the new line character" << endl;

       if (QString::compare(b, c) == STR_EQUAL) {
         out << "b, c are equal" << endl;
       } else {
         out << "b, c are not equal" << endl;
       }


out<<"#########################################"<<endl;


          QString s11 = "There are %1 white roses";
          int n = 12;

          out << s11.arg(n) << endl;

          QString s22 = "The tree is %1 m high";
          double h = 5.65;

          out << s22.arg(h) << endl;

          QString s33 = "We have %1 lemons and %2 oranges";
          int ln = 12;
          int on = 4;

          out << s33.arg(ln).arg(on) << endl;



out<<"#########################################"<<endl;

    QString s1 = "12";
    QString s2 = "15";
    QString s3, s4;


    out << s1.toInt() + s2.toInt() << endl;

    int n1 = 30;
    int n2 = 40;

    out << s3.setNum(n1) + s4.number(n2) << endl;

out<<"#########################################"<<endl;

/*
Aşağıdaki metinde . ile doldurulmuş alanları değişkenlerden gelen değerlerle değiştirin.
Kırmızı ile boyanmış kısmı silin.
dersi/ kısmını silip dersleri kısmından sonra rastgele bir kaç ders ekleyin.
İlk iki satırın tamamını küçük harf olarak değiştirin. Türkçe karkterlerlere takılmayın
*/

    QString qs1 = "S. Ü. EDEBİYAT FAKÜLTESİ DEKANLIĞINA";
    QString qs2 ="KONYA";
    QString qs3 ="Fakülteniz %1 Bölümü, %2 numaralı %3 sınıf öğrencisiyim. Üniversitemiz Eğitim-Öğretim ve Sınav Yönetmeliğinin 6. Maddesinin 4. fıkrası gereği, üniversitemiz senatosunca her Eğitim-Öğretim yılında akademik takvimde belirtilen ders ekleme-bırakma süresi içerisinde aşağıda belirtilen dersleri, eklemek istiyorum.";
    QString qs4 = "Gereğini arz ederim.";

    QString bolumAdi="Türkçe Öğretmenliği";
    QString numara="3423";
    QString sinif="son";

    out<<qs1.toLower()<<endl<<qs2.toCaseFolded()<<endl<<qs3.arg(bolumAdi).arg(numara).arg(sinif)<<endl<<qs4<<endl;


out<<"#########################################"<<endl;

    QString qs5="Fakülteniz ……………………… Bölümü, ……………… numaralı …… sınıf öğrencisiyim. ";
    out << qs5.replace("………………………",bolumAdi).replace("………………",numara).replace("……",sinif)<<endl;


out<<"#########################################"<<endl;


    return app.exec();
}
