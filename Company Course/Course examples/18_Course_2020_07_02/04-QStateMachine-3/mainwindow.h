#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStateMachine>


class MainWindow : public QWidget
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:

};

#endif // MAINWINDOW_H
