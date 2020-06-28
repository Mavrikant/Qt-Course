#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_style1Button_clicked()
{
    QPalette palette = ui->label->palette();
    palette.setColor(QPalette::Window, Qt::blue);
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->label->setPalette(palette);
}

void Widget::on_style2Button_clicked()
{
    QPalette palette = ui->label->palette();
    palette.setColor(QPalette::Window, Qt::black);
    palette.setColor(QPalette::WindowText, Qt::white);
    ui->label->setPalette(palette);
}

void Widget::on_style3Button_clicked()
{
    QPalette palette = ui->label->palette();
    palette.setColor(QPalette::Window, Qt::yellow);
    palette.setColor(QPalette::WindowText, Qt::green);
    ui->label->setPalette(palette);
}

void Widget::on_restoreButton_clicked()
{
    QLabel *tempLabel = new QLabel;
    ui->label->setPalette(tempLabel->palette());
    delete tempLabel;
}
