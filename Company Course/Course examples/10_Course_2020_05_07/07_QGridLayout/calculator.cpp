#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(2);

    QList<QString> values({ "7", "8", "9", "/",
                            "4", "5", "6", "*",
                            "1", "2", "3", "-",
                            "0", ".", "=", "+"
                          });

    int pos = 0;
    QLineEdit *le = new QLineEdit(this);
    grid->addWidget(le, 0, 0, 1, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            QPushButton *btn = new QPushButton(values[pos], this);
            //btn->setFixedSize(40, 40);
            btn->setMinimumSize(40, 40);
            //btn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

            grid->addWidget(btn, i + 1, j, 1, 1);
            pos++;
        }
    }

    setLayout(grid);
}
