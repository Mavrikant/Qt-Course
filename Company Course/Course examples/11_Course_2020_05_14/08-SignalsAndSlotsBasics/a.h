#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
	Q_OBJECT
private:
	int m_state;

public:
	explicit A(QObject *parent = nullptr);

	int state() const;
	void setState(int state);

signals:
	void stateChanged(int newState);

public slots:

};

#endif // A_H
