#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString path = "D:/";// /home/username/Downloads

    //Dir Model
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::AllEntries | QDir::Dirs | QDir::Hidden);
    dirModel->setRootPath(path);
    ui->treeView->setModel(dirModel);

    //Files Model
    filesModel = new QFileSystemModel(this);
    filesModel->setFilter(QDir::AllEntries | QDir::Files | QDir::Hidden);
    filesModel->setRootPath(path);//Required for model to load file system info
    ui->listView->setModel(filesModel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_treeView_clicked(const QModelIndex &index)
{
    QString path = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filesModel->setRootPath(path + "/"));
}

QString Widget::size_human(int size)
{
    float num = size;
    QStringList list;
    list << "KB" << "MB" << "GB" << "TB";

    QStringListIterator i(list);
    QString unit("bytes");

    while (num >= 1024.0 && i.hasNext())
    {
        unit = i.next();
        num /= 1024.0;
    }
    return QString().setNum(num, 'f', 2) + " " + unit;
}

void Widget::on_listView_clicked(const QModelIndex &index)
{
    QFileInfo selectedFile = dirModel->fileInfo(index);
    QString size = size_human( selectedFile.size());

    QMessageBox::information(this, "File Info",
                             "File path: " + selectedFile.absoluteFilePath() + "\n" +
                             "File size: " + size + "\n" +
                             "File lastModified date: " + QDateTime(selectedFile.lastModified()).toString("dd.MM.yyyy") + "\n"
                             "File owner: " + selectedFile.owner()
                            );
}
