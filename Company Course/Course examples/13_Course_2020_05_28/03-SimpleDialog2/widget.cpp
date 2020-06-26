#include "widget.h"
#include "dialog2.h"
#include <QtWidgets>
#include <QtDebug>
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QPushButton *pb1 = new QPushButton(tr("&Open Dialog Modal"), this);
    QPushButton *pb2 = new QPushButton(tr("&Open Dialog Modless"), this);
    vbox->addWidget(pb1);
    vbox->addWidget(pb2);
    connect(pb1, &QPushButton::clicked, this, &Widget::onShowModalDialog);
    connect(pb2, &QPushButton::clicked, this, &Widget::onShowModelessDialog);
    setLayout(vbox);
}

void Widget::onShowModelessDialog()
{
    Dialog2 *wd = new Dialog2(this);
    //wd->setModal(true);
    connect(wd, &Dialog2::accepted, []()
    {
        qDebug("Accepted");
    });
    wd->show();
}

void Widget::onShowModalDialog()
{
    Dialog2 wd;
    if (wd.exec() == QDialog::Accepted)
    {
        qDebug("Accepted");
    }
    else
    {
        qDebug("Canceled");
    }
}

