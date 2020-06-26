#include "mainwindow.h"
#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QPixmap>
#include <QLabel>
#include <QFileDialog>
#include <QDir>
#include <QStatusBar>
#include <QScrollArea>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QAction *qaQuit = new QAction("&Quit", this);
    QAction *qaFileOpen = new QAction("&Open File", this);
    QMenu *qmFile;
    qmFile = menuBar()->addMenu("&File");
    qmFile->addAction(qaFileOpen);
    qmFile->addAction(qaQuit);

    lbFile = new QLabel(this);
    lbFile->setBackgroundRole(QPalette::Base);
    lbFile->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lbFile->setScaledContents(true);

    setPicture("D:/qt_egitim/icons/qtlogo.png");
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(lbFile);

    setCentralWidget(scrollArea);
    connect(qaQuit, &QAction::triggered, qApp, QApplication::quit);
    connect(qaFileOpen, &QAction::triggered, this, &MainWindow::onFileOpenClicked);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onFileOpenClicked()
{
    QDir dir(strFileSelected);

    QFileDialog fileDialog(this, tr("Bir dosya seçiniz"), dir.dirName());
    QStringList filters;
    filters << "All File (*.*)" << "Picture Files (*.png,*.jpg)";
    fileDialog.setNameFilters(filters);

    if (fileDialog.exec() == QFileDialog::Accepted)
    {
        statusBar()->showMessage(fileDialog.selectedFiles()[0], 5000);
        setPicture(fileDialog.selectedFiles()[0]);
    }
}

void MainWindow::setPicture(QString fileName)
{
    if (QFile::exists(fileName))
    {
        QPixmap px(fileName);
        lbFile->setPixmap(px);
        lbFile->adjustSize();
        strFileSelected = fileName;
    }
}
