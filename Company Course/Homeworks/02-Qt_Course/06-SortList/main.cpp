#include <QCoreApplication>
#include <QTextStream>
#include <QList>
#include "device.h"
#include <QObject>
int main()
{
    QTextStream out(stdout);
    QList<Device> shoppingCart;

    shoppingCart.append(Device("HDSSD2561", 180.000, 2.220, 0.020));
    shoppingCart.append(Device("HDSSD1281", 90.000, 1.350, 0.050));
    shoppingCart.append(Device("HDSSD1282", 90.000, 3.400, 0.013));
    shoppingCart.append(Device("HDSSD2562", 180.000, 6.652, 0.052));
    shoppingCart.append(Device("MNXWG191", 97.500, 7.545, 0.045));
    shoppingCart.append(Device("MNXWG192", 97.500, 10.380, 1.080));

    qDebug()<<shoppingCart;

    std::sort(shoppingCart.begin(),shoppingCart.end());
    qDebug()<<shoppingCart;

    std::sort(shoppingCart.begin(),shoppingCart.end(), Device::compareByPrice);
    qDebug()<<shoppingCart;

    std::sort(shoppingCart.begin(),shoppingCart.end(), Device::compareByWeight);
    qDebug()<<shoppingCart;

    std::sort(shoppingCart.begin(),shoppingCart.end(), Device::compareByVolume);
    qDebug()<<shoppingCart;

}
