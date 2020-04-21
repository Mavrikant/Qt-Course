#ifndef DEVICE_H
#define DEVICE_H

/*
                  _(_)_                          wWWWw   _
      @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_
     @@()@@ wWWWw  (_)\    (___)   _(_)_  @@()@@   Y  (_)@(_)
      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   (_)\
       /      Y       \|    \|/    /(_)    \|      |/      |
    \ |     \ |/       | / \ | /  \|/       |/    \|      \|/
    \\|//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/

#include <QString>
#include <QDebug>

/**
 * @brief The Device class is used for storing device properties and have related sorting methods
 * @author M. Serdar Karaman
 */

class Device
{
public:
    /**
     * @brief Device
     * @param productName
     * @param productPriceTL Product price in Turkish Lira
     * @param productWeightKg Product weight in kilogram
     * @param productVolumeM3 Product volume in m³
     */
    Device(QString productName, double productPriceTL, double productWeightKg, double productVolumeM3);

    QString getDeviceName() const;
    double getPrice() const;
    double getWeight() const;
    double getVolume() const;

    void setName(QString ProductName);
    void setPrice(double productPriceTL);
    void setWeight(double productWeightKg);
    void setVolume(double productVolumeM3);

    bool operator< (Device &rightDevice) const;

    bool static compareByDeviceName( const Device& leftDevice, const Device& rightDevice ) {
         return leftDevice.m_productName < rightDevice.m_productName;
    }
    bool static compareByWeight( const Device& leftDevice, const Device& rightDevice ) {
         return leftDevice.m_productWeightKg < rightDevice.m_productWeightKg;
    }
    bool static compareByVolume( const Device& leftDevice, const Device& rightDevice ) {
         return leftDevice.m_productVolumeM3 < rightDevice.m_productVolumeM3;
    }
    bool static compareByPrice( const Device& leftDevice, const Device& rightDevice ) {
         return leftDevice.m_productPriceTL < rightDevice.m_productPriceTL;
    }
    /**
     * @brief operator <<
     * @param qdebug
     * @param qlistDevice
     * @return
     */
    friend QDebug operator<<( QDebug qdebug, const QList<Device> & qlistDevice);

private:
    QString m_productName;
    double  m_productPriceTL;
    double  m_productWeightKg;
    double  m_productVolumeM3;

};

#endif // DEVICE_H
