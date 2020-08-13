#include "udppeer.h"

UdpPeer::UdpPeer(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 1234);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void UdpPeer::selamVer()
{
    QByteArray Data;
    Data.append("Selam ver!");

    socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
}

void UdpPeer::selamAl()
{
    QByteArray Data;
    Data.append("Selam al!");

    socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
}

void UdpPeer::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    qDebug() << QString(40, '-');
    qDebug() << "<yeni mesaj geldi!>:";
    qDebug() << "IP: " << sender.toString();
    qDebug() << "Port: " << senderPort;
    qDebug() << "Mesaj: " << buffer;

    QString msg(buffer);
    if (msg == "Selam ver!")
        selamAl();
}
