/* puff.h */
#pragma once

#include <QWidget>

class Puff : public QWidget {

  public:
    Puff(QWidget *parent = 0);

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

  private:
    int x;
    qreal opacity;
    int timerId;

    void doPainting();
};
