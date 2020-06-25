#include "checkable.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Checkable window;

    window.resize(250, 150);
    window.setWindowTitle("Checkable menu");
    window.show();

    return app.exec();
}
