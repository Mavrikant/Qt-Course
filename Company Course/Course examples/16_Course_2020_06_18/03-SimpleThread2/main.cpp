#include <QCoreApplication>
#include <mythread.h>

int g_var;

int main()
{
    MyThread t1, t2;

    t1.start();
    t2.start();

    t1.wait();
    t2.wait();

    return 0;
}
