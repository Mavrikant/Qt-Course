#include "widget.h"
#include "widget.h"
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
    const QSize btnSize = QSize(50, 50);

    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    QLineEdit  *line = new QLineEdit();
    line->setReadOnly(true);
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

    buttons[0] = new QPushButton(QString::number(0));
    buttons[0]->setFixedSize(btnSize);
    grid->addWidget(buttons[0], 4, 1, 1, 1);
    connect(buttons[0], &QPushButton::clicked, [line]()
    {
        line->setText(line->text() + QString::number(0));
    });

    QPushButton  *deleteButton = new QPushButton("Delete");
    grid->addWidget(deleteButton, 1 + 10 / 3, 1 + 10 % 3, 1, 1); //Delete button
    connect(deleteButton, &QPushButton::clicked, this, [ = ]()
    {
        line->backspace();
    });
    deleteButton->setFixedSize(btnSize); //Delete button


    QPushButton  *OKButton = new QPushButton("OK");
    grid->addWidget(OKButton, 4, 0, 1, 1); //OK button
    connect(OKButton, &QPushButton::clicked, this, [ = ]()
    {
        line->clear();
    });
    OKButton->setFixedSize(btnSize); //OK button

}

