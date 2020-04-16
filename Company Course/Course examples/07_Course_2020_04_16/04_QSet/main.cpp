#include <QSet>
#include <QDebug>
#include <QString>

int main(void)
{
  QSet<QString> set1, set2, set3, set4,set6,set7,set8;

  set1 << "mavi" << "yesil" << "mor" << "beyaz" << "siyah";

  set2 << "siyah" << "beyaz" << "kahve rengi";
  set2.insert("pembe");

  qDebug() << set1;
  qDebug() << set2;

  set3 = set4 = set6 = set7 = set1;
  set3.unite(set2);//birlesim

  set4.intersect(set2);//kesisim
  set6 += set2;//birlesim
  set7 = set1-set2;//fark kumesi
  set8 = set2-set1;//fark kumesi


  qDebug() << "Union:" << set3;
  qDebug() << "Union:" << set6;
  qDebug() <<  "Intersection:" << set4;
  qDebug() <<  "Subtraction(set1-set2):" << set7;
  qDebug() <<  "Subtraction(set2-set1):" << set8;

  QSet<int> set5 = {1,2,3,5};
  for(int i:set5){
    qDebug() << i;
  }
  return 0;
}

