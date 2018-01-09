#ifndef CPRIORITYQUEUE_H
#define CPRIORITYQUEUE_H

#include "CList.h"
#include <iostream>

template
<typename T>
class CPriorityQueue
{
public:
    CPriorityQueue();
    CPriorityQueue(const CPriorityQueue<T> &q);
    explicit CPriorityQueue(const CList<T> &elements);

    void push(const T &val);
    void show();
    int size() const;
    bool empty();

    CPriorityQueue<T> &operator =(const CPriorityQueue<T> &rq);
    bool operator==(const CPriorityQueue<T> &rq);
    bool operator!=(const CPriorityQueue<T> &rq);
    bool operator>(const CPriorityQueue<T> &rq);
    bool operator<(const CPriorityQueue<T> &rq);
    bool operator>=(const CPriorityQueue<T> &rq);
    bool operator<=(const CPriorityQueue<T> &rq);

    ~CPriorityQueue();

private:
    CList<T> elements_;

    int size_;
};

#endif

template<typename T>
CPriorityQueue<T>::CPriorityQueue() : size_(0)
{

}

template<typename T>
CPriorityQueue<T>::CPriorityQueue(const CPriorityQueue<T> &q)
{
    elements_ = q.elements_;

    size_ = q.size_;
}

template<typename T>
CPriorityQueue<T>::CPriorityQueue(const CList<T> &elements) : elements_(elements), size_(0) {}

template<typename T>
void CPriorityQueue<T>::push(const T &val)
{
    if (elements_.empty())
    {
        elements_.add(val);
    }

    else
    {
        int i=0;
        while (i < elements_.size())
        {
            if (elements_.atPos(i) <= val)
            {
                break;
            }

            ++i;
        }

        elements_.insert(i, val);
    }

    ++size_;
}

template<typename T>
void CPriorityQueue<T>::show()
{
    elements_.show();
}


template<typename T>
int CPriorityQueue<T>::size() const
{
    return size_;
}

template<typename T>
bool CPriorityQueue<T>::empty()
{
    return elements_.empty();
}

template<typename T>
CPriorityQueue<T>& CPriorityQueue<T>::operator =(const CPriorityQueue<T> &rq)
{
    elements_ = rq.elements_;
}

template<typename T>
bool CPriorityQueue<T>::operator==(const CPriorityQueue<T> &rq)
{
    return (elements_ == rq.elements_);
}

template<typename T>
bool CPriorityQueue<T>::operator!=(const CPriorityQueue<T> &rq)
{
    return (elements_ != rq.elements_);
}

template<typename T>
bool CPriorityQueue<T>::operator>(const CPriorityQueue<T> &rq)
{
    return (elements_ > rq.elements_);
}

template<typename T>
bool CPriorityQueue<T>::operator<(const CPriorityQueue<T> &rq)
{
    return (elements_ < rq.elements_);
}

template<typename T>
bool CPriorityQueue<T>::operator>=(const CPriorityQueue<T> &rq)
{
    return (elements_ >= rq.elements_);
}

template<typename T>
bool CPriorityQueue<T>::operator<=(const CPriorityQueue<T> &rq)
{
    return (elements_ <= rq.elements_);
}

template<typename T>
CPriorityQueue<T>::~CPriorityQueue()
{
    elements_.clear();
}
