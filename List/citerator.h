#ifndef CITERATOR_H
#define CITERATOR_H

#include "node.h"

template
<typename T>
class CIterator
{
public:
    explicit CIterator(Node<T>* node);
    CIterator(const CIterator &iter);

    bool hasNext() const;
    bool hasPrevious() const;

    CIterator<T>& operator++();
    CIterator<T>& operator--();
    CIterator<T> operator++(int);
    CIterator<T> operator--(int);

    CIterator<T>& operator+=(int count);
    CIterator<T>& operator-=(int count);
    CIterator<T>& operator+(int count);
    CIterator<T>& operator-(int count);


    T operator*();
    CIterator<T>* operator->();

    bool operator==(const CIterator &iter);
    bool operator!=(const CIterator &iter);

private:
    Node<T>* m_current;
};

#endif // CITERATOR_H

template<typename T>
CIterator<T>::CIterator(Node<T> *node)
{
    m_current = node;
}

template<typename T>
CIterator<T>::CIterator(const CIterator &iter)
{
    m_current = iter.m_current;
}

template<typename T>
bool CIterator<T>::hasNext() const
{
    if (m_current->next_ != nullptr)
    {
        return true;
    }

    return false;
}

template<typename T>
bool CIterator<T>::hasPrevious() const
{
    if (m_current->prev_ != nullptr)
    {
        return true;
    }

    return false;
}

template<typename T>
CIterator<T> &CIterator<T>::operator++()
{
    m_current = m_current->next_;
    return *this;
}

template<typename T>
CIterator<T> &CIterator<T>::operator--()
{
    m_current = m_current->prev_;
    return *this;
}

template<typename T>
CIterator<T> CIterator<T>::operator++(int)
{
    CIterator<T> copy = *this;
    ++(*this);
    return copy;
}

template<typename T>
CIterator<T> CIterator<T>::operator--(int)
{
    CIterator<T> copy = *this;
    --(*this);
    return copy;
}

template<typename T>
CIterator<T> &CIterator<T>::operator+=(int count)
{
    for (int i=0; i<count; ++i)
    {
        m_current = m_current->next_;
    }

    return *this;
}

template<typename T>
CIterator<T> &CIterator<T>::operator-=(int count)
{
    for (int i=0; i<count; ++i)
    {
        m_current = m_current->prev_;
    }

    return *this;
}

template<typename T>
CIterator<T> &CIterator<T>::operator+(int count)
{
    return *this+=count;
}

template<typename T>
CIterator<T> &CIterator<T>::operator-(int count)
{
    return *this-=count;
}

template<typename T>
T CIterator<T>::operator*()
{
    return m_current->val_;
}

template<typename T>
CIterator<T> *CIterator<T>::operator->()
{
    return this;
}

template<typename T>
bool CIterator<T>::operator==(const CIterator &iter)
{
    if (this == &iter)
    {
        return true;
    }

    else
    {
        if (this->m_current == iter.m_current)
        {
            return true;
        }
    }

    return false;
}

template<typename T>
bool CIterator<T>::operator!=(const CIterator &iter)
{
    if (this != &iter)
    {
        return true;
    }

    else
    {
        if(m_current != iter.m_current)
        {
            return true;
        }
    }

    return false;
}
