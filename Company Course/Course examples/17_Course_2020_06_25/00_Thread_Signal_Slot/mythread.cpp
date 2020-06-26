#include "mythread.h"
#include <QDebug>


MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    emit threadStarted();
    for (int i = 0; i <= 100; ++i)
    {
        emit valueChanged(i);
        qDebug() << i;
        msleep(50);
    }
    emit threadFinished();
}
