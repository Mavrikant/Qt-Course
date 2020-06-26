//widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

class Widget : public QWidget
{
  Q_OBJECT
private:
  QSlider *slider;
  QLabel *label;
public:
  Widget(QWidget *parent = 0);
  ~Widget();
};

#endif // WIDGET_H
