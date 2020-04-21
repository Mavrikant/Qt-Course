#include <QtTest>

// add necessary includes here
#include "device.h"

class TestListSorting : public QObject
{
    Q_OBJECT

public:
    TestListSorting();
    ~TestListSorting();
private:
    QList<Device> m_shoppingCart = QList<Device>();

private slots:
    void test_case1_sortingByPrice();
    void test_case2_sortingByDeviceName();
    void test_case3_sortingByWeight();
    void test_case4_sortingByVolume();
};

TestListSorting::TestListSorting()
{    
    m_shoppingCart.append(Device("HDSSD2561", 180.000,  2.220, 0.020));
    m_shoppingCart.append(Device("HDSSD1281",  90.000,  1.350, 0.050));
    m_shoppingCart.append(Device("HDSSD1282",  90.000,  3.400, 0.013));
    m_shoppingCart.append(Device("HDSSD2562", 180.000,  6.652, 0.052));
    m_shoppingCart.append(Device("MNXWG191",   97.500,  7.545, 0.045));
    m_shoppingCart.append(Device("MNXWG192",   97.500, 10.380, 1.080));

    qDebug() << "All devices in the shopping cart:" << endl;
    qDebug() << m_shoppingCart;
}

TestListSorting::~TestListSorting()
{
    m_shoppingCart.clear();
}

/**
 * @brief TestListSorting::test_case1_sortingByPrice
 * std::sort a siralama icin ekstra arguman olarak
 * fonksiyon verilmezse varsayilan olarak operator<
 * fonksiyonunu cagirir.
 */
void TestListSorting::test_case1_sortingByPrice()
{
    std::sort(m_shoppingCart.begin(), m_shoppingCart.end());
    qDebug() << endl << "Sorting by price:" << endl << m_shoppingCart;

    for (int i = 0; i < m_shoppingCart.size() - 1; ++i) {
        if (m_shoppingCart[i].getPrice() > m_shoppingCart[i + 1].getPrice()) {
            qDebug() << "Sorting by price failed:"
                     << m_shoppingCart[i].getDeviceName() << "device price (" << m_shoppingCart[i].getPrice() << " TL )"
                     << "is greater than the"
                     << m_shoppingCart[i + 1].getDeviceName() << "device price (" << m_shoppingCart[i + 1].getPrice() << " TL )!";
            QCOMPARE(m_shoppingCart[i].getPrice() > m_shoppingCart[i + 1].getPrice(), false);
        }
    }
}

/**
 * @brief TestListSorting::test_case2_sortingByDeviceName
 * std::sort a siralama icin ekstra arguman olarak
 * verilen ve cihaz ismine gore siralama yapan fonksiyonun
 * calismasini kontrol eder.
 */
void TestListSorting::test_case2_sortingByDeviceName()
{
    std::sort(m_shoppingCart.begin(), m_shoppingCart.end(), Device::compareByDeviceName);
    qDebug() << endl << "Sorting by device name:" << endl << m_shoppingCart;

    for (int i = 0; i < m_shoppingCart.size() - 1; ++i) {
        if (m_shoppingCart[i].getDeviceName() > m_shoppingCart[i + 1].getDeviceName()) {
            qDebug() << "Sorting by device name failed:"
                     << m_shoppingCart[i].getDeviceName() << "device name is greater than the"
                     << m_shoppingCart[i + 1].getDeviceName() << "device name!";
            QCOMPARE(m_shoppingCart[i].getDeviceName() > m_shoppingCart[i + 1].getDeviceName(), false);
        }
    }
}

/**
 * @brief TestListSorting::test_case3_sortingByWeight
 * std::sort a siralama icin ekstra arguman olarak
 * verilen ve agirliga gore siralama yapan fonksiyonun
 * calismasini kontrol eder.
 */
void TestListSorting::test_case3_sortingByWeight()
{
    std::sort(m_shoppingCart.begin(), m_shoppingCart.end(), Device::compareByWeight);
    qDebug() << endl <<"Sorting by weight:" << endl << m_shoppingCart;

    for (int i = 0; i < m_shoppingCart.size() - 1; ++i) {
        if (m_shoppingCart[i].getWeight() > m_shoppingCart[i + 1].getWeight()) {
            qDebug() << "Sorting by weight failed:"
                     << m_shoppingCart[i].getDeviceName() << "device weight (" << m_shoppingCart[i].getWeight() << " kg )"
                     << "is greater than the"
                     << m_shoppingCart[i + 1].getDeviceName() << "device weight (" << m_shoppingCart[i + 1].getWeight() << " kg )!";
            QCOMPARE(m_shoppingCart[i].getWeight() > m_shoppingCart[i + 1].getWeight(), false);
        }
    }
}

/**
 * @brief TestListSorting::test_case4_sortingByVolume
 * std::sort a siralama icin ekstra arguman olarak
 * verilen ve hacme gore siralama yapan fonksiyonun
 * calismasini kontrol eder.
 */
void TestListSorting::test_case4_sortingByVolume()
{
    std::sort(m_shoppingCart.begin(), m_shoppingCart.end(), Device::compareByVolume);
    qDebug() << endl << "Sorting by volume:" << endl << m_shoppingCart;

    for (int i = 0; i < m_shoppingCart.size() - 1; ++i) {
        if (m_shoppingCart[i].getVolume() > m_shoppingCart[i + 1].getVolume()) {
            qDebug() << "Sorting by volume failed:"
                     << m_shoppingCart[i].getDeviceName() << "device volume (" << m_shoppingCart[i].getVolume() << " m3 )"
                     << "is greater than the"
                     << m_shoppingCart[i + 1].getDeviceName() << "device volume (" << m_shoppingCart[i + 1].getVolume() << " m3 )!";
            QCOMPARE(m_shoppingCart[i].getVolume() > m_shoppingCart[i + 1].getVolume(), false);
        }
    }
}

QTEST_APPLESS_MAIN(TestListSorting)

#include "tst_listsorting.moc"
