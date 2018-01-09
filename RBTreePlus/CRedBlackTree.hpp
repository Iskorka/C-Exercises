#ifndef CREDBLACKTREE_H
#define CREDBLACKTREE_H

#include "NProperties.hpp"
#include <iostream>

template
<typename T>
class CRedBlackTree
{
public:
    CRedBlackTree();
    ~CRedBlackTree();

    void insert(const T &value);

    const int& getSize() const;

    void clear();

    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();

    const T &search(const T &value) const;

private:
    /* TODO: inplement copy constructor and assingment operator */
    CRedBlackTree(const CRedBlackTree &tree);
    CRedBlackTree<T>& operator=(const CRedBlackTree &tree);

    NProperties::sNode<T>* rotateLeft(NProperties::sNode<T>* node);
    NProperties::sNode<T>* rotateRight(NProperties::sNode<T>* node);

    void flipColors(NProperties::sNode<T>* node);

    NProperties::sNode<T> *insert(T value, NProperties::sNode<T>* node);

    void clear(NProperties::sNode<T> *node);

    void preOrderTraversal(NProperties::sNode<T> *node);
    void inOrderTraversal(NProperties::sNode<T> *node);
    void postOrderTraversal(NProperties::sNode<T> *node);

    NProperties::sNode<T>*
    search(const T &value, NProperties::sNode<T> *node) const;

    NProperties::sNode<T>* m_root;
    int m_size;

    /* TODO: tree size field */
};

#endif // CREDBLACKTREE_H

template<typename T>
CRedBlackTree<T>::CRedBlackTree() : m_root(nullptr), m_size(0)
{
}

template<typename T>
CRedBlackTree<T>::~CRedBlackTree()
{
    clear();
}

template<typename T>
NProperties::sNode<T> *CRedBlackTree<T>::rotateLeft(NProperties::sNode<T>* node)
{
    if (nullptr != node && node->m_right->isRed())
    {
        NProperties::sNode<T>* pivot = node->m_right;

        node->m_right = pivot->m_left;
        pivot->m_left = node;
        pivot->m_color = node->m_color;
        node->makeRed();
        return pivot;
    }

    return nullptr;
}

template<typename T>
NProperties::sNode<T> *CRedBlackTree<T>::
rotateRight(NProperties::sNode<T>* node)
{
    if (nullptr != node && node->m_left->isRed())
    {
        NProperties::sNode<T>* pivot = node->m_left;

        node->m_left = pivot->m_right;
        pivot->m_right = node;
        pivot->m_color = node->m_color;
        node->makeRed();
        return pivot;
    }

    return nullptr;
}

template<typename T>
void CRedBlackTree<T>::flipColors(NProperties::sNode<T> *node)
{
    node->makeRed();
    node->m_left->makeBlack();
    node->m_right->makeBlack();
}

template<typename T>
inline const int &CRedBlackTree<T>::getSize() const
{
    return m_size;
}

template<typename T>
void CRedBlackTree<T>::insert(const T &value)
{
    m_root = insert(value, m_root);
    m_root->makeBlack();

    ++m_size;
}

template<typename T>
NProperties::sNode<T>* CRedBlackTree<T>::
insert(T value, NProperties::sNode<T> *node)
{
    if (nullptr == node)
    {
        return new NProperties::sNode<T>(value);
    }

    if (value < node->m_value)
    {
        node->m_left = insert(value, node->m_left);
    }

    else if (value > node->m_value)
    {
        node->m_right = insert(value, node->m_right);
    }

    else
    {
        node->m_value = value;
    }

    if (node->m_right->isRed() && !node->m_left->isRed())
    {
        node = rotateLeft(node);
    }

    if (node->m_left->isRed() && node->m_left->m_left->isRed())
    {
        node = rotateRight(node);
    }

    if (node->m_left->isRed() && node->m_right->isRed())
    {
        flipColors(node);
    }

    return node;
}

template<typename T>
void CRedBlackTree<T>::clear()
{
    clear(m_root);
}

template<typename T>
void CRedBlackTree<T>::clear(NProperties::sNode<T> *node)
{
    if (nullptr != node->m_left)
    {
        clear(node->m_left);
    }

    if (nullptr != node->m_right)
    {
        clear(node->m_right);
    }

    delete node;

    m_size = 0;
}

template<typename T>
void CRedBlackTree<T>::preOrderTraversal()
{
    preOrderTraversal(m_root);
}

template<typename T>
void CRedBlackTree<T>::preOrderTraversal(NProperties::sNode<T> *node)
{
    std::cout << node->m_value;

    if (nullptr != node->m_left)
    {
        preOrderTraversal(node->m_left);
    }


    if (nullptr != node->m_right)
    {
        preOrderTraversal(node->m_right);
    }
}

template<typename T>
void CRedBlackTree<T>::inOrderTraversal()
{
    inOrderTraversal(m_root);
}

template<typename T>
void CRedBlackTree<T>::inOrderTraversal(NProperties::sNode<T> *node)
{
    if (nullptr != node->m_left)
    {
        inOrderTraversal(node->m_left);
    }

    std::cout << node->m_value;

    if (nullptr != node->m_right)
    {
        inOrderTraversal(node->m_right);
    }
}

template<typename T>
void CRedBlackTree<T>::postOrderTraversal()
{
    postOrderTraversal(m_root);
}

template<typename T>
void CRedBlackTree<T>::postOrderTraversal(NProperties::sNode<T> *node)
{
    if (nullptr != node->m_left)
    {
        postOrderTraversal(node->m_left);
    }

    if (nullptr != node->m_right)
    {
        postOrderTraversal(node->m_right);
    }

    std::cout << node->m_value;
}

template<typename T>
inline const T& CRedBlackTree<T>::search(const T &value) const
{
    return search(value, m_root)->m_value;
}

template<typename T>
NProperties::sNode<T> *CRedBlackTree<T>::
search(const T &value, NProperties::sNode<T> *node) const
{
    if (nullptr != node)
    {
        if (value == node->m_value)
        {
            return node;
        }

        else if (value < node->m_value)
        {
            return search(value, node->m_left);
        }

        else
        {
            return search(value, node->m_right);
        }
    }

    return nullptr;
}
