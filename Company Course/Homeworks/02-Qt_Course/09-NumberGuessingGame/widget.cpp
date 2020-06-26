#include "widget.h"
#include "ui_widget.h"
#include "stdlib.h"
#include <time.h>
#include <QDebug>
#include <QMessageBox>
#include <QMovie>

Widget::Widget(QWidget *parent) :    QWidget(parent),    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "*********** Start ***********";
    srand (static_cast<unsigned int>((time(nullptr))));
    secretNumber = rand() % 100 + 1;
    qDebug() << "Secret number" << secretNumber;
    tryCount = 0;
    ui->restartButton->setDisabled(true);
    QMovie *movie = new QMovie(":/thinking.gif");
    ui->gitLabel->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    tryCount++;
    guessNumber = ui->inputBox->value();
    qDebug().nospace() << "Guess #" << tryCount << " = " << guessNumber;
    if (guessNumber == secretNumber)
    {
        ui->messageLabel->setText("Congratulations, number=" + QString::number(guessNumber));
        QMessageBox::information(this, "Result",
                                 "You guessed it with " + QString::number(tryCount) + " try.");
        ui->guessButton->setDisabled(true);
        ui->restartButton->setEnabled(true);
    }
    else if (guessNumber < secretNumber)
    {
        ui->messageLabel->setText("My number is higher");
    }
    else
    {
        ui->messageLabel->setText("My number is lower");
    }
}

void Widget::on_restartButton_clicked()
{
    secretNumber = rand() % 100 + 1;
    qDebug() << "*********** Restart ***********";
    qDebug() << "Secret number=" << secretNumber;
    tryCount = 0;
    ui->guessButton->setEnabled(true);
    ui->restartButton->setDisabled(true);
    ui->messageLabel->setText("Guess Again");
    ui->inputBox->setValue(1);
}
