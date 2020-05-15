#ifndef B_H
#define B_H

#include <QObject>

class B : public QObject
{
	Q_OBJECT
private:
	int m_sensorState;

public:
	explicit B(QObject *parent = nullptr);

signals:


public slots:
	void onSensorStateChanged(const int newState);
};

#endif // B_H
