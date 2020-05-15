//keypress.cpp
#include <QApplication>
#include <QKeyEvent>
#include "keypress.h"

KeyPress::KeyPress(QWidget *parent)
    : QWidget(parent)
{ }

/**
 * @brief KeyPress::keyPressEvent
 * @param event
 * Olay kaynagi: giris cihazi, klavye
 * Olay hedefi: QWidget'tan turetilmis KeyPress sinifi turunden nesnemiz
 * Olay nesnesi: QKeyEvent
 */
void KeyPress::keyPressEvent(QKeyEvent *event) {

   if (event->key() == Qt::Key_Escape) {
       qApp->quit();
   }
}
