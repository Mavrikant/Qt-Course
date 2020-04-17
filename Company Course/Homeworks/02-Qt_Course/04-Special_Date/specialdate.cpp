#include "specialdate.h"
#include <QDebug>
#include <iostream>

bool SpecialDate::isSpecialDate()
{
    return ( (day()==month()) & (year()%100==day()) );
}

unsigned int SpecialDate::getSpecialDateCount(const SpecialDate &target_date)
{
    unsigned int count=0;

    SpecialDate nextdate(this->year(),this->month(),this->day());
    SpecialDate enddate(target_date.year(),target_date.month(),target_date.day());

    if( static_cast<QDate>(target_date) < static_cast<QDate>(*this) ){
        SpecialDate *temp= new SpecialDate(1,1,1);
        *temp= enddate;
        enddate=nextdate;
        nextdate=*temp;
    }

    while ( static_cast<QDate>(enddate) > static_cast<QDate>(nextdate.nextSpecialDate()) )
    {
        nextdate=nextdate.nextSpecialDate();
        count++;
    }

    return count;
}

SpecialDate SpecialDate::nextSpecialDate() const
{
    if( (year()%100) > 12)
    {
        return SpecialDate(year()-(year()%100)+100+1, 1, 1);
    }
    else
    {
        SpecialDate nextdate(year(),year()%100,year()%100);
        if( static_cast<QDate>(nextdate) > static_cast<QDate>(*this) )
        {
            return nextdate;
        }
        else if( (year()%100) == 12 )
        {
            return SpecialDate(year()-(year()%100)+100+1, 1, 1);
        }
        else{
            return SpecialDate(year()+1,(year()+1)%100,(year()+1)%100);
        }
    }
}


QDebug operator<<(QDebug qdebug, const SpecialDate &specialDate)
{
    QDebugStateSaver saver(qdebug);
    qdebug <<specialDate.toString("dd/MM/yyyy");
    return qdebug;
}
