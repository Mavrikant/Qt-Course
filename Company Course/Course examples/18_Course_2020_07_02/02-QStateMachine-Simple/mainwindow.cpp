#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QState *s1 = new QState();
    QState *s2 = new QState();
    QState *s3 = new QState();

    s1->addTransition(ui->pushButton, &QPushButton::clicked, s2);
    s2->addTransition(ui->pushButton, &QPushButton::clicked, s3);
    s3->addTransition(ui->pushButton, &QPushButton::clicked, s1);

    machine.addState(s1);
    machine.addState(s2);
    machine.addState(s3);
    machine.setInitialState(s1);

    s1->assignProperty(ui->label, "text", "In state s1");
    s2->assignProperty(ui->label, "text", "In state s2");
    s3->assignProperty(ui->label, "text", "In state s3");

    QObject::connect(s3, &QState::entered, this, &MainWindow::showMaximized);
    QObject::connect(s3, &QState::exited, this, &MainWindow::showNormal);
    machine.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
