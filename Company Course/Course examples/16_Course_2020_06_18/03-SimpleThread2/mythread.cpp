#include "mythread.h"
#include <QDebug>

extern int g_var;

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    int i;//lokal
    for (i = 0; i < 1000000; i++)
        ;
    qDebug() << "Thread started";

    for (g_var = 0; g_var < 9999999; g_var++)
    {
        msleep(10);
        qDebug() << g_var;
    }

}
