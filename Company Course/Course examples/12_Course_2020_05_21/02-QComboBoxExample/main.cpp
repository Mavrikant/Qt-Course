//main.cpp
#include "comboboxex.h"
#include <QApplication>

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  ComboBoxEx window;

  window.resize(300, 150);
  window.setWindowTitle("QComboBox");
  window.show();

  return app.exec();
}
