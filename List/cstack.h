#ifndef CSTACK_H
#define CSTACK_H
#include "CList.h"

template
<typename T>
class CStack
{
public:
    CStack();
    CStack(const CStack<T>& s);

    void add(const T &val);
    void pop();

    T top() const;

    bool empty();

    int size() const;

    CStack<T> &operator =(const CStack<T> &rstack);
    bool operator==(const CStack<T> &rstack);
    bool operator!=(const CStack<T> &rstack);
    bool operator>(const CStack<T> &rstack);
    bool operator<(const CStack<T> &rstack);
    bool operator>=(const CStack<T> &rstack);
    bool operator<=(const CStack<T> &rstack);

    ~CStack();

private:

    CList<T> elements_;
    int size_;
};

#endif // CSTACK_H

template<typename T>
CStack<T>::CStack() : size_(0) {}

template<typename T>
CStack<T>::CStack(const CStack<T>& s)
{
    this->elements_ = s.elements_;
}

template<typename T>
void CStack<T>::add(const T &val)
{
    elements_.add(val);
    ++size_;
}

template<typename T>
inline T CStack<T>::top() const
{
    return elements_.last();
}

template<typename T>
void CStack<T>::pop()
{
    elements_.popBack();
    --size_;
}

template<typename T>
bool CStack<T>::empty()
{
    return elements_.empty();
}

template<typename T>
inline int CStack<T>::size() const
{
    return size_;
}

template<typename T>
CStack<T>& CStack<T>::operator =(const CStack<T> &rstack)
{
    elements_ = rstack.elements_;
}

template<typename T>
bool CStack<T>::operator==(const CStack<T> &rstack)
{
    return (elements_ == rstack.elements_);
}

template<typename T>
bool CStack<T>::operator!=(const CStack<T> &rstack)
{
    return (elements_ != rstack.elements_);
}

template<typename T>
bool CStack<T>::operator>(const CStack<T> &rstack)
{
    return (elements_ > rstack.elements_);
}

template<typename T>
bool CStack<T>::operator<(const CStack<T> &rstack)
{
    return (elements_ < rstack.elements_);
}

template<typename T>
bool CStack<T>::operator>=(const CStack<T> &rstack)
{
    return (elements_ >= rstack.elements_);
}

template<typename T>
bool CStack<T>::operator<=(const CStack<T> &rstack)
{
    return (elements_ <= rstack.elements_);
}

template<typename T>
CStack<T>::~CStack()
{
    elements_.clear();
}
