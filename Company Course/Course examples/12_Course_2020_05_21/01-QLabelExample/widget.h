//widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
class Widget : public QWidget
{
  Q_OBJECT
private:
  QLabel *labelImg;
  QLabel *labelText;
  QLabel *labelMovie;
  QMovie *movie;
public:
  Widget(QWidget *parent = 0);
  ~Widget();
  void playMovie();
};

#endif // WIDGET_H

