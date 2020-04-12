#include "student.h"
#include "human.h"

/* WARNING: Burada geçici bir nesne yaratılmış ve herhangi bir yerde kullanılmamış. */
/* Amaç students içerisinde kalıtım yoluyla bulunan  taban sınıfın belirli			*/
/* değerlerini değiştirmekse aşağıdaki gibi yapılmalıdır. 							*/
// Student::Student(Human::m_property studying,Human::m_property walking,Human::m_property running,Human::m_property speaking,Human::m_property eating,Human::m_property sleeping,Human::m_property reading)
// : Human(walking, running, speaking, eating, sleeping, reading); 
// {
// 	// codes...
// }
Student::Student(Human::m_property studying,Human::m_property walking,Human::m_property running,Human::m_property speaking,Human::m_property eating,Human::m_property sleeping,Human::m_property reading)
{
    Human(walking, running, speaking, eating, sleeping, reading);
    this->m_studying=studying;
}

void Student::setStudying(Human::m_property studying)
{
    this->m_studying=studying;
}

Human::m_property Student::getStudying()
{
    return this->m_studying;
}
