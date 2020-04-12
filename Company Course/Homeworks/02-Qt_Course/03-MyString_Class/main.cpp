#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QtTest/QtTest>
#include "mystring.h"

int main(void)
    {
    QTextStream out(stdout);

    MyString str1("Mycarcarcar");
    MyString str2("car");
    MyString str3;
    str3 = str1 - str2;

    //str3 = "My"
    out << "str1 = \"" << str1 << "\"" << endl;
    out << "str2 = \"" << str2 << "\"" << endl;
    out << "str3 = \"" << str3 << "\"" << endl;

    QCOMPARE(QString("hello").toUpper(), QString("HELLO"));

    return 0;
}
