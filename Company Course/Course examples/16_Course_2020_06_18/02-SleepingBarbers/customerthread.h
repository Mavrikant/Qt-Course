#ifndef CUSTOMERTHREAD_H
#define CUSTOMERTHREAD_H

#include <QThread>
#include <threadparam.h>

class CustomerThread : public QThread
{
    Q_OBJECT
public:
    explicit CustomerThread(ThreadParam param, QObject *parent = nullptr);

signals:

public slots:
private:
    ThreadParam m_threadParam;
    void run() override;
};

#endif // CUSTOMERTHREAD_H
