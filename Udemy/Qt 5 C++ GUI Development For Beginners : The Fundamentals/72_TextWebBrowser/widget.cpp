#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    netManager =  new QNetworkAccessManager(this);
    netReply = nullptr;
    mDataBuffer = new QByteArray();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dataReadyToRead()
{
    qDebug() << "Some data available";
    mDataBuffer->append(netReply->readAll());
}

void Widget::dataReadFinished()
{
    if (netReply->error())
    {
        qDebug() << " Error : " << netReply->errorString();
        ui->resultArea->clear();
        QMessageBox::information(this, "Error", netReply->errorString());
    }
    else
    {
        qDebug() << "Data read finished!";
        ui->resultArea->setPlainText(QString(*mDataBuffer));
        mDataBuffer->clear();
    }
}

void Widget::on_getButton_clicked()
{
    QNetworkRequest request;
    request.setUrl(QUrl(ui->pageAdress->toPlainText()));

    netReply = netManager->get(request);
    connect(netReply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect(netReply, &QNetworkReply::finished, this, &Widget::dataReadFinished);
}
