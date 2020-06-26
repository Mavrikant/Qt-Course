#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString strFileSelected;
    QLabel *lbFile;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void onFileOpenClicked();
    void setPicture(QString fileName);
};

#endif // MAINWINDOW_H
