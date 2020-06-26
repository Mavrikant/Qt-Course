/* main.cpp */
#include <QApplication>
#include "puff.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Puff window;

  window.resize(350, 280);
  window.setWindowTitle("Puff");
  window.show();

  return app.exec();
}
