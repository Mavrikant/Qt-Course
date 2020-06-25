#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);

    if (argc != 2)
    {
        out << "Usage: file_paths file" << Qt::endl;
        return 1;
    }

    QString filename = argv[1];

    QFileInfo fileinfo(filename);

    QString absPath = fileinfo.absoluteFilePath();
    QString baseName = fileinfo.baseName();
    QString compBaseName = fileinfo.completeBaseName();
    QString fileName = fileinfo.fileName();
    QString suffix = fileinfo.suffix();
    QString compSuffix = fileinfo.completeSuffix();

    out << "Absolute file path: " << absPath << Qt::endl;
    out << "Base name: " << baseName << Qt::endl;
    out << "Complete base name: " << compBaseName << Qt::endl;
    out << "File name: " << fileName << Qt::endl;
    out << "Suffix: " << suffix << Qt::endl;
    out << "Whole suffix: " << compSuffix << Qt::endl;
}
