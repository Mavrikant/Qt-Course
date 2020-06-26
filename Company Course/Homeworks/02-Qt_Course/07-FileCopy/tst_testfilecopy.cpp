#include <QtTest>

// add necessary includes here
#include "filecopy.h"

class TestFileCopy : public QObject
{
    Q_OBJECT

public:
    TestFileCopy();
    ~TestFileCopy();

private slots:
    void initTestCase(void);
    void test_case1_missingArgument(void);
    void test_case2_moreArgument(void);
    void test_case3_invalidSource(void);
    void test_case4_destinationFileExist(void);
    void test_case5_copyOperationFail(void);
    void test_case6_copyOperationSuccess(void);

};

TestFileCopy::TestFileCopy()
{
}

TestFileCopy::~TestFileCopy()
{

}

/**
 * @brief TestFileCopy::initTestCase
 * Test sirasinda kullanilacak ve directory de
 * olmamasi gereken dosyalar kaldiriliyor. Olmasi
 * gereken dosyalarin kontrolu yapiliyor.
 */
void TestFileCopy::initTestCase(void)
{
    QFile::remove("Makefilex");
    QFile::remove("Makefile2");

    /*NOTE: Dizine "Makefile" isimli bir dosya eklenmelidir. */
    QCOMPARE(QFile::exists("Makefile"), true);
}

/**
 * @brief TestFileCopy::test_case1_missingArgument
 * Eksik arguman ile program calistirildigi zaman
 * "1" hata koduyla donmelidir.
 */
void TestFileCopy::test_case1_missingArgument(void)
{
    int argc = 1;
    const char *argv[] = { "filecopy" };
    QCOMPARE(filecopy(argc, argv), 1);
}

/**
 * @brief TestFileCopy::test_case2_moreArgument
 * Fazla arguman ile program calistirildigi zaman
 * "1" hata koduyla donmelidir.
 */
void TestFileCopy::test_case2_moreArgument(void)
{
    int argc = 4;
    const char *argv[] = { "filecopy", "Makefile", "Makefile", "Makefile" };
    QCOMPARE(filecopy(argc, argv), 1);
}

/**
 * @brief TestFileCopy::test_case3_invalidSource
 * Olmayan bir dosya kopyalanmaya calisildigi zaman
 * "2" hata koduyla donmelidir.
 */
void TestFileCopy::test_case3_invalidSource(void)
{
    int argc = 3;
    const char *argv[] = { "filecopy", "Makefilex", "Makefilex" };
    QCOMPARE(filecopy(argc, argv), 2);
}

/**
 * @brief TestFileCopy::test_case4_destinationFileExist
 * Hedef olarak verilen dosya zaten directory icerisinde
 * varsa "3" hata koduyla donmelidir.
 */
void TestFileCopy::test_case4_destinationFileExist(void)
{
    int argc = 3;
    const char *argv[] = { "filecopy", "Makefile", "Makefile" };
    QCOMPARE(filecopy(argc, argv), 3);
}

/**
 * @brief TestFileCopy::test_case5_copyOperationFail
 * Kaynaktan hedefe yapilan kopyalama islemi gerceklesmediyse
 * "4" hata koduyla donmelidir.
 */
void TestFileCopy::test_case5_copyOperationFail(void)
{
    int argc = 3;
    const char *argv[] = { "filecopy", "Makefile", "Makefile/Makefile" };
    QCOMPARE(filecopy(argc, argv), 4);
}

/**
 * @brief TestFileCopy::test_case6_copyOperationSuccess
 * Kopyalama işlemi başarılı bir şekilde yapıldıysa "0"
 * hata koduyla donmelidir.
 */
void TestFileCopy::test_case6_copyOperationSuccess(void)
{
    int argc = 3;
    const char *argv[] = { "filecopy", "Makefile", "Makefile2" };
    QCOMPARE(filecopy(argc, argv), 0);

    /* NOTE: Dosya olustu mu kontrol ediliyor. */
    QCOMPARE(QFile::exists(argv[2]), true);
}

QTEST_APPLESS_MAIN(TestFileCopy)

#include "tst_testfilecopy.moc"
