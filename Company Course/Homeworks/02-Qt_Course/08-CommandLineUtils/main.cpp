#include <QCoreApplication>
#include <QtDebug>
#include <QDir>
#include "iostream"
#include <QString>

static QTextStream in(stdin), out(stdout);

void showDirectory(QDir &directory)
{
    if (directory.exists())
    {
        QFileInfoList fileInfo = directory.entryInfoList();
        for (auto info : fileInfo)
        {
            out << (info.isDir() ?  QString("DIR") : QString("FILE")).leftJustified(8, ' ')
                << QString("%1").arg(fileInfo.size()).leftJustified(5, ' ')
                << (info.fileName().size() < 25 ? info.fileName().leftJustified(30,
                                                                                ' ') : (info.fileName().left(25) + "...").leftJustified(30, ' ')) << Qt::endl;
        }
    }
    else
    {
        qDebug() << "Wrong directory input...\n";
    }
}

void moveDirectory(const QString &pwd, QString &file, QString &target)
{
    QString temp1{pwd + "/" + file}, temp2 {pwd + "/" + target};

    if (QFile::rename(temp1, temp2))
    {
        qDebug() << "Moving has been succesful!" << Qt::endl;
    }
    else
    {
        qDebug() << "Moving has failed!" << Qt::endl;
    }
}

void copyDirectory(const QString &pwd, QString &file, QString &target)
{


    QString temp1{pwd + "/" + file}, temp2 {pwd + "/" + target};

    if (QFile::copy(temp1, temp2))
    {
        qDebug() << "Copying has been succesful!" << Qt::endl;
    }
    else
    {
        qDebug() << "Copying has failed!" << Qt::endl;
    }
}

void changeDirectory(QDir &directory, const QString &targetDirectory)
{
    if (targetDirectory == "..")
    {
        directory.cdUp();
        return;
    }
    if (!directory.cd(targetDirectory))
    {
        qDebug() << "Target directory does not exist!\n";
        return;
    }
}

void deleteFile(QDir &directory, const QString &target)
{
    if (!directory.remove(target))
    {
        qDebug() << "Removing has failed!" << Qt::endl;
    }
    else
    {
        qDebug() << "Removing has been succesful." << Qt::endl;
    }
}

int main()
{

    QString inputCommand;
    std::cout << "+-++-++-++-++-++-++-+\n"
              << "|T||u||r||k||i||s||h|\n"
              << "+-++-++-++-++-++-++-+\n"
              << "+-++-++-++-++-++-++-+\n"
              << "|T||e||c||h||n||i||c|\n"
              << "+-++-++-++-++-++-++-+\n";

    QDir dir(QDir::currentPath());
    QString input;


    while (true)
    {
        std::cout << std::endl << ">>";
        inputCommand = in.readLine();

        QStringList inputCommands = inputCommand.split(' ');

        if (inputCommands[0] == "ls" || inputCommands[0] == "dir")
        {
            showDirectory(dir);
        }
        else if (inputCommands[0] == "cd")
        {
            changeDirectory(dir, inputCommands[1]);

        }
        else if (inputCommands[0] == "cp" || inputCommands[0] == "copy")
        {
            copyDirectory(dir.path(), inputCommands[1], inputCommands[2]);

        }
        else if (inputCommands[0] == "mv" || inputCommands[0] == "move")
        {
            moveDirectory(dir.path(), inputCommands[1], inputCommands[2]);
        }
        else if (inputCommands[0] == "rm" || inputCommands[0] == "del")
        {
            deleteFile(dir, inputCommands[1]);

        }
        else
        {
            qWarning() << "Undefined command:" << inputCommands[0];
        }
    }
}
