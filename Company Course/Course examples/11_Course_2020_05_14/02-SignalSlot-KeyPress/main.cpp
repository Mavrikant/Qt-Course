//main.cpp
#include <QApplication>
#include "keypress.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  KeyPress window;

  window.resize(250, 150);
  window.setWindowTitle("Key press");
  window.show();

  return app.exec();
}
