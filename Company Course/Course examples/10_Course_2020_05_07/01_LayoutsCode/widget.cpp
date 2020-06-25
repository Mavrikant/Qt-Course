#include "widget.h"
#include <QWidget>

#include <QPushButton>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //QHBoxLayout *anotherLayout = new QHBoxLayout(this);

    for (int i = 0; i < 4; i++)
    {
        QPushButton *pb = new QPushButton("Button_" + QString::number(i + 1), this);
        vbox1.addWidget(pb);
    }
    for (int i = 0; i < 4; i++)
    {
        QLabel *lb = new QLabel("Label_" + QString::number(i + 1), this);
        vbox2.addWidget(lb);
    }
    hbox.addLayout(&vbox1);
    hbox.addLayout(&vbox2);
    setLayout(&hbox);

}

Widget::~Widget()
{

}
