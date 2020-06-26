#include "customerthread.h"
#include <shop.h>

CustomerThread::CustomerThread(ThreadParam param, QObject *parent) :
    QThread(parent), m_threadParam(param)
{

}

void CustomerThread::run()
{
    int barber = -1;
    if ( ( barber = m_threadParam.shop->visitShop( m_threadParam.id ) ) != -1 ) // am I assigned to barber i or no barber (-1)?
        m_threadParam.shop->leaveShop( m_threadParam.id, barber );
}
