#ifndef CBINARYTREE_H
#define CBINARYTREE_H

#include "snode.h"
#include <iostream>

template
<typename T>
class CBinaryTree
{
public:
    CBinaryTree();
    CBinaryTree(const CBinaryTree<T> &tree);

    void add(T val, Node<T> *tree);
    void add(T val);

    void show();

    void showNode(Node<T>* node, int depth);

    Node<T>* search(T val, Node<T> *node);
    Node<T>* search(T val);

    void clear(Node<T>* node);

    CBinaryTree<T>& operator=(const CBinaryTree<T> &tree);


    ~CBinaryTree();
private:
    Node<T>* m_root;
};

#endif // CBINARYTREE_H

template<typename T>
CBinaryTree<T>::CBinaryTree() : m_root(nullptr)
{

}

template<typename T>
CBinaryTree<T>::CBinaryTree(const CBinaryTree<T> &tree)
{

}

template<typename T>
void CBinaryTree<T>::add(T val, Node<T>* tree)
{
    if (val < tree->val)
    {
        if (nullptr != tree->left)
        {
            add(val, tree->left);
        }

        else
        {
            tree->left = new Node<T>;
            tree->left->val = val;

            tree->left->left = nullptr;
            tree->left->right = nullptr;
        }
    }

    else if (val >= tree->val)
    {
        if (nullptr != tree->right)
        {
            add(val, tree->right);
        }

        else
        {
            tree->right = new Node<T>;
            tree->right->val = val;

            tree->right->left = nullptr;
            tree->right->right = nullptr;
        }
    }
}

template<typename T>
void CBinaryTree<T>::add(T val)
{
    if (nullptr == m_root)
    {
        m_root = new Node<T>;
        m_root->val = val;

        m_root->left = nullptr;
        m_root->right = nullptr;
    }

    else
    {
        add(val, m_root);
    }
}


template<typename T>
void CBinaryTree<T>::show()
{
    showNode(m_root, 0);
}

template<typename T>
void CBinaryTree<T>::showNode(Node<T> *node, int depth)
{
    if (nullptr != node->left)
    {
        showNode(node->left, depth+1);
    }

    for (int i=0; i<depth; ++i)
    {
        std::cout<<"      ";
    }
    std::cout << node->val << "\n\n";

    if (nullptr != node->right)
    {
        showNode(node->right, depth+1);
    }
}

template<typename T>
Node<T> *CBinaryTree<T>::search(T val, Node<T> *node)
{
    if (nullptr != node)
    {
        if (val == node->val)
        {
            return node;
        }

        else if (val >= node->val)
        {
            return search(val, node->right);
        }

        else
        {
            return search(val, node->left);
        }
    }
}

template<typename T>
Node<T> *CBinaryTree<T>::search(T val)
{
    return search(val, m_root);
}

template<typename T>
void CBinaryTree<T>::clear(Node<T> *node)
{
    if (nullptr != node)
    {
        clear(node->left);
        clear(node->right);

        delete node;
    }
}

template<typename T>
CBinaryTree<T> &CBinaryTree<T>::operator=(const CBinaryTree<T> &tree)
{

}

template<typename T>
CBinaryTree<T>::~CBinaryTree()
{
    clear(m_root);
}
