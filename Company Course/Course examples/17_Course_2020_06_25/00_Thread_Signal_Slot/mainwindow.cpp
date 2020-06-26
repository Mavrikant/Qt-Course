#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Press Start");

    connect(&t1, &MyThread::valueChanged, ui->progressBar, &QProgressBar::setValue);
    connect(&t1, &MyThread::threadStarted, this, &MainWindow::on_Thread_Started);
    connect(&t1, &MyThread::threadFinished, this, &MainWindow::on_Thread_Finished);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    t1.start();
}

void MainWindow::on_Thread_Started()
{
    ui->statusbar->showMessage("Thread Started");
}

void MainWindow::on_Thread_Finished()
{
    ui->statusbar->showMessage("Thread Finished");

}
