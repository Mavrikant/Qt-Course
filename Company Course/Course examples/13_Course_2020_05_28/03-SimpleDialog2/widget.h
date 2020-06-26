#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

public slots:
    void onShowModelessDialog();
    void onShowModalDialog();
};

#endif // WIDGET_H
