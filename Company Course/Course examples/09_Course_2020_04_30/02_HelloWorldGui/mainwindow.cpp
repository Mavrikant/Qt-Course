#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(tr("Merhaba GUI Dünyası :)\nBen Geldim!"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Close_clicked()
{
    QApplication::exit();
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(QString("\n%1: %2\n%3: %4\n%5: %6")
                       .arg(tr("Güncel tarih saat")).arg(QDateTime::currentDateTime().toString("d/M/yyyy hh:mm:ss"))
                       .arg(tr("Kullancı adı")).arg(ui->lineEditUserName->text())
                       .arg(tr("Şifre")).arg(ui->lineEditPassword->text()));
    ui->lcdNumber->display(56);
}
