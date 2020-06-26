#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap(":/images/qtlogo.png"));
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(pixmapItem);
    View w1, w2;
    w1.setScene(scene);
    w1.show();
    w2.setScene(scene);
    w2.show();

    return a.exec();
}
