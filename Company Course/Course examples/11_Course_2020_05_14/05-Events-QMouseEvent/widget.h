#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QMenu>

class Widget : public QMainWindow
{
	Q_OBJECT
private:
	QAction *action1;
	QAction *action2;
public:
	Widget(QMainWindow *parent = nullptr);

protected:
	void mousePressEvent(QMouseEvent *event) override;
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
};

#endif // WIDGET_H
