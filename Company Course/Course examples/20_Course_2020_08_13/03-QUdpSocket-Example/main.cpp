#include <QCoreApplication>
#include <udppeer.h>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  UdpPeer client;

  client.selamVer();

  return a.exec();
}
