#include <QTextStream>
#include <QFile>
#include "mytree.h"

int main(int argc, char *argv[])
{

    QTextStream out(stdout);

    if (argc != 2)  //argc: number of arguments
    {
        qWarning("Usage: filesize file");
        return 1;
    }

    QString filename = argv[1];
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Cannot open file for reading");
        return 1;
    }

    QTextStream in(&file);
    int width = QString("\"Volume(ft^3)\"").size();
    if (in.atEnd())
    {
        qWarning("No line in file!");
        return 1;
    }
    QStringList headers = in.readLine().split(",");
    QString str = QString("%2%1%3%1%4%1%5").arg(",").arg(headers[0], width, QChar(' ')).arg(headers[1], width, QChar(' ')).arg(headers[2], width, QChar(' ')).arg(headers[3], width, QChar(' '));
    out << str << Qt::endl;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        MyTree tree(line, ",");
        if (!tree.isEmpty())
        {
            out << tree.toString(width) << Qt::endl;
        }
    }

    file.close();
}
