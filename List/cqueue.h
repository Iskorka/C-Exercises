#ifndef CQUEUE_H
#define CQUEUE_H

#include <iostream>
#include "CList.h"

template
<typename T>
class CQueue
{
public:
    CQueue();
    CQueue(const CQueue &q);

    void add(const T &val);
    void show();

    inline T front() const;
    inline T back() const;

    T pop();

    int size() const;

    bool empty();

    CQueue<T> &operator =(const CQueue<T> &rqueue);
    bool operator==(const CQueue<T> &rqueue);
    bool operator!=(const CQueue<T> &rqueue);
    bool operator>(const CQueue<T> &rqueue);
    bool operator<(const CQueue<T> &rqueue);
    bool operator>=(const CQueue<T> &rqueue);
    bool operator<=(const CQueue<T> &rqueue);

    ~CQueue();

private:

    CList<T> elements_;

    int size_;
};

#endif // CQUEUE_H

template<typename T>
CQueue<T>::CQueue() : size_(0)
{

}

template<typename T>
CQueue<T>::CQueue(const CQueue &q)
{
    this->elements_ = q.elements_;
}

template<typename T>
void CQueue<T>::add(const T &val)
{
    elements_.add(val);

    ++size_;
}

template<typename T>
void CQueue<T>::show()
{
    elements_.show();
}

template<typename T>
T CQueue<T>::front() const
{
    return elements_.first();
}

template<typename T>
T CQueue<T>::back() const
{
    return elements_.last();
}

template<typename T>
T CQueue<T>::pop()
{
    --size_;
    return elements_.popFront();
}

template<typename T>
int CQueue<T>::size() const
{
    return size_;
}

template<typename T>
bool CQueue<T>::empty()
{
    return elements_.empty();
}

template<typename T>
CQueue<T>& CQueue<T>::operator =(const CQueue<T> &rqueue)
{
    elements_ = rqueue.elements_;
}

template<typename T>
bool CQueue<T>::operator==(const CQueue<T> &rqueue)
{
    return (elements_ == rqueue.elements_);
}

template<typename T>
bool CQueue<T>::operator!=(const CQueue<T> &rqueue)
{
    return (elements_ != rqueue.elements_);
}

template<typename T>
bool CQueue<T>::operator>(const CQueue<T> &rqueue)
{
    return (elements_ > rqueue.elements_);
}

template<typename T>
bool CQueue<T>::operator<(const CQueue<T> &rqueue)
{
    return (elements_ < rqueue.elements_);
}

template<typename T>
bool CQueue<T>::operator>=(const CQueue<T> &rqueue)
{
    return (elements_ >= rqueue.elements_);
}

template<typename T>
bool CQueue<T>::operator<=(const CQueue<T> &rqueue)
{
    return (elements_ <= rqueue.elements_);
}

template<typename T>
CQueue<T>::~CQueue()
{
    elements_.clear();
}
