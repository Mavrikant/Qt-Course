#include <QCoreApplication>
#include "gprmcdatetime.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char gprmc[] = "$GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70";
    GPRMCDateTime gprmc_data(gprmc);


    qDebug() <<"**************************";
    QString str1;
    str1 = gprmc_data.toString(0);
    qDebug() <<"ISO DateTime:" << str1;

    QString str2;
    str2 = gprmc_data.toString(1);
    qDebug() <<"Local DateTime:" << str2;


    qDebug() <<"**************************";
    char gprmc3[] = ("eg3. $GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70");
    char gprmc4[] = ("eg3. $GPRMC,230414,A,5133.82,N,00042.24,W,173.8,231.8,120899,004.2,W*70");
    GPRMCDateTime gprmc_data3(gprmc3);
    GPRMCDateTime gprmc_data4(gprmc4);


    qDebug() <<"**************************";
    qDebug()<<gprmc_data3-gprmc_data4;

    return a.exec();
}
