#include <QTextStream>
#include <QFile>

int main(int argc, char *argv[]) {

  QTextStream out(stdout);

  if (argc != 3) {

      qWarning("Usage: copyfile source destination");
      return 1;
  }

  QString source = argv[1];

  if (!QFile(source).exists()) {
      qWarning("The source file does not exist");
      return 1;
  }

  QString destin(argv[2]);

  QFile::copy(source, destin);
}
