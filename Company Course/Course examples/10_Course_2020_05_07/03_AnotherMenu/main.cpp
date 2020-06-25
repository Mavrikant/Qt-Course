#include "anothermenu.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    AnotherMenu window;

    window.resize(350, 200);
    window.setWindowTitle("Another menu");
    window.show();

    return app.exec();
}
