//main.cpp
#include "spinboxex.h"
#include <QApplication>

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  SpinBox window;

  window.resize(250, 150);
  window.setWindowTitle("QSpinBox");
  window.show();

  return app.exec();
}
