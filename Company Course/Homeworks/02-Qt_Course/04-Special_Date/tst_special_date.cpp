#include <QtTest>

// add necessary includes here
#include "specialdate.h"

class TestSpecialDate : public QObject
{
    Q_OBJECT

public:
    TestSpecialDate();
    ~TestSpecialDate();

private slots:
    void test_case1_constructors();
    void test_case2_constructors();
    void test_case3_isSpecialDate();
    void test_case4_operator();
    void test_case5_getSpecialDateCount();
};

TestSpecialDate::TestSpecialDate()
{

}

TestSpecialDate::~TestSpecialDate()
{

}

/* NOTE: Asagidaki constructor a arguman olarak verilen degerler turetilmis sinif */
/* icerisinde tutulan taban sinif turunden degiskene atanmis olmalidir.           */
// SpecialDate(int year = 0, int month = 0, int day = 0);
void TestSpecialDate::test_case1_constructors()
{
    QTextStream out(stderr);
    QDate date = SpecialDate(2012, 12, 30);
    QCOMPARE(date.year(), 2012);
    QCOMPARE(date.month(), 12);
    QCOMPARE(date.day(), 30);
}

/* NOTE: Asagidaki constructor a arguman olarak verilen degerler turetilmis sinif */
/* icerisinde tutulan taban sinif turunden degiskene atanmis olmalidir.           */
// SpecialDate(const QDate &date);
void TestSpecialDate::test_case2_constructors()
{
    QDate temp(2012, 12, 30);
    QDate date = SpecialDate(temp);
    QCOMPARE(date.year(), 2012);
    QCOMPARE(date.month(), 12);
    QCOMPARE(date.day(), 30);
}

/* NOTE: Gunun ozel bir gun olup olmadigini belirleyen fonksiyonun */
/* dogru calisip calismadigini kontrol eder.                       */
void TestSpecialDate::test_case3_isSpecialDate()
{
    for (int i = 1; i <= 12; ++i) {
        SpecialDate date(i, i, i);
        QCOMPARE(date.isSpecialDate(), true);

        date = SpecialDate(100 + i, i, i);
        QCOMPARE(date.isSpecialDate(), true);

        date = SpecialDate(1000 + i, i, i);
        QCOMPARE(date.isSpecialDate(), true);
    }

    for (int i = 1; i <= 12; ++i) {
        SpecialDate date(12 + i, i, i);
        QCOMPARE(date.isSpecialDate(), false);

        date = SpecialDate(112 + i, i, i);
        QCOMPARE(date.isSpecialDate(), false);

        date = SpecialDate(1012 + i, i, i);
        QCOMPARE(date.isSpecialDate(), false);
    }
}

/* NOTE: QDebug icin yazilan operator<< un dogru calisip calismadigini kontrol eder. */
void TestSpecialDate::test_case4_operator()
{
    QString *pstr = new QString();
    QDebug debug = QDebug(pstr);
    debug.noquote().nospace() << SpecialDate(2012, 12, 30);
    QCOMPARE(*pstr, "30/12/2012");
}

/* NOTE: Iki tarih arasindaki toplam ozel gun sayisini bulan fonksiyonun */
/* dogru calisip calismadigini kontrol eder.                             */
void TestSpecialDate::test_case5_getSpecialDateCount()
{
    SpecialDate date(3000, 1, 1);
    QCOMPARE(date.getSpecialDateCount(SpecialDate(1, 1, 1)), 360);
}

QTEST_APPLESS_MAIN(TestSpecialDate)
#include "tst_special_date.moc"
