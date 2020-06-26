#include <shop.h>
#include <QCoreApplication>
#include <QThread>
#include <threadparam.h>
#include <barberthread.h>
#include <customerthread.h>
#include <iostream>

// function prototype
void *barber( void * );    // the prototype of the barber thread function
void *customer( void * );  // the prototype of the customer thread function

int main( int argc, char *argv[] )
{
    QCoreApplication app(argc, argv);
    // validate the arguments
    if ( argc != 5 )
    {
        std::cerr << "usage: sleepingBarber nBaerbers nChairs nCustomers serviceTime" << std::endl;
        return -1;
    }
    //2 5 15 200
    int nBarbers = atoi( argv[1] );      // # barbers working in the barbershop
    int nChairs = atoi( argv[2] );       // # chairs available for customers to wait on
    int nCustomers = atoi( argv[3] );    // # customers who need a haircut service
    int serviceTime = atoi( argv[4] );   // each barber's service time ( in u seconds)

    BarberThread *barber_thread[nBarbers];
    CustomerThread *customer_threads[nCustomers];
    Shop shop( nBarbers, nChairs );      // instantiate a barbershop

    for ( int i = 0; i < nBarbers; i++ )     // instantiate barbers
    {
        ThreadParam *param = new ThreadParam( &shop, i, serviceTime );
        barber_thread[i] = new BarberThread(*param);
        barber_thread[i]->start();
    }
    for ( int i = 0; i < nCustomers; i++ )   // instantiate customers
    {
        QThread::usleep( rand( ) % 1000 );              // with random interval
        ThreadParam *param = new ThreadParam( &shop, i + 1, 0 );
        customer_threads[i] = new CustomerThread(*param);
        customer_threads[i]->start();
    }

    for ( int i = 0; i < nCustomers; i++ )   // wait until all the customers are served
        customer_threads[i]->wait();

    for ( int i = 0; i < nBarbers; i++ )     // terminate all the barbers
        barber_thread[i]->exit();
    std::cout << "# customers who didn't receive a service = " << shop.nDropsOff
              << std::endl;

    return 0;
}


