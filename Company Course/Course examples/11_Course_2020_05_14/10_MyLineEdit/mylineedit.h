#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLabel>

class MyLineEdit : public QWidget
{
	Q_OBJECT

public:
	MyLineEdit(QWidget *parent = nullptr);
	~MyLineEdit();
	void keyPressEvent(QKeyEvent *event) override;
	QString text();
	void setText(QString &text);

private:
	QString m_stored_text;
	QLabel label;
};
#endif // MYLINEEDIT_H
