#include "widget.h"
#include <QMouseEvent>
#include <QStatusBar>
#include <QApplication>

Widget::Widget(QMainWindow *parent)
	: QMainWindow(parent)
{
	action1 = new QAction("Action 1", this);
	action2 = new QAction("Close", this);
	connect(action2, &QAction::triggered,
			qApp, &QApplication::quit);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		// handle left mouse button here
		statusBar()->showMessage(QString("You clicked coordinates (%1,%2)").arg(event->pos().x()).arg(
									 event->pos().y()));
	}
	else
	{
		// pass on other buttons to base class
		QWidget::mousePressEvent(event);
	}

}
#ifndef QT_NO_CONTEXTMENU
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu menu(this);
	menu.addAction(action1);
	menu.addAction(action2);
	menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

