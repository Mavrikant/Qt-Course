#ifndef UDPPEER_H
#define UDPPEER_H

#include <QObject>
#include <QUdpSocket>

class UdpPeer : public QObject
{
  Q_OBJECT
public:
  explicit UdpPeer(QObject *parent = nullptr);
  void selamVer();
  void selamAl();
private:
  QUdpSocket *socket;
signals:

public slots:
  void readyRead();
};

#endif // UDPPEER_H
