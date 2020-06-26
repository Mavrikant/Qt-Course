#ifndef SHOP_H
#define SHOP_H

#include <map>
#include <queue>
#include <QWaitCondition>
#include <QMutex>
using namespace std;

#define DEFAULT_CHAIRS 3 // the default number of chairs for waiting = 3
#define DEFAULT_BARBERS 1 // the default number of barbers = 1

class Shop
{
public:
    Shop( int nBarbers, int nChairs );
    Shop( );
    int visitShop( int customerId ); // return a non-negative number only when a customer got a service

    void leaveShop( int customerId, int barberId );
    void helloCustomer( int barberId );

    void byeCustomer( int barberId );

    int nDropsOff = 0; // the number of customers dropped off

private:
    int nBarbers;
    int nChairs;

    enum customerState {WAIT, CHAIR, LEAVING};
    QWaitCondition barberCond;
    QWaitCondition customerCond;
    struct Barber
    {

        int id;

        int myCustomer = -1; //no customer by default
    };

    struct Customer
    {
        int id;

        customerState state = WAIT; //waiting state by default
        int myBarber = -1; //no barber by default
    };


    struct Barber *barbers; //array of barber objects
    map<int, struct Customer> customers; //container for customer objects


    queue<int> waitingCustomers;
    queue<int> sleepingBarbers;

    QMutex mutex1;

    Barber *getBarber(int barberId);
};

#endif // SHOP_H
