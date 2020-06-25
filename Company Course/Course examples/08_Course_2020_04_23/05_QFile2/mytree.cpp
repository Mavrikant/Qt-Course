#include "mytree.h"


MyTree::MyTree(QString propCsv, QString _delim)
{
  index = -1;
  girth = 0;
  height = 0;
  volume = 0;
  delimiter = _delim;
  treeIsEmpty = true;
  if(propCsv.isEmpty())
    return;
  QStringList columns = propCsv.split(",");
  if(columns.size()<4)
    return;
  index = columns[0].toInt();
  girth = columns[1].toDouble();
  height = columns[2].toDouble();
  volume = columns[3].toDouble();
  treeIsEmpty = false;
}

QString MyTree::toString(int width)
{
  QString str = QString("%2%1%3%1%4%1%5").arg(delimiter).arg(index,width,10,QChar(' '))
                                            .arg(girth,width,'f',1,QChar(' '))
                                            .arg(height,width,'f',1,QChar(' '))
                                            .arg(volume,width,'f',1,QChar(' '));

  return str;
}
