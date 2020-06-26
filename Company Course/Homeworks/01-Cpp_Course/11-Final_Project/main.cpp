#include <iostream>
#include "myqueue.h"
#include "mystack.h"


int main()
{
    MyQueue<int> q1, q2;
    MyStack<double> s1, s2;

    std::cout << "*********   MyQueue   ********" << std::endl;
    q1.push(1);
    q1.push(11);
    q1.push(111);

    std::cout << "### Before pop" << std::endl;
    std::cout << "q1: " << q1;
    q1.pop();

    q2.push(2);
    q2.push(22);
    q2.push(222);

    std::cout << "### Before swap" << std::endl;
    std::cout << "q1: " << q1;
    std::cout << "q2: " << q2;

    q1.swap(q2);

    std::cout << "### After swap" << std::endl;
    std::cout << "q1: " << q1;
    std::cout << "q2: " << q2;

    std::cout << std::endl << "*********   MyStack   ********" << std::endl;


    s1.push(1);
    s1.push(1.1);
    s1.push(1.11);

    std::cout << "### Before pop" << std::endl;
    std::cout << "s1: " << s1;
    s1.pop();

    s2.push(2);
    s2.push(2.2);
    s2.push(2.22);

    std::cout << "### Before swap" << std::endl;
    std::cout << "s1: " << s1;
    std::cout << "s2: " << s2;

    s1.swap(s2);

    std::cout << "### After swap" << std::endl;
    std::cout << "s1: " << s1;
    std::cout << "s2: " << s2;

}


