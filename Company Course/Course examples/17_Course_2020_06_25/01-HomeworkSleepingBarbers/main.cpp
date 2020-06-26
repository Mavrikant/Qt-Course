#include <QCoreApplication>
#include <barbershop.h>

int main(int argc, char *argv[])
{
  Q_UNUSED(argc);
  Q_UNUSED(argv);
  BarberShop *shop = BarberShop::getInstance();
  shop->setProperties(nullptr,2,5,40000);//2 barbers, 5 seats, 40 ms service time
  shop->startClients();

}
