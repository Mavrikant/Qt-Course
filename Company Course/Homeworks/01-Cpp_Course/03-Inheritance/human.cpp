#include "human.h"
#include <iostream>

Human::Human(m_property walking,m_property running,m_property speaking,m_property eating,m_property sleeping,m_property reading){
    /* NOTE: "m_" ön eki zaten sınıfın member variable ı olduğunu belli ediyor. Tekarar this eklemek okunabilirliği azaltıyor. */
    this->m_walking=walking;
    this->m_running=running;
    this->m_speaking=speaking;
    this->m_eating=eating;
    this->m_sleeping=sleeping;
    this->m_reading=reading;
}

void Human::setWalking(m_property walking){
    this->m_walking=walking;
}

void Human::setRunnig(m_property running){
    this->m_running=running;
}
void Human::setSpeaking(m_property speaking){
    this->m_speaking=speaking;
}
void Human::setEating(m_property eating){
    this->m_eating=eating;
}
void Human::setSleeping(m_property sleeping){
    this->m_sleeping=sleeping;
}
void Human::setReading(m_property reading){
    this->m_reading=reading;
}

std::string Human::printProperty(m_property property)
{
    /* NOTE: Switch case kullanılabilir. */
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

Human::m_property Human::getWalking(){
    return this->m_walking;
}

Human::m_property Human::getRunnig(){
    return this->m_running;
}

Human::m_property Human::getSpeaking(){
    return this->m_speaking;
}

Human::m_property Human::getEating(){
    return this->m_eating;
}

Human::m_property Human::getSleeping(){
    return this->m_sleeping;
}

Human::m_property Human::getReading(){
    return this->m_reading;
}
