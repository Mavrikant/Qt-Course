#include "widget.h"
#include "numpad.h"

#include <QIcon>
#include <QPushButton>
#include <QGridLayout>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>

Widget::Widget(QWidget *parent): QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    QPushButton  *button = new QPushButton("Login");
    grid->addWidget(button, 0, 0, 1, 1);

    QLabel *label = new QLabel("asda");
    label->setAlignment(Qt::AlignHCenter);
    grid->addWidget(label, 1, 0, 1, 1);

    connect(button, &QPushButton::clicked, []()
    {
        Numpad *numpad = new Numpad(this);
        int ret = numpad->exec();


    });


}

Widget::~Widget()
{

}
