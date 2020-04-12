#include "teacher.h"
#include "human.h"

Teacher::Teacher(Human::m_property teaching,Human::m_property walking,Human::m_property running,Human::m_property speaking,Human::m_property eating,Human::m_property sleeping,Human::m_property reading)
{
	/* WARNING: Buda hatalı. Yerel değişken neden? */
    Human(walking, running, speaking, eating, sleeping, reading);
    this->m_teaching = teaching;
}

void Teacher::setTeaching(Human::m_property teaching)
{
    this->m_teaching=teaching;
}

Human::m_property Teacher::getTeaching()
{
    return this->m_teaching;
}
