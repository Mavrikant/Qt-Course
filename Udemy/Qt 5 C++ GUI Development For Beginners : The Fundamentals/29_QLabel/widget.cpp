#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	QPixmap image("://images/Primary_Flight_Display_of_a_Boeing_737-800.png");
	ui->label_image->setPixmap(image);
	ui->label->setText("Primary Flight Display of a Boeing 737-800");

}

Widget::~Widget()
{
	delete ui;
}

