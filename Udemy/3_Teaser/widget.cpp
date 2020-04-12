#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_send_button_clicked()
{
    qDebug()<<"Send message..";
    qDebug()<<"First Name:"<< ui->first_name_line_edit->text();
    qDebug()<<"Last Name:"<< ui->last_name_line_edit->text();
    qDebug()<<"Message:"<<ui->message_textEdit->toPlainText();
}
void Widget::on_clear_button_clicked()
{
    qDebug()<<"Clear message..";
    ui->first_name_line_edit->clear();
    ui->last_name_line_edit->clear();
    ui->message_textEdit->clear();
}
