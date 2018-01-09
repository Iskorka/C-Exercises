#ifndef CLIST_H
#define CLIST_H

#include <iostream>
#include "Node.h"
#include "citerator.h"

template
<typename T>
class CList
{
public:
    CList();

    void add(T const &val);
    void pushFront(T const &val);
    void insert(int index, T const &val);

    T popBack();
    T popFront();
    T pop(int index);

    T first() const;
    T last() const;
    T atPos(int index) const;

    CIterator<T> begin();
    CIterator<T> end();

    bool empty();
    void clear();
    int size() const;

    void show() const;
    void showReversed() const;

    bool operator==(const CList<T> &rlist);
    bool operator !=(const CList<T> &rlist);
    bool operator >(const CList<T> &rlist);
    bool operator <(const CList<T> &rlist);
    bool operator >=(const CList<T> &rlist);
    bool operator <=(const CList<T> &rlist);
    const CList<T>& operator =(const CList<T> &rlist);

    ~CList();

private:
    Node<T> *head_, *tail_;
    int size_;
};

#endif // CLIST_H

template<typename T>
CList<T>::CList() : head_(nullptr), tail_(nullptr), size_(0)
{

}


template<typename T>
void CList<T>::add(const T &val)
{
    Node<T>* newElem = new Node<T>;
    newElem->val_ = val;

    if (head_ == nullptr)
    {
        newElem->prev_ = nullptr;
        head_ = newElem;
    }

    else
    {
        newElem->prev_ = tail_;
        tail_->next_ = newElem;
        newElem->next_ = nullptr;
    }

    tail_ = newElem;
    ++size_;
}

template<typename T>
void CList<T>::pushFront(T const &val)
{
    Node<T>* newElem = new Node<T>;
    newElem->val_ = val;

    if (head_ == nullptr)
    {
        head_ = newElem;
    }

    else
    {
        newElem->next_ = head_;
        head_->prev_ = newElem;

    }

    head_ = newElem;
    ++size_;
}

template<typename T>
void CList<T>::insert(int index, const T &val)
{
    if (index > size_ || index < 0)
    {
        throw std::runtime_error("Index out of range");
    }

    Node<T>* temp = head_;
    Node<T>* newElem = new Node<T>;

    newElem->val_ = val;

    if (index == 0)
    {
        pushFront(val);
    }

    else if (index == size_)
    {
        add(val);
    }

    else
    {
        for (int i=0; i<=index; ++i)
        {
            if (i == index)
            {
                newElem->next_ = temp;
                newElem->prev_ = temp->prev_;
                temp->prev_->next_ = newElem;
                temp->prev_ = newElem;

            }

            temp = temp->next_;
        }

        ++size_;
    }
}

template<typename T>
T CList<T>::popBack()
{
    Node<T>* temp = tail_->prev_;
    T tempVal = tail_->val_;

    delete tail_;

    tail_ = temp;

    --size_;

    return tempVal;
}

template<typename T>
T CList<T>::popFront()
{
    Node<T>* temp = head_;
    T tempVal = temp->val_;
    head_ = temp->next_;
    delete temp;
    --size_;
    return tempVal;
}

template<typename T>
T CList<T>::pop(int index)
{
    if (index > size_ || index < 0)
    {
        throw std::runtime_error("Index out of range");
    }

    else if (index == 0)
    {
        popFront();
    }

    else if (index == size_)
    {
        popBack();
    }

    else
    {
        Node<T>* temp = head_;
        for (int i=0; i<=index; ++i)
        {
            if (i == index)
            {
                T tempVal = temp->val_;
                temp->prev_->next_ = temp->next_;
                temp->next_->prev_ = temp->prev_;

                delete temp;

                --size_;

                return tempVal;
            }

            temp = temp->next_;
        }
    }
    return 0;
}

template<typename T>
T CList<T>::first() const
{
    return head_-> val_;
}

template<typename T>
void CList<T>::clear()
{
    Node<T>* temp;

    while (size_ != 0)
    {
        temp = head_;
        head_ = temp->next_;

        delete temp;

        --size_;
    }
}

template<typename T>
T CList<T>::last() const
{
    if (head_ == nullptr)
    {
        throw std::runtime_error("No elements");
    }

    return tail_->val_;
}

template<typename T>
bool CList<T>::empty()
{
    if (head_)
    {
        return false;
    }

    return true;
}

template<typename T>
inline int CList<T>::size() const
{
    return size_;
}

template<typename T>
void CList<T>::show() const
{
    if (head_ == nullptr)
    {
        throw std::runtime_error("No elements to show");
    }

    else
    {
        Node<T>* temp = head_;

        for (int i=0; i<size_; ++i)
        {
            std::cout << temp->val_ << ' ';
            temp = temp->next_;
        }
    }
}

template<typename T>
void CList<T>::showReversed() const
{
    if (head_ == nullptr)
    {
        throw std::runtime_error("No elements to show");
    }

    else
    {
        Node<T>* temp = tail_;
        while (temp != head_->prev_)
        {
            std::cout << temp->val_ << ' ';
            temp = temp->prev_;
        }
    }
}

template<typename T>
T CList<T>::atPos(int index) const
{
    if (index >= size_ || index < 0)
    {
        throw std::runtime_error("Index out of range");
    }

    else
    {
        Node<T>* temp = head_;
        for (int i=0; i<=index; ++i)
        {
            if (i == index)
            {
                return temp->val_;
            }

            temp = temp->next_;
        }
    }

    return 0;
}

template<typename T>
CIterator<T> CList<T>::begin()
{
    return CIterator<T>(head_);
}

template<typename T>
CIterator<T> CList<T>::end()
{
    return CIterator<T>(tail_);
}

template<typename T>
bool CList<T>::operator==(const CList<T> &rlist)
{
    if (this == &rlist)
    {
        return true;
    }

    else if (size_ != rlist.size())
    {
        return false;
    }

    else
    {
        Node<T>* lTemp = head_;
        Node<T>* rTemp = rlist.head_;

        while (lTemp != tail_->next_)
        {
            if (lTemp->val_ != rTemp->val_)
            {
                return false;
            }

            lTemp = lTemp->next_;
            rTemp = rTemp->next_;
        }

        return true;
    }
}

template<typename T>
bool CList<T>::operator !=(const CList<T> &rlist)
{
    if (this == &rlist)
    {
        return false;
    }

    else if (size_ != rlist.size())
    {
        return true;
    }

    else
    {
        Node<T>* lTemp = head_;
        Node<T>* rTemp = rlist.head_;

        while (lTemp != tail_->next_)
        {
            if (lTemp->val_ != rTemp->val_)
            {
                return true;
            }

            lTemp = lTemp->next_;
            rTemp = rTemp->next_;
        }

        return false;
    }
}

template<typename T>
bool CList<T>::operator >(const CList<T> &rlist)
{
    if (this == &rlist)
    {
        return false;
    }

    else
    {
        Node<T>* lTemp = head_;
        Node<T>* rTemp = rlist.head_;

        while (lTemp != tail_->next_ && rTemp != rlist.tail_->next_)
        {
            if (lTemp->val_ < rTemp->val_)
            {
                return false;
            }

            else if (lTemp->val_ > rTemp->val_)
            {
                return true;
            }

            lTemp = lTemp->next_;
            rTemp = rTemp->next_;
        }

        return (lTemp != tail_->next_) && (rTemp == rlist.tail_->next_);
    }
}

template<typename T>
bool CList<T>::operator <(const CList<T> &rlist)
{
    if (this == &rlist)
    {
        return false;
    }


    else
    {
        Node<T>* lTemp = head_;
        Node<T>* rTemp = rlist.head_;

        while (lTemp != tail_->next_ && rTemp != rlist.tail_->next_)
        {
            if (lTemp->val_ < rTemp->val_)
            {
                return true;
            }

            else if (lTemp->val_ > rTemp->val_)
            {
                return false;
            }

            lTemp = lTemp->next_;
            rTemp = rTemp->next_;
        }

        return (lTemp == tail_->next_) && (rTemp != rlist.tail_->next_);
    }
}

template<typename T>
bool CList<T>::operator >=(const CList<T> &rlist)
{
    if (this == &rlist)
    {
        return true;
    }

    else
    {
        Node<T>* lTemp = head_;
        Node<T>* rTemp = rlist.head_;

        while (lTemp != tail_->next_ && rTemp != rlist.tail_->next_)
        {
            if (lTemp->val_ < rTemp->val_)
            {
                return false;
            }

            else if (lTemp->val_ > rTemp->val_)
            {
                return true;
            }

            lTemp = lTemp->next_;
            rTemp = rTemp->next_;
        }

        return (lTemp == tail_->next_) && (rTemp == rlist.tail_->next_);
    }
}

template<typename T>
bool CList<T>::operator <=(const CList<T> &rlist)
{
    if (this == &rlist)
    {
        return true;
    }

    else
    {
        Node<T>* lTemp = head_;
        Node<T>* rTemp = rlist.head_;

        while (lTemp != tail_->next_ && rTemp != rlist.tail_->next_)
        {
            if (lTemp->val_ < rTemp->val_)
            {
                return true;
            }

            else if (lTemp->val_ > rTemp->val_)
            {
                return false;
            }

            lTemp = lTemp->next_;
            rTemp = rTemp->next_;
        }

        return (lTemp == tail_->next_) && (rTemp == rlist.tail_->next_);
    }
}

template<typename T>
const CList<T> &CList<T>::operator =(const CList<T> &rlist)
{
    if (this != &rlist)
    {
        clear();
        Node<T>* temp = rlist.head_;

        for (int i=0; i<rlist.size_; ++i)
        {
            add(temp->val_);
            temp = temp->next_;
        }
    }

    return *this;
}

template<typename T>
CList<T>::~CList()
{
    clear();
}
