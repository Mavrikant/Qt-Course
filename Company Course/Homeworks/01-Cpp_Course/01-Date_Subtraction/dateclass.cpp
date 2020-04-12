#include "dateclass.h"
#include <iostream>
#include <string>

using namespace std;
/* NOTE: global olarak verilen metodlar, sinifin static private uye metodlari haline getirilebilir. */
/* Boylelikle Object Oriented Programming yaklasimiyla proje gerceklestirilmis olur.                */
int check_leap_year(int year);
int no_of_days_in_month(int month, int year);
long long int difference_of_days(int day1,int month1, int year1, int day2, int month2, int year2);

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

/* NOTE: Sadece metod cagrisi yapiliyorsa, "difference_of_days" metodunun icerigi */
/* "DiffDate" metoduna alinarak daha sade bir yaklasim gerceklestirilebilir.      */
int64_t DateClass::DiffDate(DateClass Diff){
    return difference_of_days(m_day,m_month,m_year,Diff.m_day,Diff.m_month,Diff.m_year);
}

// Source: https://www.codespeedy.com/find-difference-between-two-dates-in-cpp/
int check_leap_year(int year){
    if( year%4==0 && year%100!=0 || year%400==0 )   //if year is a leap year
        return 1;
    else
        return 0;
}

int no_of_days_in_month(int month, int year){
    // jan, march, may, july, aug, oct, dec contains 31 days
    if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 )
        return 31;

    // april, jun, sept, nov contains 30 days
    if( month==4 || month==6 || month==9 || month==11 )
        return 30;

    if( month==2 )
    {
        int n=check_leap_year(year);
        if(n==1)    // if year is a leap year then Feb will contain 29 days, otherwise it contains 28 days
        return 29;

        else
        return 28;
    }
}

long long int difference_of_days(int day1,int month1, int year1, int day2, int month2, int year2){
    if(year1==year2)
    {
        if(month1==month2)
        {
            if(day1==day2)      //for same dates
                return 0;
            else
                return abs(day1-day2);  //for same year, same month but diff days
        }
        else if(month1<month2)
        {
            int result=0;
            for(int i=month1; i<month2; i++)
            result=result+no_of_days_in_month(i,year1);

            if(day1==day2)      //for same year, same day but diff month
                return result;
            else if(day1<day2)
            {
                result=result+(day2-day1);
                return result;
            }
            else
            {
                result=result-(day1-day2);
                return result;
            }
        }
        else
        {
            int result=0;
            for(int i=month2; i<month1; i++)
            result=result+no_of_days_in_month(i,year1);

            if(day1==day2)
                return result;
            else if(day2<day1)
            {
                result=result+(day1-day2);
                return result;
            }
            else
            {
                result=result-(day2-day1);
                return result;
            }
        }
    }
    else if(year1<year2)
    {
        int temp=0;
        for(int i=year1; i<year2; i++)
        {
            if(check_leap_year(i))
                temp=temp+366;
            else
                temp=temp+365;
        }

        if(month1==month2)
        {
            if(day1==day2)      //for same month, same day but diff year
                return temp;
            else if(day1<day2)
                return temp+(day2-day1);
            else
                return temp-(day1-day2);
        }
        else if(month1<month2)
        {
            int result=0;
            for(int i=month1; i<month2; i++)
            result=result+no_of_days_in_month(i,year2);

            if(day1==day2)      // for same day, diff year and diff month
                return temp+result;
            else if(day1<day2)
            {
                result=result+(day2-day1);
                return temp+result;
            }
            else
            {
                result=result-(day1-day2);
                return temp+result;
            }
        }
        else
        {
            int result=0;
            for(int i=month2; i<month1; i++)
            result=result+no_of_days_in_month(i,year2);

            if(day1==day2)
                return temp-result;
            else if(day2<day1)
            {
                result=result+(day1-day2);
                return temp-result;
            }
            else
            {
                result=result-(day2-day1);
                return temp-result;
            }
        }
    }
    else
    {
        int temp=0;
        for(int i=year2; i<year1; i++)
        {
            if(check_leap_year(i))
                temp=temp+366;
            else
                temp=temp+365;
        }

        if(month1==month2)
        {
            if(day1==day2)      // for same day, same month but diff year
                return temp;
            else if(day2<day1)
                return temp+(day1-day2);
            else
                return temp-(day2-day1);
        }
        else if(month2<month1)
        {
            int result=0;
            for(int i=month2; i<month1; i++)
            result=result+no_of_days_in_month(i,year1);

            if(day1==day2)
                return temp+result;
            else if(day2<day1)
            {
                result=result+(day1-day2);
                return temp+result;
            }
            else
            {
                result=result-(day2-day1);
                return temp+result;
            }
        }
        else
        {
            int result=0;
            for(int i=month1; i<month2; i++)
            result=result+no_of_days_in_month(i,year1);

            if(day1==day2)      // for same day, diff year and diff month
                return temp-result;
            else if(day1<day2)
            {
                result=result+(day2-day1);
                return temp-result;
            }
            else
            {
                result=result-(day1-day2);
                return temp-result;
            }
        }
    }
}
