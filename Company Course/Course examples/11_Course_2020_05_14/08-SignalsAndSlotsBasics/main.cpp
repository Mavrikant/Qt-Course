#include <QCoreApplication>
#include <a.h>
#include <b.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	A *sensor = new A();
	B *sensorMonitor = new B();

	//Sensorun durumu degistiginde sensoru izleyen nesnenin haberi olabilmesi icin sinyal-slot iliskisi kuruluyor
	QObject::connect(sensor, &A::stateChanged, sensorMonitor, &B::onSensorStateChanged);

	sensor->setState(1);
	sensor->setState(2);

	return a.exec();
}
