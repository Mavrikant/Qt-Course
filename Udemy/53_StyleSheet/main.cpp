#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set style sheet appliation wise.
    a.setStyleSheet("QPushButton{color : yellow ; background-color : grey;}");
    Widget w;
    w.show();

    return a.exec();
}
