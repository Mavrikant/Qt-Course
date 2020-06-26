#include "scratchpadwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScratchpadWidget w;
    w.resize(600, 600);
    w.show();

    return a.exec();
}
