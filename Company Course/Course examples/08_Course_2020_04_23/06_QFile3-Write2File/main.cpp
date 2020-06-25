/*
 * QFile sinifi ve QTextStream ile dosyaya yazma islemleri.
 */
#include <QTextStream>
#include <QFile>

int main(void)
{
    QTextStream out(stdout);

    QString filename = "distros.txt";
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "Xubuntu" << Qt::endl;//Dosya text modunda acilmamissa satir atlamaz
        out << "Arch" << Qt::endl;
        out << "Debian" << Qt::endl;
        out << "Redhat" << Qt::endl;
        out << "Slackware" << Qt::endl;
    }
    else
    {
        qWarning("Could not open file");
    }

    file.close();
}

