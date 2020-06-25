#pragma once

#include <QMainWindow>
#include <QApplication>

class SimpleMenu : public QMainWindow
{
    Q_OBJECT
public:
    SimpleMenu(QWidget *parent = 0);
private slots:
    void on_ItemClick();
};


