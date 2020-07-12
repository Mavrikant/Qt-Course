#include "mainwindow.h"
#include <QtWidgets>
#include <mylineedit.h>

MainWindow::MainWindow(QWidget *parent) :
  QWidget(parent)
{
  QVBoxLayout *vbox = new QVBoxLayout;
  MyLineEdit *le = new MyLineEdit();
  le->show();
  vbox->addWidget(le);
  setLayout(vbox);

}

MainWindow::~MainWindow()
{

}
