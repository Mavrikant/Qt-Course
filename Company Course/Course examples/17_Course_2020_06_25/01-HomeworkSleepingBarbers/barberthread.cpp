#include "barberthread.h"
#include <QDebug>
#include <QSemaphore>
#include <QMutex>
#include <QWaitCondition>

extern QSemaphore semBarbers;
extern QSemaphore semSeats;
extern QMutex mutex1;
extern QWaitCondition clientAvailable;
static QMutex mutexCA;

int popReadyClient();//define this function in barbershop class
BarberThread::BarberThread(QObject *parent, int id, unsigned long hcProcessTime) :
  QThread(parent),m_id(id),m_hcProcessTime(hcProcessTime)
{
  m_clientId = INVALID_CLIENT_ID;
}

void BarberThread::run()
{
  forever{
    int id = INVALID_CLIENT_ID;
    //a wait condition should come here
    mutexCA.lock();
    clientAvailable.wait(&mutexCA);
    id = popReadyClient();

    mutexCA.unlock();
    if(INVALID_CLIENT_ID != id){
      qDebug() << QString("Barber #%1 started an hair-cut for client #%2 ").arg(m_id).arg(id);
      usleep(m_hcProcessTime);
      qDebug() << QString("Barber #%1 has done an hair-cut for client #%2 ").arg(m_id).arg(id);
      semBarbers.release();
    }
  }

}
