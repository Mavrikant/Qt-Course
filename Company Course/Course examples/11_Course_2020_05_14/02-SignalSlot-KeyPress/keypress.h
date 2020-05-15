//keypress.h
#pragma once

#include <QWidget>

class KeyPress : public QWidget
{

public:
	KeyPress(QWidget *parent = nullptr);

protected:
	void keyPressEvent(QKeyEvent *e);
};

