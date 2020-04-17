#ifndef GPRMCDATETIME_H
#define GPRMCDATETIME_H
#include <QString>
#include <QStringList>
#include <QDateTime>

//| No |  Value   |        Explanation           |
//|:--:|---------:|:-----------------------------|
//| 1  | 220516   |  Time Stamp (hhmmss UTC)     |
//| 2  | A        |  validity - A-ok, V-invalid  |
//| 3  | 5133.82  |  current Latitude            |
//| 4  | N        |  North/South                 |
//| 5  | 00042.24 |  current Longitude           |
//| 6  | W        |  East/West                   |
//| 7  | 173.8    |  Speed in knots              |
//| 8  | 231.8    |  True course                 |
//| 9  | 130694   |  Date Stamp(ddMMyy)          |
//| 10 | 004.2    |  Variation                   |
//| 11 | W        |  East/West                   |
//| 12 | *70      |  checksum                    |


class GPRMCDateTime
{
public:
    GPRMCDateTime (const char *gprmcMessage);
    QString toString(int frmt=0);
    long long operator-(GPRMCDateTime gprmc2);

private:
    QStringList m_container;
    QDateTime m_datetime;




};
#endif // GPRMCDATETIME_H
