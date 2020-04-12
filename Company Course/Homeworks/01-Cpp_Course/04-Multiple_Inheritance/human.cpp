#include "human.h"
#include <iostream>

/* NOTE: "Variable shadowing (name hiding)" olusmadikca sinifin uye degiskenleri (member variable)     */
/* icin ekstradan this anahtar sozcugunu kullanmaya gerek yoktur. Zaten sinifin uye degiskeni oldugunu */
/* belirtmek icin "m_" on eki kullanilmistir.                                                          */

Human::Human(property walking,property running,property speaking,property eating,property sleeping,property reading){
    this->m_walking=walking;
    this->m_running=running;
    this->m_speaking=speaking;
    this->m_eating=eating;
    this->m_sleeping=sleeping;
    this->m_reading=reading;
    /* NOTE: Yukaridaki setleme islemleride asagidaki gibi sinifin uye fonksiyonuna cagri ile yapilabilir. */
    /* Bu durum setleme isleminin yaninda ekstra islemler yapildigi durumda bu islemlerin kod tekrari ile  */
    /* burada yine yapilmasini engelleyecektir.                                                            */
    /* setSpeaking(reading);                                                                               */
}

void Human::setWalking(property walking){
    this->m_walking=walking;
}

void Human::setRunnig(property running){
    this->m_running=running;
}
void Human::setSpeaking(property speaking){
    this->m_speaking=speaking;
}
void Human::setEating(property eating){
    this->m_eating=eating;
}
void Human::setSleeping(property sleeping){
    this->m_sleeping=sleeping;
}
void Human::setReading(property reading){
    this->m_reading=reading;
}

/* NOTE: On tanimli enum lar ile ilgili karsilastirma yapildigi icin */
/* genel konvensiyon olan switch case deyimi kullanilabilir.         */
std::string Human::propertyToString(property property)
{
    if(property == Slow){
        return "Slow";
    }
    else if(property==Normal){
        return "Normal";
    }
    else if(property==Fast){
        return "Fast";
    }
    else{
        std::cerr<<"Error: printPropert unknown property";
        return "Error";
    }
}

void Human::printAllProperties()
{
    std::cout<<"Walking= "<<propertyToString(getWalking())<<std::endl;
    std::cout<<"Running= "<<propertyToString(getRunning())<<std::endl;
    std::cout<<"Speaking= "<<propertyToString(getSpeaking())<<std::endl;
    std::cout<<"Eating= "<<propertyToString(getEating())<<std::endl;
    std::cout<<"Sleeping= "<<propertyToString(getSleeping())<<std::endl;
    std::cout<<"Reading= "<<propertyToString(getReading())<<std::endl;
}

Human::property Human::getWalking(){
    return this->m_walking;
}

Human::property Human::getRunning(){
    return this->m_running;
}

Human::property Human::getSpeaking(){
    return this->m_speaking;
}

Human::property Human::getEating(){
    return this->m_eating;
}

Human::property Human::getSleeping(){
    return this->m_sleeping;
}

Human::property Human::getReading(){
    return this->m_reading;
}
