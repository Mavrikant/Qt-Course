#include "clientthread.h"
#include <QDebug>
#include <QSemaphore>
#include <QMutex>
#include <QWaitCondition>

extern QSemaphore semBarbers;
extern QSemaphore semSeats;
extern QMutex mutex1;
extern QWaitCondition clientAvailable;

#define INVALID_ID -1

void addClientToWaitingQue(int clientId);
void byeBarberShop(int clientId);


ClientThread::ClientThread(QObject *parent, int id) :
  QThread(parent),m_id(id)
{

}

void ClientThread::run()
{
  //here we need a semaphore for seat
  //if we could acquire a seat then we wait a barber to be available, another semaphore
  if(semSeats.tryAcquire()){
    addClientToWaitingQue(m_id);
    clientAvailable.wakeOne();
    semBarbers.acquire();
    //qDebug() << QString("Client #%1 I am happy with my barber :)").arg(m_id);
    semSeats.release();

  }
  else
  {
    byeBarberShop(m_id);

    return;
  }

}

int ClientThread::id() const
{
  return m_id;
}
