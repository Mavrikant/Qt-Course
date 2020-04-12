#include <iostream>
#include "human.h"
#include "student.h"
#include "teacher.h"

/* NOTE: Ödevde eksik sınıflar var. */

int main()
{
    Human Yusuf;
    Student Student1(Human::Slow);
    Student Student2(Human::Normal);
    Student Student3(Human::Fast);
    Teacher Teacher1(Human::Fast);

    Yusuf.setWalking(Human::Slow);
    std::cout<<"Yusuf.getwalking="<<Human::printProperty(Yusuf.getWalking())<<std::endl<<std::endl;

    Teacher1.setReading(Human::Fast);
    std::cout<<"Teacher1.getTeaching="<<Teacher::printProperty(Teacher1.getTeaching())<<std::endl;
    std::cout<<"Teacher1.getReading="<<Teacher::printProperty(Teacher1.getReading())<<std::endl<<std::endl;

    Student1.setEating(Human::Slow);
    std::cout<<"Student1.getEating="<<Student::printProperty(Student1.getEating())<<std::endl;
    std::cout<<"Student1.getStudying="<<Student::printProperty(Student1.getStudying())<<std::endl<<std::endl;

    Student2.setEating(Human::Normal);
    std::cout<<"Student2.getEating="<<Student::printProperty(Student2.getEating())<<std::endl;
    std::cout<<"Student2.getStudying="<<Student::printProperty(Student2.getStudying())<<std::endl<<std::endl;

    Student3.setEating(Human::Fast);
    std::cout<<"Student3.getEating="<<Student::printProperty(Student3.getEating())<<std::endl;
    std::cout<<"Student3.getStudying="<<Student::printProperty(Student3.getStudying())<<std::endl<<std::endl;



    return 0;
}
