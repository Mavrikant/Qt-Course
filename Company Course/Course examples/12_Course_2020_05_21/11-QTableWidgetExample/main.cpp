//main.cpp
#include <QApplication>
#include "table.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Table window;

  window.resize(400, 250);
  window.setWindowTitle("QTableWidget");
  window.show();

  return app.exec();
}
