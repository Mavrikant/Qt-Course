#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

/**
 * @brief Widget::on_writeButton_clicked
 * Save file to disk
 */
void Widget::on_writeButton_clicked()
{
	QString filename = QFileDialog::getSaveFileName(this, "Save As");
	if (filename.isEmpty())
	{
		return;
	}
	QFile file(filename);

	//Open the file
	if (!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
	{
		return;
	}

	QTextStream out(&file);
	out << ui->textEdit->toPlainText() << "\n\r";
	file.close();
	ui->textEdit->clear();
}
/**
 * @brief Widget::on_readButton_clicked
 *
 */
void Widget::on_readButton_clicked()
{
	QString fileContent;
	QString filename = QFileDialog::getOpenFileName(this, "Open File");

	if (filename.isEmpty())
	{
		return;
	}

	QFile file(filename);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		return;
	}

	QTextStream in(&file);
	QString line = in.readLine();

	while (!line.isNull())
	{
		fileContent.append(line);
		line = in.readLine();
	}

	file.close();
	ui->textEdit->clear();
	ui->textEdit->setPlainText(fileContent);


}

void Widget::on_selectFileButton_clicked()
{

	QString filename = QFileDialog::getOpenFileName(this, "Choose File");

	if (filename.isEmpty())
	{
		return;
	}

	ui->sourceLineEdit->setText(filename);
	ui->destinationLineEdit->setText(filename);


}

void Widget::on_copyButton_clicked()
{
	QString source = ui->sourceLineEdit->text();
	QString destination =  ui->destinationLineEdit->text();

	if (source.isEmpty() || destination.isEmpty())
	{
		return;
	}

	QFile file(source);
	if (file.copy(destination))
	{
		QMessageBox::information(this, "Succes", "Copy Successful");
	}
	else
	{
		QMessageBox::warning(this, "Failure", "Can't copy the file");
	}

}
