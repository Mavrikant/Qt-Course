//widget.cpp
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include "widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  QHBoxLayout *hbox = new QHBoxLayout(this);
  hbox->setSpacing(5);

  QPushButton *quitBtn = new QPushButton("Quit", this);
  hbox->addWidget(quitBtn, 0, Qt::AlignLeft | Qt::AlignTop);

  connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
  //Olay kaynagi: quitBtn
  //Olay hedefi: qApp, ilgili slot: quit()
  //Olay nesnesi: clicked()
}

Widget::~Widget()
{

}

