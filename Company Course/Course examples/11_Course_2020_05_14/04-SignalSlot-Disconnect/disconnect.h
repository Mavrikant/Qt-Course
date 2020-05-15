//disconnect.h
#pragma once

#include <QWidget>
#include <QPushButton>

class Disconnect : public QWidget
{

	Q_OBJECT

public:
	Disconnect(QWidget *parent = nullptr);

private slots:
	void onClick();
	void onCheck(int);

private:
	QPushButton *clickBtn;
};
