#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

class Widget : public QWidget
{
	Q_OBJECT

public:
	QLabel *label;
	Widget(QWidget *parent = nullptr);
	void onPushButtonClicked(int ix);
	~Widget();
};

#endif // WIDGET_H
