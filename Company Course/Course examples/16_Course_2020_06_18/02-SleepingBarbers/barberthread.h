#ifndef BARBERTHREAD_H
#define BARBERTHREAD_H

#include <QThread>
#include <threadparam.h>

class BarberThread : public QThread
{
    Q_OBJECT
public:
    explicit BarberThread(ThreadParam param, QObject *parent = nullptr);
private:
    ThreadParam m_threadParam;
    void run() override;
signals:

public slots:
};

#endif // BARBERTHREAD_H
