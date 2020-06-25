#include "skeleton.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    Skeleton window;

    window.resize(350, 250);
    window.setWindowTitle("Application skeleton");
    window.show();

    return app.exec();
}
