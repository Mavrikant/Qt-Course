#include "barbershop.h"
#include <QDebug>

#include <QSemaphore>
#include <QMutex>
#include <QWaitCondition>
#include <QRandomGenerator>
QSemaphore semBarbers;
QSemaphore semSeats;
QMutex mutex1;
QWaitCondition clientAvailable;
BarberShop* BarberShop::instance = nullptr;
BarberShop *BarberShop::getInstance()
{
  if(nullptr == instance)
    instance = new BarberShop();
  return instance;
}

void BarberShop::setProperties(QObject *parent, unsigned int barberCapacity, unsigned int seatCapacity, unsigned long haircutServiceTime)
{
  setParent(parent);
  setBarberCapacity(barberCapacity);
  setSeatCapacity(seatCapacity);
  setHaircutServiceTime(haircutServiceTime);
}

void addClientToWaitingQue(int clientId)
{
  BarberShop::getInstance()->addClientToWaitingQue(clientId);
}
int popReadyClient()
{//define this function in barbershop class
  BarberShop::getInstance()->popReadyClient();
}
void BarberShop::startClients()
{
  semSeats.release(m_seatCapacity);
  semBarbers.release(m_barberCapacity);
  foreach(auto value ,m_barberThreads.values()){
    value->start();
  }
  for(unsigned int i=0; i<MaxNumberOfClients;i++){
    if(m_clientThreads.contains(i)){
      unsigned int ms = QRandomGenerator::global()->bounded(10);
      //qDebug() << "Lets wait : " << ms;
      m_clientThreads[i]->start();
      QThread::msleep(ms);
      m_clientThreads[i]->wait(1);
    }
  }

}
void byeBarberShop(int clientId)
{
  qDebug() << QString("%1 clients waiting already").arg(BarberShop::getInstance()->getClientQueue().count());
  qDebug() << QString("Client #%1 I am unlocky today :(").arg(clientId);
}
void BarberShop::addClientToWaitingQue(int clientId)
{
  int id = -1;
  mutex1.lock();
  if(m_clientThreads.contains(clientId))
    m_clientQueue.enqueue(m_clientThreads[clientId]);
  //qDebug() << QString("%1 clients waiting").arg(m_clientQueue.count());
  mutex1.unlock();

}

int BarberShop::popReadyClient()
{
  int id = -1;
  mutex1.lock();
  if(!m_clientQueue.isEmpty()){

    id = m_clientQueue.dequeue()->id();
    //qDebug() << "Que was not empty! client id is: " << id;
  }

  mutex1.unlock();

  return id;
}


BarberShop::BarberShop(QObject *parent, unsigned int barberCapacity, unsigned int seatCapacity, unsigned long haircutServiceTime):
  QObject(parent),m_barberCapacity(barberCapacity),m_seatCapacity(seatCapacity),m_haircutServiceTime(haircutServiceTime)
{
  for(unsigned int i=0; i<m_barberCapacity;i++){
    BarberThread* bthread = new BarberThread(nullptr,i,m_haircutServiceTime);
    m_barberThreads[i] = bthread;
    //bthread->start();
  }
  for(unsigned int i=0; i<MaxNumberOfClients;i++){
    ClientThread* cthread = new ClientThread(nullptr,i);
    m_clientThreads[i] = cthread;
  }

}

unsigned int BarberShop::getHaircutServiceTime() const
{
  return m_haircutServiceTime;
}

void BarberShop::setHaircutServiceTime(unsigned int haircutServiceTime)
{
  m_haircutServiceTime = haircutServiceTime;
}

unsigned int BarberShop::getSeatCapacity() const
{
  return m_seatCapacity;
}

void BarberShop::setSeatCapacity(unsigned int seatCapacity)
{
  m_seatCapacity = seatCapacity;
}

unsigned int BarberShop::getBarberCapacity() const
{
  return m_barberCapacity;
}

void BarberShop::setBarberCapacity(unsigned int barberCapacity)
{
  m_barberCapacity = barberCapacity;
}

QQueue<ClientThread *> BarberShop::getClientQueue() const
{
  return m_clientQueue;
}
