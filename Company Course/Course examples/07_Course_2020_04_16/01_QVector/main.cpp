#include <QCoreApplication>
#include <QTextStream>
#include <QVector>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out (stdout);

    QVector<int> b_dates = {1993,1987,1992,1992,1979,1987,1989,1990,1984};

    b_dates.prepend(1996);
    b_dates.append(1993);


    for (auto date:b_dates){
        out << date << endl;
    }

    return a.exec();
}
