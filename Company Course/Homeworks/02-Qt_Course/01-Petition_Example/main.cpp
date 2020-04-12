#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QDate>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    QString placeholder=".........";
    QString deletesentence= "Universitemiz Egitim-Ogretim ve Sinav Yonetmeliginin  6. Maddesinin 4. fikrasi geregi, ";
    QString deletedersi= "dersi / ";
    QString deleteders5= "Ders 5:";
    QString arzederim="GEREGINI ARZ EDERIM.";

    petition.replace(petition.left(250),petition.left(250).toUpper()); //Dilekçe başlığı ve il bilgisinin tamamı büyük harfe çevrilmelidir.
    petition.replace(petition.indexOf(placeholder),placeholder.length(),"Elektronik ve Haberleşme Müh."); //Öğrencinin bölümü girilmelidir.
    petition.replace(petition.indexOf(placeholder),placeholder.length(),"95823"); //Öğrencinin numarası girilmelidir.
    petition.replace(petition.indexOf(placeholder),placeholder.length(),"4."); //Öğrencinin sınıfı girilmelidir.
    petition.replace(petition.indexOf(deletesentence),deletesentence.length()+1,"Ü"); //"Universitemiz Egitim-Ogretim ve Sinav Yonetmeliginin  6. Maddesinin 4. fikrasi geregi, " yazısının bulunduğu kısım silinmeli, virgülden sonraki kısım büyük harfle başlamalıdır.
    petition.replace(petition.indexOf(deletedersi),deletedersi.length(),""); //Eklenecek / çıkarılacak ders sayısı tek olmadığı için "dersi / " kısmı silinmelidir.
    petition.replace(petition.indexOf(deleteders5),deleteders5.length()+30,""); //Ders sayısına uygun olarak fazla olan "Ders 5:", ... silenmelidir.
    petition.insert(petition.indexOf("Ders 1: ")+8,"Analog Circuit"); //Ders bilgileri "Ders 1: Analog Circuit" gibi eklenmelidir.
    petition.insert(petition.indexOf("Ders 2: ")+8,"Digital Signal Processing");
    petition.insert(petition.indexOf("Ders 3: ")+8,"Information Theory");
    petition.insert(petition.indexOf("Ders 4: ")+8,"Mobile Communication");
    petition.replace(" / birakmak",""); //Ders ekleme yapılacaksa " / birakmak" kısmı silinmelidir.
    petition.replace(",              ",", "); //Boşluk düzeltme
    petition.insert(petition.indexOf(arzederim),"    ");//Fakulteniz, gereğini bilgilerinize arz ederim ve Ders X: kısmına 4 karakter "    " boşluk eklenerek eklenerek paragraf başı yapılmalıdır.
    petition.insert(petition.indexOf("Fakulteniz"),"    ");
    petition.replace(petition.indexOf(arzederim),arzederim.length(),arzederim.left(1).toUpper()+arzederim.toLower().mid(1)); //Arz kısmının ilk harfi büyük diğer harfleri küçük olmalıdır.

    petition=petition.arg("M.Serdar Karaman").arg(QDate::currentDate().toString("dd/MM/yyyy"));



    out << petition << endl;


    return a.exec();
}
