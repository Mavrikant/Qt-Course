//main.cpp
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget window;
  window.resize(250, 150);
  window.setWindowTitle("Click");
  window.show();

  return a.exec();
}
