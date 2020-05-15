#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *vbox = new QVBoxLayout(this);
	label = new QLabel(this);
	vbox->addWidget(label);
	for (int digit = 1; digit <= 3; ++digit)
	{
		QString text = QString::number(digit);
		QPushButton *button = new QPushButton(text);
		vbox->addWidget(button);

		connect(button, &QPushButton::clicked, [this, digit]()
		{
			onPushButtonClicked(digit);
		});
	}
	setLayout(vbox);
}

void Widget::onPushButtonClicked(int ix)
{
	label->setText(QString(tr("Button #%1 clicked!")).arg(ix));
}

Widget::~Widget()
{

}
