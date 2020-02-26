#include "dateclass.h"
#include <iostream>
#include <string>

using namespace std;

DateClass::DateClass(int y,int m,int d,string sep){
    m_year=y;
    m_month=m;
    m_day=d;
    m_date_sep=sep;
}



bool DateClass::SetDate(int y,int m,int d){
    if (m < 1 || m > 12 || d < 1 || d > 31 || y < 1970){
        return false;
    }
    m_year = y;
    m_month = m;
    m_day = d;

    return true;
}

void DateClass::print(){
    cout << m_day << m_date_sep << m_month << m_date_sep << m_year << endl;
}
