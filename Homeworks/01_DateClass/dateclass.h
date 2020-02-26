#ifndef DATECLASS_H
#define DATECLASS_H

#include <iostream>
#include <string>

using namespace std;

class DateClass{
public:
    string m_date_sep = ".";
    DateClass(int y,int m,int d,string sep=".");
    int64_t DiffDate(DateClass Diff);
    bool SetDate(int y,int m,int d);
    void print();
    int64_t operator - (DateClass Diff){
        return DiffDate(Diff);
    }

private:
        int m_year;
        int m_month;
        int m_day;
};

#endif // DATECLASS_H
