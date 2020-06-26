#include "view.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QKeyEvent>

View::View(QWidget *parent) :
    QGraphicsView(parent)
{
    setDragMode(QGraphicsView::ScrollHandDrag);
}

void View::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().ry() < 0)
        scale(1.25, 1.25);
    else
        scale(0.8, 0.8);
}

void View::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
        rotate(1);
    else if (event->key() == Qt::Key_Right)
        rotate(-1);
}
