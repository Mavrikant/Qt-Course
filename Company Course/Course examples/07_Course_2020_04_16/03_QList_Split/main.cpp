#include <QTextStream>
#include <QList>
#include <algorithm>
#include <QDebug>
int main(void) {

  QTextStream out(stdout);

  QString string = "coin, book, cup, pencil, clock, bookmark, market";
  QStringList items = string.split(",");
  items << " kutu" << " silgi";
  QStringListIterator it(items);

  while (it.hasNext()) {
      out << it.next().trimmed() << endl;
  }
  QStringList result;
  result = items.filter("mar");
  out << "items including mar:" << endl;
  qDebug() << result << endl;

  QString joinStr = items.join("-");
  out << "QStringList items joined by a new seperator:" << endl;
  out << joinStr.replace(" ","") << endl;


}
