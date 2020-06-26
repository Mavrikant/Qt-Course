#include "barberthread.h"

BarberThread::BarberThread(ThreadParam param, QObject *parent) :
    QThread(parent), m_threadParam(param)
{

}

void BarberThread::run()
{
    // extract parameters

    Shop &shop = *(m_threadParam.shop);

    // keep working until being terminated by the main
    while ( true )
    {
        shop.helloCustomer( m_threadParam.id );  // pick up a new customer
        usleep( m_threadParam.serviceTime );     // spend a service time
        shop.byeCustomer( m_threadParam.id );    // release the customer
    }

}
