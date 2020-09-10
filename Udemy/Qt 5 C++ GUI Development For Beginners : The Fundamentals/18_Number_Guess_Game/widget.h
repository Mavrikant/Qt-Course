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
    void on_guessButton_clicked();

    void on_restartButton_clicked();

private:
    Ui::Widget *ui;
    int secretNumber;
    int guessNumber;
    int tryCount;
};

#endif // WIDGET_H
