#ifndef MYSTRING_H
#define MYSTRING_H
#include <QString>
#include <QTextStream>
#include <QtTest/QtTest>

class MyString:QString
{
public:
    MyString(QString str="")
    {
        m_str=str;
    }
    MyString operator- (MyString const difStr)
    {
        auto qstr=this->m_str;
        return qstr.replace(difStr.m_str,"");
        QCOMPARE(MyString("mycarcar") - MyString("car") , MyString("my"));

    }
    bool operator== (MyString const str2)
    {
        if (this->m_str==str2.m_str){
            return true;
        }
        else{
            return false;
        }
    }
    friend QTextStream & operator<<(QTextStream & out, MyString const & str){
        out<<str.m_str;
        return out;
    }

private:
    QString m_str;
};



#endif // MYSTRING_H
