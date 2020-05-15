#include "mylineedit.h"
#include <QDebug>
#include <QKeyEvent>
#include <QLabel>

MyLineEdit::MyLineEdit(QWidget *parent)
	: QWidget(parent)
{
	label.setBuddy(this);
}

MyLineEdit::~MyLineEdit()
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Backspace)
	{
		m_stored_text.chop(1);
	}
	else
	{
		m_stored_text.append(event->text());
	}
	qDebug() << event->text() << "pressed";
	qDebug() << m_stored_text << "all text";
	label.clear();
	label.setText(m_stored_text);
	label.show();


}

QString MyLineEdit::text()
{
	return m_stored_text;
}

void MyLineEdit::setText(QString &text)
{
	m_stored_text = text;
}


