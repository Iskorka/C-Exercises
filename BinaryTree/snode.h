#ifndef SNODE_H
#define SNODE_H

template
<typename T>
struct Node
{
    Node() : left(nullptr), right(nullptr), parent(nullptr) {}

    T val;
    Node<T> *left, *right, *parent;
};

#endif // SNODE_H
