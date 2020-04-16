#include <QCoreApplication>
#include <QList>
#include <QMap>
#include <QString>
#include <QVector>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out (stdout);

    QVector<int> b_dates = {1993,1987,1992,1992,1979,1987,1989,1990,1984};
    QList<QString> names = {"Onder","Muhammet","Metin","Toygan","Abdullah","Onur Can","Emre", "Hasan Salih", "Murat"};
    QList<QString> last_names ={"Gormez", "Karaman", "Duzenli", "Subasi", "Karadag", "Kurban", "Ergun", "Postalli", "Zengin"};

    QMap<QString,int> map;

    for(auto name: names){
        map.insert(name+" "+last_names.takeFirst(), b_dates.takeFirst());
    }

    qDebug()<<map;


    return a.exec();
}
