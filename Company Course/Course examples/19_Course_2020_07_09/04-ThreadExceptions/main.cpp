#include <QCoreApplication>
#include <mythread.h>
int main(int argc, char *argv[])
{
  MyThread t(1,nullptr);
  MyThread t2(2,nullptr);
  t.start();
  t.wait();
  t2.start();
  t2.wait();
}
