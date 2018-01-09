#ifndef NODE_H
#define NODE_H

template
<typename T>
struct Node
{
    T val_;
    Node *next_, *prev_;

    Node() : next_(nullptr), prev_(nullptr) {}
};

#endif // NODE_H
