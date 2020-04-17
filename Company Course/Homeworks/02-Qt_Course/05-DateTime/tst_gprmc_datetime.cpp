#include <QtTest>

// add necessary includes here
#include "gprmcdatetime.h"

class GPRMC_DateTime : public QObject
{
    Q_OBJECT

public:
    GPRMC_DateTime();
    ~GPRMC_DateTime();

private slots:
    void test_case1_toString_0();
    void test_case2_toString_1();
    void test_case3_operator();

};

GPRMC_DateTime::GPRMC_DateTime()
{

}

GPRMC_DateTime::~GPRMC_DateTime()
{

}

/* NOTE: toString fonksiyonunun 0 argumani aldigi durumda ISO formatina */
/* uygun bir cikti verilip verilmedigini kontrol eden test case idir.   */
void GPRMC_DateTime::test_case1_toString_0()
{
    char gprmc[] = "$GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70";
    GPRMCDateTime a(gprmc);

   QString str;
    str = a.toString(0);
    qDebug() << str;
    QCOMPARE(str, QString("1994-06-13T22:05:16"));
}

/* NOTE: toString fonksiyonunun 1 argumani aldigi durumda sistem lokali formatina */
/* uygun bir cikti verilip verilmedigini kontrol eden test case idir.             */
void GPRMC_DateTime::test_case2_toString_1()
{
  char gprmc[] = "$GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70";
  GPRMCDateTime a(gprmc);
  QDateTime dt = QDateTime::fromString("13/06/94-22:05:16", "dd/MM/yy-hh:mm:ss");

  QString str = a.toString(1);
  qDebug() << str;
  QCOMPARE(str, dt.toString(Qt::SystemLocaleLongDate));
}

/* NOTE: Iki tarih arasinda gecen surenin kontrolu yapiliyor. */
void GPRMC_DateTime::test_case3_operator()
{
    QString str = QString("eg3. $GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70");
    GPRMCDateTime gdt = GPRMCDateTime(str.toStdString().c_str());
    QString str1 = QString("eg3. $GPRMC,230414,A,5133.82,N,00042.24,W,173.8,231.8,120899,004.2,W*70");
    GPRMCDateTime gdt1 = GPRMCDateTime(str1.toStdString().c_str());

    qDebug() << "Seconds between: " << gdt - gdt1 << endl;
    QCOMPARE(gdt - gdt1, 162953938);

    qDebug() << "Seconds between: " << gdt1 - gdt << endl;
    QCOMPARE(gdt1 - gdt, -162953938);
}

QTEST_APPLESS_MAIN(GPRMC_DateTime)

#include "tst_gprmc_datetime.moc"
