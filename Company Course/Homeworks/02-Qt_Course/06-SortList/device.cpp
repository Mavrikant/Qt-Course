#include "device.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

Device::Device(QString productName, double productPriceTL, double productWeightKg, double productVolumeM3)
{
    #ifdef QT_DEBUG //If debud mode used for building code
            if(productName==""){
                qWarning() << "LOG: productName is empty";
            }
            if(productPriceTL<=0){
                qWarning() << "LOG: productPriceTL is lower or equal to zero";
            }
            if(productWeightKg<=0){
                qWarning() << "LOG: productWeightKg is lower or equal to zero";
            }
            if(productVolumeM3<=0){
                qWarning() << "LOG: productVolumeM3 is lower or equal to zero";
            }
    #else

    #endif



    m_productName=productName;
    m_productPriceTL=productPriceTL;
    m_productWeightKg=productWeightKg;
    m_productVolumeM3=productVolumeM3;
}

QString Device::getDeviceName() const
{
    return m_productName;
}

double Device::getPrice() const
{
    return m_productPriceTL;
}

double Device::getWeight() const
{
    return m_productWeightKg;
}

double Device::getVolume() const
{
    return m_productVolumeM3;
}

void Device::setName(QString ProductName)
{
    m_productName=ProductName;
}

void Device::setPrice(double productPrice)
{
    m_productPriceTL=productPrice;
}

void Device::setWeight(double productWeightKg)
{
    m_productWeightKg=productWeightKg;
}

void Device::setVolume(double productVolumeM3)
{
    m_productVolumeM3=productVolumeM3;
}

bool Device::operator<(Device &rightDevice) const
{
    return (this->m_productPriceTL<rightDevice.m_productPriceTL);
}

QDebug operator<<(QDebug qdebug, const QList<Device> &qlistDevice)
{
    QDebugStateSaver saver(qdebug);
    #define fieldSize 14

    qdebug.nospace().noquote() << QString("| %1|%2 |%3 |%4 |").arg("Device Name",-fieldSize).arg("Price TL",fieldSize).arg("Weight kg",fieldSize).arg("Volume m³",fieldSize)<<endl;
    for(Device device: qlistDevice){
        QString str = QString("| %1|%2 |%3 |%4 |").arg(device.getDeviceName(),-fieldSize).arg(device.getPrice(),fieldSize,'f',3).arg(device.getWeight(),fieldSize,'f',3).arg(device.getVolume(),fieldSize,'f',3);
        qdebug.nospace().noquote() << str<<endl;
    }
    return qdebug;
}
