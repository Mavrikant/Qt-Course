#include "widget.h"
#include <QtWidgets>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawLine(20, 20, 20, 200);
}
