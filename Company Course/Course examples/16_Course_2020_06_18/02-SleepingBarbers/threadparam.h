#ifndef THREADPARAM_H
#define THREADPARAM_H
// a set of parameters to be passed to each thread
#include "shop.h"
class ThreadParam
{
public:
    ThreadParam( Shop *shop, int id, int serviceTime ) :
        shop( shop ), id( id ), serviceTime( serviceTime ) { };
    Shop *shop;               // a pointer to the Shop object
    int id;                   // a thread identifier
    int serviceTime;          // service time (in usec) to a barber, whereas 0 to a customer
};
#endif // THREADPARAM_H
