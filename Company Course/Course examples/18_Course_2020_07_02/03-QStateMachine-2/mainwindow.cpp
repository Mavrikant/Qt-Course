#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QState *s1 = new QState();
    QState *s11 = new QState(s1);
    QState *s12 = new QState(s1);
    QState *s13 = new QState(s1);

    s11->addTransition(ui->pushButton, &QPushButton::clicked, s12);
    s12->addTransition(ui->pushButton, &QPushButton::clicked, s13);
    s13->addTransition(ui->pushButton, &QPushButton::clicked, s11);

    s1->setInitialState(s11);
    machine.addState(s1);

    QFinalState *s2 = new QFinalState();
    s1->addTransition(ui->pbQuit, &QPushButton::clicked, s2);
    machine.addState(s2);
    machine.setInitialState(s1);

    QObject::connect(&machine, &QStateMachine::finished,
                     QCoreApplication::instance(),      &QCoreApplication::quit);
    s1->assignProperty(ui->label, "text", "In state s1");
    s11->assignProperty(ui->label, "text", "In state s11");
    s12->assignProperty(ui->label, "text", "In state s12");
    s13->assignProperty(ui->label, "text", "In state s13");

    QObject::connect(s13, &QState::entered, this, &MainWindow::showMaximized);
    QObject::connect(s13, &QState::exited, this, &MainWindow::showNormal);

    machine.start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
