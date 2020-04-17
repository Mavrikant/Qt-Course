#ifndef SPECIALDATE_H
#define SPECIALDATE_H

#include <QDate>
#include <QDebug>

class SpecialDate : public QDate
{
public:
    SpecialDate(int y, int m, int d):QDate(y, m, d){;}
    SpecialDate(QDate qdate):QDate(qdate.year(), qdate.month(), qdate.day()){;}
    bool isSpecialDate();
    unsigned int getSpecialDateCount(const SpecialDate &target_date);
    Q_REQUIRED_RESULT SpecialDate nextSpecialDate() const;
    friend QDebug operator<<( QDebug qdebug, const SpecialDate & specialDate);

};


#endif // SPECIALDATE_H
