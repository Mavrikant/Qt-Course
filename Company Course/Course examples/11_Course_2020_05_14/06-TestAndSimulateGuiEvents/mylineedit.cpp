#include "mylineedit.h"
#include <QRegExpValidator>

QString MyLineEdit::text() const
{
	return m_text;
}

void MyLineEdit::setText(const QString &text)
{
	int pos = 0;
	QString str = text;
	if (validator->validate(str, pos) != QValidator::Invalid)
		m_text = text;
}

MyLineEdit::MyLineEdit(QWidget *parent) : QWidget(parent)
{
	/*
	^    : start of string
	[    : beginning of character group
	a-z  : any lowercase letter
	A-Z  : any uppercase letter
	0-9  : any digit
	_    : underscore
	]    : end of character group
	*    : zero or more of the given characters
	\w   : word character
	\s   : space character
	\d   : digit
	$    : end of string
	*/
	QRegExp rx("^[\\w\\s\\d_]*$");
	QValidator *v = new QRegExpValidator(rx, this);
	validator = v;
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
	QString str = "";
	if (event->key() == Qt::Key_Backspace)
	{
		if (m_text.length() > 0)
			str = m_text.left(m_text.length() - 1);
	}
	else
	{
		str = QString("%1%2").arg(m_text).arg(event->text());
	}
	setText(str);
}
