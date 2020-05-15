#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QString>
#include <QKeyEvent>
#include <QValidator>

class MyLineEdit : public QWidget
{
	Q_OBJECT
private:
	QString m_text;
	QValidator *validator;
public:
	explicit MyLineEdit(QWidget *parent = nullptr);
	void keyPressEvent(QKeyEvent *event) override;

	QString text() const;
	void setText(const QString &text);

signals:

public slots:
};

#endif // MYLINEEDIT_H
