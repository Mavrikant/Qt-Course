//move.cpp
#include <QMoveEvent>
#include "move.h"

Move::Move(QWidget *parent)
    : QWidget(parent)
{


}

/**
 * @brief Move::moveEvent bir pencere ekran uzerinde hareket ettirilirse tetiklenir. Ornek kodu denemek icin pencereyi
 *  ust cercevesinden tutarak hareket ettiriniz.
 * @param e
 */
void Move::moveEvent(QMoveEvent *e) {

  int x = e->pos().x();
  int y = e->pos().y();

  QString text = QString::number(x) + "," + QString::number(y);

  setWindowTitle(text);

}
