#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

private:
    void run() override;

signals:
    void valueChanged(int i);
    void threadStarted();
    void threadFinished();
};

#endif // MYTHREAD_H
