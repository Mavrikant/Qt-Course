#include "gprmcdatetime.h"
#include <QDebug>
#include <iostream>

GPRMCDateTime::GPRMCDateTime(const char *gprmcMessage)
{
    m_container = (QString(gprmcMessage)).split(",");
    qDebug()<<m_container;

    //| 9  | 130694   |  Date Stamp(ddMMyy)          |
    int day = m_container.at(9).mid(0,2).toInt();
    int month = m_container.at(9).mid(2,2).toInt();
    int year = m_container.at(9).mid(4,2).toInt();
    if (year<30){
        year+=2000;
    }
    else{
        year+=1900;
    }

    //| 1  | 220516   |  Time Stamp (hhmmss UTC)     |
    int hour = m_container.at(1).mid(0,2).toInt();
    int minute = m_container.at(1).mid(2,2).toInt();
    int second = m_container.at(1).mid(4,2).toInt();

    m_datetime = QDateTime(QDate(year,month,day),QTime(hour,minute,second));

    if(m_datetime.isValid()){
        qDebug()<<"GPRMCDateTime is valid";
    }
    else{
        qDebug()<<"GPRMCDateTime is NOT valid";
    }
}

QString GPRMCDateTime::toString(int frmt)
{
    if(0==frmt){ //ISO time format

        //QCOMPARE(str, QString("1994-06-13T22:05:16"));
        return m_datetime.toString(Qt::ISODate);
    }
    else if (1==frmt){ //Local time format
        return m_datetime.toString(Qt::SystemLocaleLongDate);
    }
    else{
        std::cerr<<"GPRMCDateTime::toString(int frmt) ->"<<"frmt is out of range (frmt="<<frmt<<")";
        return QString();
    }
}

long long GPRMCDateTime::operator-(GPRMCDateTime gprmc2)
{
    return gprmc2.m_datetime.toSecsSinceEpoch()-m_datetime.toSecsSinceEpoch();
}
