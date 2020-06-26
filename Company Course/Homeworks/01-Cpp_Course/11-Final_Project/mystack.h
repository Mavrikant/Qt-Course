#ifndef MYSTACK_H
#define MYSTACK_H
#include"mycontainer.h"
#include <iostream>


template <typename T>
class MyStack: public MyContainer<T>
{
public:
    MyStack();

    //Base Class Functions
    /**
     * @brief push MyStack'in sonuna yeni eleman ekler.
     * @param newItem MyStack'e eklenecek yeni eleman.
     */
    void push(T newItem);
    /**
     * @brief pop MyStack'in sonundan elemanı döndürür ve çıkartır.
     * @throw Exception if MyStack is empty.
     * @return
     */
    T pop();

    /**
     * @brief top MyStack'in sonundan elemanı döndürür
     * @return
     */
    T top();
    void swap(MyStack <T> &otherMyStack);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out,  const MyStack <U> &Stack);

private:
    void transferToBiggerContainer();


};


template<typename T>
MyStack<T>::MyStack(): MyContainer<T>()
{

}

template<typename T>
void MyStack<T>::push(T newItem)
{
    if (this->isFull())
    {
        transferToBiggerContainer();
    }

    this->ptrContainer[this->m_nodeCount] = newItem;
    this->m_nodeCount++;

}

template<typename T>
T MyStack<T>::pop()
{
    if (!this->isEmpty())
    {
        this->m_nodeCount--;
        return this->ptrContainer[this->m_nodeCount];
    }
    else
    {
        throw "MyQueue is Empty";
    }

}

template<typename T>
void MyStack<T>::swap(MyStack<T> &otherMyStack)
{
    T *tempPtrContainer = this->ptrContainer;
    int tempNodeCount = this->m_nodeCount;
    int tempContainerCapacity = this->m_containerCapacity;

    this->ptrContainer = otherMyStack.ptrContainer;
    this->m_nodeCount = otherMyStack.m_nodeCount;
    this->m_containerCapacity = otherMyStack.m_containerCapacity;


    otherMyStack.ptrContainer = tempPtrContainer;
    otherMyStack.m_nodeCount = tempNodeCount;
    otherMyStack.m_containerCapacity = tempContainerCapacity;
}

template<typename T>
void MyStack<T>::transferToBiggerContainer()
{

    T *biggerContainer = new T[this->m_containerCapacity * 2];
    for (int i = 0; i < this->m_nodeCount; i++)
    {
        biggerContainer[i] = this->ptrContainer[i];
    }

    delete[] this->ptrContainer;
    this->ptrContainer = biggerContainer;
}

template<typename U>
std::ostream &operator<<(std::ostream &out,  const MyStack <U> &Stack)
{
    for (int i = 0; i < Stack.m_nodeCount; i++)
    {
        out << Stack.ptrContainer[i] << ", ";
    }
    return out << std::endl;
}
#endif // MYSTACK_H
