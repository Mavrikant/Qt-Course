#include <iostream>
#include "pedestrian.h"
#include "car.h"

int main()
{

//    MovingObject* pObj1= new Car();
//    MovingObject* pObj2= new Pedestrian();
//    pObj1->go();
//    pObj2->stop();


    bool trafficSign[2] = {false,true};
    MovingObject *moArray[2] = {nullptr};
    moArray[0] = new Car();
    moArray[1] = new Pedestrian();
    for(int i=0;i<2;i++)
        if(trafficSign[i])
            moArray[i]->go();
        else
            moArray[i]->stop();


    return 0;
}
