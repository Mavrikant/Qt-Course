/*
 * Bu program kendisine parametre olarak gecilen dizinde bulunan dosyalari listeler.
 * Siralama kriteri boyuta gore kucukten buyuge dogrudur.
 */
#include <QTextStream>
#include <QFileInfo>
#include <QDir>

int main(int argc, char *argv[])
{

    QTextStream out(stdout);

    if (argc != 2)
    {
        qWarning("Usage: list_dir directory");
        return 1;
    }

    QString directory = argv[1];

    QDir dir(directory);

    if (!dir.exists())
    {
        qWarning("The directory does not exist");
        return 1;
    }

    dir.setFilter(QDir::Files | QDir::AllDirs);
    dir.setSorting(QDir::Size | QDir::Reversed);
//  QStringList filters;
//  filters << "*.cpp" << "*.cxx" << "*.cc";
//  dir.setNameFilters(filters);

    QFileInfoList list = dir.entryInfoList();

    int max_size = 0;

    foreach (QFileInfo finfo, list)
    {
        QString name = finfo.fileName();
        int size = name.size();

        if (size > max_size)
        {
            max_size = size;
        }
    }

    int len = max_size + 2;

    out << QString("Filename").leftJustified(len).append("Bytes") << Qt::endl;

    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));
        out << str <<  Qt::endl;
    }

    return 0;
}
