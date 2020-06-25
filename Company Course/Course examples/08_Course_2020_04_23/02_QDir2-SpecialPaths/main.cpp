/*
 * Bu program calisma dizinini, ev dizinini, temp dizinini, ve ana dizini konsola basar.
 *
 */
#include <QTextStream>
#include <QDir>

int main(void)
{

    QTextStream out(stdout);

    out << "Current path:" << QDir::currentPath() <<  Qt::endl;
    out << "Home path:" << QDir::homePath() <<  Qt::endl;
    out << "Temporary path:" << QDir::tempPath() <<  Qt::endl;
    out << "Rooth path:" << QDir::rootPath() <<  Qt::endl;
}
