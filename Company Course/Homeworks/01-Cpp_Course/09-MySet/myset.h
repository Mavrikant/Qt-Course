#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template <class T>
class MySet
{
    const static unsigned int MaxSize =100;

public:
    MySet();
    void insert(T newItem);
    bool contains(T item);
    void print();
    int size(){return counter;}
    MySet<T> &operator<< (T newItem);
    bool operator < ( MySet<T> &otherSet);

private:
    int items[MaxSize];
    unsigned int counter;
    void sort();
};

template <typename T>
MySet<T>::MySet()
{
    counter=0;
}

template <typename T>
void MySet<T>::insert(T newItem)
{
    if(!contains(newItem) and (counter!=MaxSize) ){
        items[counter]=newItem;
        counter++;
     }
}

template <typename T>
MySet<T> & MySet<T>::operator<<(T newItem)
{
    insert(newItem);
    return *this;
}

template <typename T>
bool MySet<T>::operator<( MySet<T> &otherSet)
{
    if(this->counter>otherSet.counter){
        return false;
    }

    if(otherSet.counter==0){
        return true;
    }

    for(unsigned int i=0; i<this->counter; i++){
        if(!otherSet.contains(this->items[i])){
            return false;
        }
    }
    return true;
}

template<typename T>
void MySet<T>::sort()
{
    bool swapped = true;
    auto begin = &items[0];
    auto end = &items[counter];

    while (begin != end-- && swapped) {
        swapped = false;
        for (auto i = begin; i != end; ++i) {
            if (*(i + 1) < *i) {
                std::iter_swap(i, i + 1);
                swapped = true;
            }
        }
    }
}

template <typename T>
bool MySet<T>::contains(T item)
{
    for(unsigned int i=0;i<counter;i++){
        if(item==items[i]){
            return true;
        }
    }
    return false;
}

template <typename T>
void MySet<T>::print()
{
    sort();
    cout<<"{";
    for (unsigned int i=0; i<counter; i++){
        cout<<items[i];
        if (!(i+1==counter)) cout<<",";
    }
    cout<<"}"<<endl;
}





#endif // MYSET_H
