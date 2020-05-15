#include "b.h"
#include <QTextStream>

B::B(QObject *parent) : QObject(parent)
{
  m_sensorState = 0;
}

void B::onSensorStateChanged(const int newState)
{
  QTextStream out(stdout);
  out << QString(tr("Sensor state changed!\nOld state: %1\nNew State: %2"))
                      .arg(m_sensorState).arg(newState) << endl;
  m_sensorState = newState;
}
