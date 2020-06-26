#include "widget.h"
#include <QPushButton>
#include <QTextStream>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  QPushButton *button = new QPushButton("Press Button",this);

  connect(button, &QPushButton::clicked,
  this, &Widget::foo);

}

Widget::~Widget()
{

}

void Widget::foo()
{
  QTextStream out(stdout);

  out << "Button clicked!" << endl;

}
