#include <QDebug>
#include <QTextStream>
#include <QPoint>
#include "complex.h"

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QPoint p1(1,2);
    Complex complex1(3,4);

    out <<"Merhaba"<<endl;
    //out<<p1<<endl;
    qDebug()<<"p1: "<<p1;
    qDebug()<<"complex1: "<<complex1;


}
