#include <QCoreApplication>
#include "specialdate.h"
#include <QtDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SpecialDate start_date(1,1,1);
    SpecialDate end_date(3000,1,1);

    qDebug()<<"Number of special dates between 0AD and 3000 years: "<<start_date.getSpecialDateCount(end_date);


    SpecialDate nextdate(start_date.year(),start_date.month(),start_date.day());
    unsigned int count=0;
    while ( static_cast<QDate>(end_date) > static_cast<QDate>(nextdate.nextSpecialDate()) )
    {
        nextdate=nextdate.nextSpecialDate();
        count++;
        qDebug()<<"#"<<count<<nextdate;

    }

    return a.exec();
}
