#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{

    QTextStream out(stdout);

    if (argc != 2)  //argc: number of arguments
    {

        qWarning("Usage: fileinfo file");
        return 1;
    }

    QString filename = argv[1];

    if (!QFile(filename).exists())
    {
        qWarning("%s", QString("The file %1 does not exist").arg(argv[1]).toStdString().c_str());
        return 1;
    }

    QFileInfo fileInfo(filename);

    QString strPerm = "";

    if (fileInfo.permission(QFile::WriteUser | QFile::ReadGroup))
        strPerm += "I can change the file; my group can read the file.";
    if (fileInfo.permission(QFile::WriteGroup ))
        strPerm += "The group or others can change the file.";
    int w = QString("Absolute File Path").size();//yazilarin hizalanmasi icin gerekli

    out << QString("Absolute File Path").leftJustified(w, ' ') << ": " << fileInfo.absoluteFilePath() << Qt::endl;
    out << QString("File Path").leftJustified(w, ' ') << ": " << fileInfo.filePath() << Qt::endl;
    out << QString("File Name").leftJustified(w, ' ') << ": " << fileInfo.fileName() << Qt::endl;
    out << QString("Base Name").leftJustified(w, ' ') << ": " << fileInfo.baseName() << Qt::endl;
    out << QString("Complete Base Name").leftJustified(w, ' ') << ": " << fileInfo.completeBaseName() << Qt::endl;
    out << QString("Full File Ext").leftJustified(w, ' ') << ": " << fileInfo.completeSuffix() << Qt::endl;
    out << QString("File Ext").leftJustified(w, ' ') << ": " << fileInfo.suffix() << Qt::endl;
    out << QString("Last Modified").leftJustified(w, ' ') << ": " << fileInfo.lastModified().toString() << Qt::endl;
    out << QString("Last Read").leftJustified(w, ' ') << ": " << fileInfo.lastRead().toString() << Qt::endl;
    out << QString("Created").leftJustified(w, ' ') << ": " << fileInfo.birthTime().toString() << Qt::endl;
    out << QString("Owner").leftJustified(w, ' ') << ": " << fileInfo.owner() << Qt::endl;
    out << QString("Permissions").leftJustified(w, ' ') << ": " << strPerm << Qt::endl;
    out << QString("File Size").leftJustified(w, ' ') << ": " << fileInfo.size() << Qt::endl;

    return 0;
}
