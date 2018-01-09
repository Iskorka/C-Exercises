#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>

template
<typename T>
class SmartPointer
{
public:
    explicit SmartPointer(T* object);
    SmartPointer(const SmartPointer<T> &pointer);
    SmartPointer(SmartPointer<T> &&pointer);
    ~SmartPointer();

    SmartPointer<T>& operator =(const SmartPointer<T> &pointer);
    SmartPointer<T>& operator =(SmartPointer<T> &&pointer);
    T& operator *();
    SmartPointer<T>* operator ->();
private:
    T* m_object;
    int* m_referenceCounter;
};

#endif // SMARTPOINTER_H


template<typename T>
SmartPointer<T>::SmartPointer(T *object) : m_object(object), m_referenceCounter(new int(1))
{
    std::cout<<"Param\n";
}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &pointer)
{
    std::cout << "Copy\n";
    m_object = new T(*pointer.m_object);
    m_referenceCounter = pointer.m_referenceCounter;
    ++(*m_referenceCounter);
}

template<typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &&pointer)
{
    std::cout<<"Move constructor\n";
    m_object = pointer.m_object;
    pointer.m_object = nullptr;

    m_referenceCounter = pointer.m_referenceCounter;
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
    --(*m_referenceCounter);
    std::cout << "refcount: " << *m_referenceCounter << std::endl;
    if (1 > *m_referenceCounter)
    {
        delete m_object;
        m_object = nullptr;

        delete m_referenceCounter;
        m_referenceCounter = nullptr;
    }
}

template<typename T>
SmartPointer<T> &SmartPointer<T>::operator =(const SmartPointer<T> &pointer)
{
    std::cout << "Assign\n";
    if (this != &pointer)
    {
        m_object = new T(*pointer.m_object);
        m_referenceCounter = pointer.m_referenceCounter;
        ++(*m_referenceCounter);
    }

    return *this;
}

template<typename T>
SmartPointer<T> &SmartPointer<T>::operator =(SmartPointer<T> &&pointer)
{
    std::cout<<"Move operator\n";
    if (this != &pointer)
    {
        m_object = pointer.m_object;
        pointer.m_object = nullptr;

        m_referenceCounter = pointer.m_referenceCounter;
    }

    return *this;
}

template<typename T>
inline T &SmartPointer<T>::operator *()
{
    return *m_object;
}

template<typename T>
inline SmartPointer<T> *SmartPointer<T>::operator ->()
{
    return m_object;
}
