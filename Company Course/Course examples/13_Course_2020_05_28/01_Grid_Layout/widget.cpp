#include "widget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>




Widget::Widget(QWidget *parent)
	: QWidget(parent)
{

	QGridLayout *grid = new QGridLayout(this);
	grid->setSpacing(2);
	QLabel *text1 = new QLabel("Label1", this);
	grid->addWidget(text1, 0, 0, 1, 1);

	QComboBox *QComboBox1 = new QComboBox(this);
	grid->addWidget(QComboBox1, 0, 1, 1, 1, Qt::AlignLeft);


	QLabel *text2 = new QLabel("Label2", this);
	grid->addWidget(text2, 1, 0, 1, 1);

	QComboBox *QComboBox2 = new QComboBox(this);
	grid->addWidget(QComboBox2, 1, 1, 1, 1, Qt::AlignLeft);

	setLayout(grid);

}


Widget::~Widget()
{
}

