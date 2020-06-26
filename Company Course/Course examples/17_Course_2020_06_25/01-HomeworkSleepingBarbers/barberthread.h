#ifndef BARBERTHREAD_H
#define BARBERTHREAD_H
#include <QThread>
#define INVALID_CLIENT_ID -1
class BarberThread : public QThread
{
  Q_OBJECT
public:
  explicit BarberThread(QObject *parent = nullptr,int id = 0,unsigned long hcProcessTime=100000);
signals:

public slots:
private:
  int m_id;
  int m_clientId;//[0-forever] -1 for no client
  unsigned long m_hcProcessTime;//hair-cut processing time in micro seconds
  void run() override;
};

#endif // BARBERTHREAD_H
