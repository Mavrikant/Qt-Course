#include <iostream>
#include "human.h"
#include "customer.h"
#include "passenger.h"
#include "son.h"
#include "student.h"
#include "behavior.h"

/* NOTE: Kodlar gayet guzel olmus. Eline saglik. Sozel ifadeleride yazabilsen iyi olurdu. */
/* Bir seyi ogrenmenin en iyi yollarindan bir kendi cumlelerinle ifade etmektir.          */
using namespace std;

int main()
{

    Behavior *Pointer[] ={new Customer, new Passenger, new Student, new Son};
    for(int i=0;i<4;i++){
        Pointer[i]->Behave();
    }

    Human Ekrem;

    std::cout<<"-----------------------"<<std::endl;
    Customer * customer = &Ekrem;
    customer->Behave(); //I'm a human.
    customer->Customer::Behave(); //I'm a customer

    std::cout<<"-------"<<std::endl;
    Passenger * passanger = &Ekrem;
    passanger->Behave();
    passanger->Passenger::Behave();

    std::cout<<"-------"<<std::endl;
    Student * student = &Ekrem;
    student->Behave();
    student->Student::Behave();

    std::cout<<"-------"<<std::endl;
    Son * son = &Ekrem;
    son->Behave();
    son->Son::Behave();
    return 0;
}
