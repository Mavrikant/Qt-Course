#include "mythread.h"
#include <myclass.h>
#include <QtDebug>
#include <iostream>
#define USE_TRY

MyThread::MyThread(int id, QObject *parent) : QThread(parent), m_id(id)
{

}

void MyThread::run()
{
    MyClass c(0);
#ifdef USE_TRY
    try
    {
#endif
        MyClass c1(1);
        MyClass *p = new MyClass(2);
        std::vector<int> v(10);
        int var;

        qDebug() << QString("Thread #%1 Lets access impossible").arg(m_id);
        var = v.at(10);
        qDebug() << QString("Thread #%1 Could we access impossible?").arg(m_id);
        delete p;
#ifdef USE_TRY
    }
    catch (const std::out_of_range &e)
    {
        qDebug() << QString("Thread #%1 Something went wrong!").arg(m_id);
    }
#endif
    qDebug() << QString("Thread #%1 Lets do some harmless things!").arg(m_id);
}
