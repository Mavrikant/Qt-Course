#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

    void on_style1Button_clicked();

    void on_style2Button_clicked();

    void on_style3Button_clicked();

    void on_restoreButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
