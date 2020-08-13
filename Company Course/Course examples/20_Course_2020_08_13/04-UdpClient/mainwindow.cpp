#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->portReceiveLineEdit->setValidator(new QIntValidator(1, 65535, this));

  // find out which IP to connect to
  QString ipAddress;
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // use the first non-localhost IPv4 address
  for (int i = 0; i < ipAddressesList.size(); ++i) {
      if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
          ipAddressesList.at(i).toIPv4Address()) {
          ipAddress = ipAddressesList.at(i).toString();
          break;
      }
  }
  // if we did not find one, use IPv4 localhost
  if (ipAddress.isEmpty())
      ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
  ui->hostLocalLineEdit->setText(ipAddress);
  ui->hostRemoteLineEdit->setText(ipAddress);
  // create a QUDP socket
  socketReceive = new QUdpSocket(this);
  socketSend = new QUdpSocket(this);
  on_pushButton_clicked();//use initial values to bind
  connect(socketReceive, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(ui->sayHelloPushButton, SIGNAL(clicked()), this, SLOT(selamVer()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  // The most common way to use QUdpSocket class is
  // to bind to an address and port using bind()
  // bool QAbstractSocket::bind(const QHostAddress & address,
  //     quint16 port = 0, BindMode mode = DefaultForPlatform)
  socketReceive->close();
  socketReceive->bind( QHostAddress(ui->hostLocalLineEdit->text()), ui->portReceiveLineEdit->text().toInt());

  QStringList strList;
  strList << "Hazır! ";
  strList << QString("Adres: %1").arg(ui->hostLocalLineEdit->text());
  strList << QString("Port: %1").arg(ui->portReceiveLineEdit->text());
  statusBar()->showMessage(strList.join(" | "));
}
void MainWindow::selamVer()
{
  QByteArray Data;
  Data.append("Selamun aleykum bro!");

  // Sends the datagram datagram
  // to the host address and at port.
  // qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
  //                      const QHostAddress & host, quint16 port)
  socketSend->writeDatagram(Data, QHostAddress(ui->hostRemoteLineEdit->text()), ui->portSendLineEdit->text().toInt());
}

void MainWindow::selamAl()
{
  QByteArray Data;
  Data.append("Aleykum selam bro!");

  // Sends the datagram datagram
  // to the host address and at port.
  // qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
  //                      const QHostAddress & host, quint16 port)
  socketSend->writeDatagram(Data, QHostAddress(ui->hostRemoteLineEdit->text()), ui->portSendLineEdit->text().toInt());
}

void MainWindow::readyRead()
{
  // when data comes in
  QByteArray buffer;
  buffer.resize(socketReceive->pendingDatagramSize());

  QHostAddress sender;
  quint16 senderPort;

  // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
  //                 QHostAddress * address = 0, quint16 * port = 0)
  // Receives a datagram no larger than maxSize bytes and stores it in data.
  // The sender's host address and port is stored in *address and *port
  // (unless the pointers are 0).

  socketReceive->readDatagram(buffer.data(), buffer.size(),
                       &sender, &senderPort);
  QStringList strList;
  strList << QString("<yeni mesaj geldi!>: %1").arg(sender.toString());
  strList <<  QString("<mesaj portu>: %1").arg(senderPort);
  strList << QString("<mesaj>: %1").arg(QString(buffer));
  qDebug() << strList;
  ui->plainTextEdit->appendPlainText( strList.join("\r\n"));
  QString msg(buffer);
  if(msg.indexOf("Selamun") >= 0)
    selamAl();
}
