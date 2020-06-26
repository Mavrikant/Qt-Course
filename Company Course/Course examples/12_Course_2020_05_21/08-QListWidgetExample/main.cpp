//main.cpp
#include <QApplication>
#include "listwidget.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  ListWidget window;

  window.setWindowTitle("QListWidget");
  window.show();

  return app.exec();
}
