#include "simplemenu.h"
#include <QMenu>
#include <QMenuBar>
#include <QDebug>

SimpleMenu::SimpleMenu(QWidget *parent)
    : QMainWindow(parent)
{

    QAction *quit = new QAction("&Quit", this);
    QAction *new_button = new QAction("&New", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");

    file->addAction(new_button);
    file->addAction(quit);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(new_button, SIGNAL(triggered()), this, SLOT(on_ItemClick()));
}

void SimpleMenu::on_ItemClick()
{
    qDebug("new_button Clicked!");
}
