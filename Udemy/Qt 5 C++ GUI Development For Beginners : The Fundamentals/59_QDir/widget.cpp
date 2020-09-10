#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QMessageBox>


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


void Widget::on_chooseDirButton_clicked()
{
	QString filename = QFileDialog::getExistingDirectory(this, "Choose Folder");
	if (filename.isEmpty())
	{
		return;
	}

	ui->lineEdit->setText(filename);
}

void Widget::on_createDirButton_clicked()
{

	QString dirPath = ui->lineEdit->text();
	if (dirPath.isEmpty())
	{
		return;
	}
	QDir dir(dirPath);
	if (!dir.exists())
	{
		if (dir.mkpath(dirPath))
		{
			QMessageBox::information(this, "Info", "Directory created!");
		}
		else
		{
			QMessageBox::warning(this, "Warning", "Directory creation failed!");
		}
	}
	else
	{
		QMessageBox::warning(this, "Warning", "Directory alredy exist!");

	}

}

void Widget::on_dirExistsButton_clicked()
{
	QString dirPath = ui->lineEdit->text();
	if (dirPath.isEmpty())
	{
		return;
	}

	QDir dir(dirPath);
	if (dir.exists())
	{
		QMessageBox::information(this, "Info", "Directory exist!");
	}
	else
	{
		QMessageBox::information(this, "Info", "Directory does NOT exist!");
	}

}

void Widget::on_dirOrFileButton_clicked()
{

	QFileInfo fileInfo(ui->listWidget->currentItem()->text().split("\t")[2]);
	if ( fileInfo.isDir())
	{
		QMessageBox::information(this, "Message", "This a Dir");
	}
	else if ( fileInfo.isFile())
	{
		QMessageBox::information(this, "Message", "This a File");
	}
	else
	{
		QMessageBox::information(this, "Message", "Something else");
	}


}

void Widget::on_folderContentButton_clicked()
{
	ui->listWidget->clear();


	QString dirPath = ui->lineEdit->text();
	if ( dirPath.isEmpty())
	{
		return;
	}

	QDir dir(dirPath);

	//Get the list of files and directories in the folder

	QList<QFileInfo> fileList = dir.entryInfoList();

	for ( int i = 0 ; i < fileList.size() ; i++)
	{
		QString prefix;
		if (fileList.at(i).isFile())
		{
			prefix = "FILE";
		}
		if (fileList.at(i).isDir())
		{
			prefix = "DIR";
		}

		QLocale locale = this->locale();
		ui->listWidget->addItem( QString( "%1\t%2\t%3").arg(prefix,
															-4).arg(locale.formattedDataSize(fileList.at(i).size()),
																	-10).arg(fileList.at(i).absoluteFilePath()));
	}
}
