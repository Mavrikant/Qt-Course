#ifndef MONITOR_H
#define MONITOR_H
#include <device.h>

class Monitor : public Device{

public:
    Monitor();
    void print();

private:
    double size;

};

#endif // MONITOR_H
