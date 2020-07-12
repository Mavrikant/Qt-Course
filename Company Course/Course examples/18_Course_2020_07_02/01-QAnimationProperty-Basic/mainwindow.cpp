#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbStart_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pbAnimated, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(QRect(0, 0, 100, 30));
    animation->setEndValue(QRect(250, 250, 100, 30));

    animation->start();

}

void MainWindow::on_pbStart_2_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pbAnimated, "geometry");
    animation->setDuration(10000);

    animation->setKeyValueAt(0, QRect(0, 0, 100, 30));
    animation->setKeyValueAt(0.8, QRect(250, 250, 100, 30));
    animation->setKeyValueAt(1, QRect(0, 0, 100, 30));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::on_pbStart_3_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pbAnimated, "geometry");
    animation->setDuration(3000);

    animation->setStartValue(QRect(0, 0, 100, 30));
    animation->setEndValue(QRect(250, 250, 100, 30));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::on_pbStart_4_clicked()
{
    QPropertyAnimation *anim1 = new QPropertyAnimation(ui->pbAnimated, "geometry");
    // Set up anim1
    anim1->setDuration(3000);
    anim1->setStartValue(QRect(0, 0, 100, 30));
    anim1->setEndValue(QRect(500, 500, 100, 30));
    anim1->setEasingCurve(QEasingCurve::OutBounce);
    QPropertyAnimation *anim2 = new QPropertyAnimation(ui->pbAnimated_2, "geometry");
    // Set up anim2
    anim2->setDuration(3000);
    anim2->setStartValue(QRect(500, 500, 100, 30));
    anim2->setEndValue(QRect(0, 0, 100, 30));
    anim2->setEasingCurve(QEasingCurve::OutBounce);
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(anim1);
    group->addAnimation(anim2);

    group->start(QAbstractAnimation::DeleteWhenStopped);
}
