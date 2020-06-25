#include "toolbar.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Toolbar window;

    window.resize(300, 200);
    window.setWindowTitle("QToolBar");
    window.show();

    return app.exec();
}
