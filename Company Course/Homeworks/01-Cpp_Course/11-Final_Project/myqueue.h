#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "mycontainer.h"
#include <iostream>

template <typename T>
class MyQueue : public MyContainer<T>
{
public:
    MyQueue();

    //Base Class Functions
    /**
     * @brief push MyQueue'nun sonuna yeni eleman ekler.
     * @param newItem MyQueue'ya eklenecek yeni eleman.
     */
    void push(T newItem);
    /**
     * @brief pop MyQueue'nun başından elemanın döndürür.
     * @throw Exception if MyQueue is empty.
     * @return
     */
    T pop();

    // Member Functions
    /**
     * @brief front Bir sonraki elemana erişir.
     * @throw Exception if MyQueue is empty.
     * @return
     */
    T front();

    /**
     * @brief back Son elemana erişir.
     * @throw Exception if MyQueue is empty.
     * @return
     */
    T back ();

    /**
     * @brief swap *this içerisinde bulunan elemanların hepsini fonsksiyon çağrısında verilen argüman MyQueue sınıfı türünden değişken ile takas eder.
     * @param otherMyQueue
     */
    void swap(MyQueue <T> &otherMyQueue);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out,  const MyQueue <U> &Queue);


private:
    int frontIndex = -1;
    int rearIndex = -1;
    void transferToBiggerContainer();
};

#endif // MYQUEUE_H


template<typename T>
MyQueue<T>::MyQueue(): MyContainer<T>()
{

}


template<typename T>
void MyQueue<T>::push(T newItem)
{
    if (this->isEmpty())
    {
        frontIndex = 0;
        rearIndex = 0;
        this->ptrContainer[frontIndex] = newItem;
        this->m_nodeCount++;
    }
    else if (!this->isFull())
    {
        frontIndex = (frontIndex + 1) % this->m_containerCapacity;
        this->ptrContainer[frontIndex] = newItem;
        this->m_nodeCount++;
    }
    else
    {
        transferToBiggerContainer();
        frontIndex = (frontIndex + 1) % this->m_containerCapacity;
        this->ptrContainer[frontIndex] = newItem;
        this->m_nodeCount++;
    }
}

template<typename T>
T MyQueue<T>::pop()
{
    if (!this->isEmpty())
    {
        this->m_nodeCount--;
        T temp = this->ptrContainer[rearIndex];
        this->ptrContainer[rearIndex] = 0;
        rearIndex = (rearIndex + 1) % this->m_containerCapacity;
        return temp;
    }
    else
    {
        throw "MyQueue is Empty";
    }

}

template<typename T>
T MyQueue<T>::front()
{
    if (!this->isEmpty())
    {
        return this->ptrContainer[this->frontIndex];
    }
    else
    {
        throw "MyQueue is Empty";
    }
}

template<typename T>
T MyQueue<T>::back()
{
    if (!this->isEmpty())
    {
        return this->ptrContainer[this->rearIndex];
    }
    else
    {
        throw "MyQueue is Empty";
    }
}

template<typename T>
void MyQueue<T>::swap(MyQueue<T> &otherMyQueue)
{
    int tempRearIndex = this->rearIndex;
    int tempFrontIndex = this->frontIndex;
    T *tempPtrContainer = this->ptrContainer;
    int tempNodeCount = this->m_nodeCount;
    int tempContainerCapacity = this->m_containerCapacity;

    this->rearIndex = otherMyQueue.rearIndex;
    this->frontIndex = otherMyQueue.frontIndex;
    this->ptrContainer = otherMyQueue.ptrContainer;
    this->m_nodeCount = otherMyQueue.m_nodeCount;
    this->m_containerCapacity = otherMyQueue.m_containerCapacity;

    otherMyQueue.rearIndex = tempRearIndex;
    otherMyQueue.frontIndex = tempFrontIndex;
    otherMyQueue.ptrContainer = tempPtrContainer;
    otherMyQueue.m_nodeCount = tempNodeCount;
    otherMyQueue.m_containerCapacity = tempContainerCapacity;
}

template<typename T>
void MyQueue<T>::transferToBiggerContainer()
{

    T *biggerContainer = new T[this->m_containerCapacity * 2];
    for (int i = 0; i < this->m_nodeCount; i++)
    {
        biggerContainer[i] = this->ptrContainer[(this->rearIndex + i) % this->m_containerCapacity];
    }

    this->m_containerCapacity *= 2;
    this->rearIndex = 0;
    this->frontIndex = this->m_nodeCount - 1;
    delete[] this->ptrContainer;
    this->ptrContainer = biggerContainer;
}


template<typename U>
std::ostream &operator<<(std::ostream &out,  const MyQueue <U> &Queue)
{
    for (int i = 0; i < Queue.m_nodeCount; i++)
    {
        out << Queue.ptrContainer[(Queue.rearIndex + i) % Queue.m_containerCapacity] << ", ";
    }
    return out << std::endl;
}
