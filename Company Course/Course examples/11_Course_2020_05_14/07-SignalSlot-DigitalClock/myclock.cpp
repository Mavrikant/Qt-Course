#include "myclock.h"
#include <QTimer>
#include <QTime>

void MyClock::showTime()
{
	QTime time = QTime::currentTime();

	if ((time.second() % 2))
	{
		display(time.toString("mm ss"));
	}
	else
	{
		display(time.toString("mm:ss"));
	}



}

MyClock::MyClock(QWidget *parent)
{
	setSegmentStyle(Filled);
	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &MyClock::showTime);

	// The average reaction time for humans is 0.25 seconds to a visual stimulus,
	// 0.17 for an audio stimulus, and 0.15 seconds for a touch stimulus.
	timer->start(250);

	showTime();

	setWindowTitle(tr("Digital Clock"));
	resize(350, 100);

}

MyClock::~MyClock()
{

}
