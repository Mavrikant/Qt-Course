#ifndef MYSET_H
#define MYSET_H
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class MySet
{
    const static unsigned int MaxSize =100;
public:
    MySet();
    void insert(int newItem);
    //MySet operator<< (MySet newMySet);
    MySet operator<< (int newItem);
    bool operator< (MySet newMySet);
    bool contains(int item);

    void print();
private:
    int items[MaxSize];
    unsigned int counter;
    //list  <int> myList;
};

#endif // MYSET_H
