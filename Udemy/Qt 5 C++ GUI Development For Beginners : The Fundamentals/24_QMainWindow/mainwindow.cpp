#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	QPushButton *button = new QPushButton("Hello", this);
	setCentralWidget(button);

	QAction *quitAction = new QAction("Quit");
	connect(quitAction, &QAction::triggered, [ = ]()
	{
		QApplication::quit();
	});


	QMenu *filemenu = menuBar()->addMenu("File");
	filemenu->addAction(quitAction);

	menuBar()->addMenu("Edit");
	menuBar()->addMenu("Setting");
	menuBar()->addMenu("Help");


	statusBar()->showMessage("Status message..", 3000);





}

MainWindow::~MainWindow()
{
}

