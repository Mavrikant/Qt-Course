#ifndef MYCONTAINER_H
#define MYCONTAINER_H

template <typename T>
class MyContainer
{
public:
    MyContainer();
    int getNodeCount();
    int getContainerCapacity();
    bool isEmpty();
    bool isFull();
    virtual void push(T newItem) = 0;
    virtual  T pop() = 0;

protected:
    int m_nodeCount = 0;
    int m_containerCapacity = 10;
    T *ptrContainer = nullptr;
};

template<typename T>
MyContainer<T>::MyContainer()
{
    ptrContainer = new T [m_containerCapacity];
}

template<typename T>
int MyContainer<T>::getNodeCount()
{
    return m_nodeCount;
}

template<typename T>
int MyContainer<T>::getContainerCapacity()
{
    return m_containerCapacity;
}

template<typename T>
bool MyContainer<T>::isEmpty()
{
    return (0 == m_nodeCount);
}

template<typename T>
bool MyContainer<T>::isFull()
{
    return (m_containerCapacity == m_nodeCount);
}





#endif // MYCONTAINER_H
