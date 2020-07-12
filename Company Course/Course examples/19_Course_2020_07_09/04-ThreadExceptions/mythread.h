#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
  Q_OBJECT
public:
  explicit MyThread(int id,QObject *parent = nullptr);

signals:

public slots:
private:
  int m_id;
  void run() override;
};

#endif // MYTHREAD_H
