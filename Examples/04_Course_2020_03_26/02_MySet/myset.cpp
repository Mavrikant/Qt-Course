#include "myset.h"
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

MySet::MySet()
{
    counter=0;
}

void MySet::insert(int newItem)
{
    if(!contains(newItem)){
        items[counter]=newItem;
        counter++;
     }
}

MySet MySet::operator<<(int newItem)
{
    insert(newItem);
    return *this;
}

bool MySet::operator<(MySet newSet)
{
    for(unsigned int i=0; i<newSet.counter; i++){
        if(this->contains(newSet.items[i])){
            return false;
        }
    }
    return true;
}

bool MySet::contains(int item)
{
    for(unsigned int i=0;i<counter;i++){
        if(item==items[i]){
            return true;
        }
    }
    return false;
}

void MySet::print()
{
    for (unsigned int i=0; i<counter; i++){
        cout<<items[i]<<endl;
    }
}
