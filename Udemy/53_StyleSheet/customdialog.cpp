#include "customdialog.h"
#include "ui_customdialog.h"

CustomDialog::CustomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomDialog)
{
    ui->setupUi(this);

    //Set style sheed on specific widget
    ui->pushButton->setStyleSheet("QPushButton{background-color : qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(126, 14, 81, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.363184 rgba(234, 11, 11, 255), stop:0.577114 rgba(244, 70, 5, 255), stop:0.736318 rgba(255, 136, 0, 255), stop:0.935 rgba(239, 236, 55, 255));;color : white ;}");

}

CustomDialog::~CustomDialog()
{
    delete ui;
}
