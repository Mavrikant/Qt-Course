#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_listView_clicked(const QModelIndex &index);

private:
    QString size_human(int size);
    Ui::Widget *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *filesModel;
};

#endif // WIDGET_H
