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

Numpad::Numpad(QWidget *parent): QWidget(parent)
{
    const QSize btnSize = QSize(50, 40);

    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    QLineEdit  *line = new QLineEdit();
    line->setReadOnly(true);
    line->setEchoMode(QLineEdit::Password);
    line->setAlignment(Qt::AlignHCenter);
    grid->addWidget(line, 0, 0, 1, 3);

    QPushButton *buttons[10];

    for (int i = 1; i <= 9; i++)
    {
        buttons[i] = new QPushButton(QString::number(i));
        buttons[i]->setFixedSize(btnSize);
        grid->addWidget(buttons[i], 1 + (i - 1) / 3,  (i - 1) % 3, 1, 1);
        connect(buttons[i], &QPushButton::clicked, [line, i]()
        {
            line->setText(line->text() + QString::number(i));
        });
    }

    //Delete button
    QPushButton *buttonDel = new QPushButton("<");
    buttonDel->setFixedSize(btnSize);
    grid->addWidget(buttonDel, 4, 0, 1, 1);
    connect(buttonDel, &QPushButton::clicked, [line]()
    {
        line->backspace();
    });//Delete button

    //Zero button
    QPushButton *button0 = new QPushButton("0");
    button0->setFixedSize(btnSize);
    grid->addWidget(button0, 4, 1, 1, 1);
    connect(button0, &QPushButton::clicked, [line]()
    {
        line->setText(line->text() + QString::number(0));
    });//Zero button


    //OK Button
    QPushButton *buttonOK = new QPushButton("OK");
    buttonOK->setFixedSize(btnSize);
    grid->addWidget(buttonOK, 4, 2, 1, 1);
    connect(buttonOK, &QPushButton::clicked, [line]()
    {
        qDebug() << line->text();
        line->clear();
    });//OK Button


}
