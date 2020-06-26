#include "filecopy.h"
#include <QDebug>
#include <QFile>
#include <QtDebug>

copyReturnCode filecopy(int argc, const char *argv[])
{
	if (argc != 3)
	{
		qWarning() << "Invalid argument count!";
		qWarning() << "You entered" << argc << "argument";
		qInfo() << "Usage: filecopy sourceFilePath destinationFilePath";
		return InvalidCount;
	}

	QString sourcePath = argv[1];
	QString destinationPath = argv[2];

	if (!QFile(sourcePath).exists())
	{
		qWarning() << "Source file" << sourcePath << "does not exist!";
		return SFNotExist;
	};

	if (QFile(destinationPath).exists())
	{
		qWarning() << "Destination file" << destinationPath << "already exist!";
		return DFAlreadyExist;
	}

	if (QFile::copy(sourcePath, destinationPath))
	{
		qInfo() << "!!Succes";

		QFile destFile(destinationPath);
		destFile.open(QFile::ReadOnly);
		qInfo() << destFile.readLine();
		destFile.close();

		return Succes;
	}
	else
	{
		qWarning("Copy operation failed!");
		return CopyFail;
	}

}
