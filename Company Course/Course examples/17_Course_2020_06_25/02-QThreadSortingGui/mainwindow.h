#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  const static size_t ArraySize = 80000;
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_btnStart_clicked();

  void on_btnClose_clicked();
  void on_sorting_finished();
private:
  Ui::MainWindow *ui;
  QVector<int> array1;
  QVector<int> array2;
  QVector<int> array3;
};

#endif // MAINWINDOW_H
