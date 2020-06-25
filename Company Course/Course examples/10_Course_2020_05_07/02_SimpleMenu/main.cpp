#include "simplemenu.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    SimpleMenu window;

    window.resize(250, 150);
    window.setWindowTitle("Simple menu");
    window.show();

    return app.exec();
}
