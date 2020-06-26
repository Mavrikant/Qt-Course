#include "widget.h"
#include <QApplication>
#include <QRect>
#include <QScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *widgets[20];
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    for ( int fooInt = static_cast<int>(DrawingOption::RadialGradient); static_cast<DrawingOption>(fooInt) >= DrawingOption::Lines ; fooInt-- )
    {

        DrawingOption foo = static_cast<DrawingOption>(fooInt);
        widgets[fooInt] = new Widget(foo);
        widgets[fooInt]->setGeometry(width / 2 - fooInt * 40, height / 2 - fooInt * 40, 600, 600);
        widgets[fooInt]->show();
    }
    //Widget * w = new Widget(DrawingOption::Lines);
    //Widget * w = new Widget(DrawingOption::Colours);
    //w->show();
    return a.exec();
}
