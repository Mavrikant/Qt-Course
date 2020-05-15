#pragma once

#include <QWidget>
#include <QLCDNumber>

class MyClock : public QLCDNumber
{
	Q_OBJECT
private slots:
	void showTime();
public:
	MyClock(QWidget *parent = nullptr);
	~MyClock();
};
