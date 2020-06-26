#ifndef BARBERSHOP_H
#define BARBERSHOP_H
#include <QQueue>
#include <QMap>
#include <barberthread.h>
#include <clientthread.h>
#include <QObject>
class BarberShop: public QObject
{
public:
  static const unsigned int BarberCapacity = 2;
  static const unsigned int SeatCapacity = 5;
  static const unsigned int HaircutServiceTime = 20000;//in useconds
  static const unsigned int MaxNumberOfClients = 100;
  static BarberShop * getInstance();
  void setProperties(QObject* parent = nullptr,unsigned int barberCapacitiy=BarberCapacity, unsigned int seatCapacity=SeatCapacity, unsigned long haircutServiceTime=HaircutServiceTime);
  void startClients();
  void addClientToWaitingQue(int clientId);
  int popReadyClient();
  QQueue<ClientThread *> getClientQueue() const;

  unsigned int getBarberCapacity() const;
  void setBarberCapacity(unsigned int barberCapacity);

  unsigned int getSeatCapacity() const;
  void setSeatCapacity(unsigned int seatCapacity);

  unsigned int getHaircutServiceTime() const;
  void setHaircutServiceTime(unsigned int haircutServiceTime);

private:
  BarberShop(QObject* parent = nullptr,unsigned int barberCapacitiy=BarberCapacity, unsigned int seatCapacity=SeatCapacity, unsigned long haircutServiceTime=HaircutServiceTime);
  static BarberShop *instance;
  unsigned int m_barberCapacity;
  unsigned int m_seatCapacity;
  unsigned int m_haircutServiceTime;//in useconds

  QMap<unsigned int, BarberThread*> m_barberThreads;
  QMap<unsigned int, ClientThread*> m_clientThreads;
  QQueue<ClientThread*> m_clientQueue;
};

#endif // BARBERSHOP_H
