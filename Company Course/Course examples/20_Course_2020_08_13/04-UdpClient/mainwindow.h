#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QUdpSocket;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void selamAl();
private:
  QUdpSocket *socketReceive;
  QUdpSocket *socketSend;
private slots:
  void on_pushButton_clicked();
  void readyRead();
  void selamVer();
private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
