#ifndef CREDBLACKTREE_H
#define CREDBLACKTREE_H

#include "nconstants.h"
#include <iostream>

template
<typename T>
class CRedBlackTree
{
public:
    CRedBlackTree();
    ~CRedBlackTree();

    /* TODO: copy method and copy constructor */
    CRedBlackTree(const CRedBlackTree& tree);

    void insert(T value);

    void deleteLeaf(const T &value);

    void clear();

    void show();

    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();


private:
    NConstants::sNode<T>* m_root;

    NConstants::sNode<T>* getGrandparent(NConstants::sNode<T>* node);
    NConstants::sNode<T>* getUncle(NConstants::sNode<T>* node);
    NConstants::sNode<T>* getSibling(NConstants::sNode<T>* node);

    void rotateLeft(NConstants::sNode<T>* node);
    void rotateRight(NConstants::sNode<T>* node);

    void insert(NConstants::sNode<T>* tree, T value);

    void insertFixup(NConstants::sNode<T>* tree);
    void insertCaseOne(NConstants::sNode<T>* node);
    void insertCaseTwo(NConstants::sNode<T>* node);
    void insertCaseThree(NConstants::sNode<T>* node);
    void insertCaseFour(NConstants::sNode<T>* node);
    void insertCaseFive(NConstants::sNode<T>* node);

    void replaceNode(NConstants::sNode<T>* node, NConstants::sNode<T>* child);

    void deleteLeaf(NConstants::sNode<T>* node, const T &value);

    void deleteCaseOne(NConstants::sNode<T>* node);
    void deleteCaseTwo(NConstants::sNode<T>* node);
    void deleteCaseThree(NConstants::sNode<T>* node);
    void deleteCaseFour(NConstants::sNode<T>* node);
    void deleteCaseFive(NConstants::sNode<T>* node);
    void deleteCaseSix(NConstants::sNode<T>* node);

    void clear(NConstants::sNode<T>* node);

    void inOrderTraversal(NConstants::sNode<T>* node);
    void preOrderTraversal(NConstants::sNode<T>* node);
    void postOrderTraversal(NConstants::sNode<T>* node);

    void show(NConstants::sNode<T>* node, const int &depth);
};

#endif // CREDBLACKTREE_H

template<typename T>
CRedBlackTree<T>::CRedBlackTree() : m_root(nullptr)
{

}



template<typename T>
CRedBlackTree<T>::~CRedBlackTree()
{
    clear();
}



template<typename T>
NConstants::sNode<T> *CRedBlackTree<T>::getGrandparent(NConstants::sNode<T> *node)
{
    if (nullptr != node && nullptr != node->m_parent)
    {
        return node->m_parent->m_parent;
    }

    return nullptr;
}



template<typename T>
NConstants::sNode<T> *CRedBlackTree<T>::getUncle(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* grandparent = getGrandparent(node);
    if (nullptr == grandparent)
    {
        return nullptr;
    }

    else if (node->m_parent == grandparent->m_left)
    {
        return grandparent->m_right;
    }

    else
    {
        return grandparent->m_left;
    }
}



template<typename T>
NConstants::sNode<T> *CRedBlackTree<T>::getSibling(NConstants::sNode<T> *node)
{
    if (node == node->m_parent->m_left)
    {
        return node->m_parent->m_right;
    }

    else
    {
        return node->m_parent->m_right;
    }
}



template<typename T>
void CRedBlackTree<T>::insert(NConstants::sNode<T> *node, T value)
{
    if (value < node->m_value)
    {
        if (nullptr != node->m_left)
        {
            insert(node->m_left, value);
        }

        else
        {
            node->m_left = new NConstants::sNode<T>;
            node->m_left->m_value = value;

            node->m_left->m_left = nullptr;
            node->m_left->m_right = nullptr;
            node->m_left->m_parent = node;

            node->m_left->m_color = NConstants::RED;

            insertFixup(node->m_left);
        }
    }

    else if (value >= node->m_value)
    {
        if (nullptr != node->m_right)
        {
            insert(node->m_right, value);
        }

        else
        {
            node->m_right = new NConstants::sNode<T>;
            node->m_right->m_value = value;

            node->m_right->m_left = nullptr;
            node->m_right->m_right = nullptr;
            node->m_right->m_parent = node;

            node->m_right->m_color = NConstants::RED;

            insertFixup(node->m_right);
        }
    }

}



template<typename T>
void CRedBlackTree<T>::insert(T value)
{
    if (nullptr == m_root)
    {
        m_root = new NConstants::sNode<T>;
        m_root->m_value = value;
        m_root->m_color = NConstants::RED;

        insertFixup(m_root);
    }

    else
    {
        insert(m_root, value);

        insertFixup(m_root);
    }
}



template<typename T>
void CRedBlackTree<T>::deleteLeaf(const T &value)
{
    deleteLeaf(m_root, value);
}



template<typename T>
void CRedBlackTree<T>::clear()
{
    clear(m_root);
}



template<typename T>
void CRedBlackTree<T>::rotateLeft(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* pivot = node->m_right;

    pivot->m_parent = node->m_parent;

    if (nullptr != node->m_parent)
    {
        if (node->m_parent->m_left == node)
        {
            node->m_parent->m_left = pivot;
        }

        else
        {
            node->m_parent->m_right = pivot;
        }
    }

    node->m_right = pivot->m_left;
    if (nullptr != pivot->m_left)
    {
        pivot->m_left->m_parent = node;
    }

    node->m_parent = pivot;
    pivot->m_left = node;

    if (nullptr == pivot->m_parent)
    {
        m_root = pivot;
    }
}



template<typename T>
void CRedBlackTree<T>::rotateRight(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* pivot = node->m_left;

    pivot->m_parent = node->m_parent;

    if (nullptr != node->m_parent)
    {
        if (node->m_parent->m_left == node)
        {
            node->m_parent->m_left = pivot;
        }

        else
        {
            node->m_parent->m_right = pivot;
        }
    }

    node->m_left = pivot->m_right;
    if (nullptr != pivot->m_right)
    {
        pivot->m_right->m_parent = node;
    }

    node->m_parent = pivot;
    pivot->m_right = node;

    if (nullptr == pivot->m_parent)
    {
        m_root = pivot;
    }
}



template<typename T>
void CRedBlackTree<T>::insertFixup(NConstants::sNode<T> *tree)
{
    insertCaseOne(tree);
}



template<typename T>
void CRedBlackTree<T>::insertCaseOne(NConstants::sNode<T> *node)
{
    if (nullptr == node->m_parent)
    {
        node->m_color = NConstants::BLACK;
    }

    else
    {
        insertCaseTwo(node);
    }
}



template<typename T>
void CRedBlackTree<T>::insertCaseTwo(NConstants::sNode<T> *node)
{
    if (NConstants::BLACK != node->m_parent->m_color)
    {
        insertCaseThree(node);
    }

    return;
}



template<typename T>
void CRedBlackTree<T>::insertCaseThree(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* uncle = getUncle(node);

    if (nullptr != uncle && NConstants::RED == uncle->m_color)
    {
        node->m_parent->m_color = NConstants::BLACK;
        uncle->m_color = NConstants::BLACK;
        NConstants::sNode<T>* grandparent = getGrandparent(node);
        grandparent->m_color = NConstants::RED;

        insertCaseOne(grandparent);
    }

    else
    {
        insertCaseFour(node);
    }
}



template<typename T>
void CRedBlackTree<T>::insertCaseFour(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* grandparent = getGrandparent(node);

    if (node == node->m_parent->m_right && node->m_parent == grandparent->m_left)
    {
        rotateLeft(node->m_parent);

        node = node->m_left;
    }

    else if (node == node->m_parent->m_left && node->m_parent == grandparent->m_right)
    {
        rotateRight(node->m_parent);

        node = node->m_right;
    }

    insertCaseFive(node);
}



template<typename T>
void CRedBlackTree<T>::insertCaseFive(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* grandparent = getGrandparent(node);

    node->m_parent->m_color = NConstants::BLACK;
    grandparent->m_color = NConstants::RED;

    if (node == node->m_parent->m_left && node->m_parent == grandparent->m_left)
    {
        rotateRight(grandparent);
    }

    else
    {
        rotateLeft(grandparent);
    }
}



template<typename T>
void CRedBlackTree<T>::replaceNode(NConstants::sNode<T>* node, NConstants::sNode<T>* child)
{
    child->m_parent = node->m_parent;

    if (child == node->m_left)
    {
        child->m_left = node;
        child->m_right = node->m_right;
    }

    else
    {
        child->m_right = node;
        child->m_left = node->m_left;
    }

    node->m_parent = child;
}



template<typename T>
void CRedBlackTree<T>::deleteLeaf(NConstants::sNode<T> *node, const T &value)
{
    if (nullptr != node)
    {
        if (value == node->m_value)
        {
            NConstants::sNode<T>* child = (nullptr != node->m_right ? node->m_left : node->m_right);

            if (nullptr == child)
            {
                deleteCaseOne(node);
            }

            else
            {
                replaceNode(node, child);
                if (NConstants::BLACK == node->m_color)
                {
                    if (NConstants::RED == child->m_color)
                    {
                        child->m_color = NConstants::BLACK;
                    }

                    else
                    {
                        deleteCaseOne(child);
                    }
                }
            }



            if (node->m_parent->m_left == node)
            {
                node->m_parent->m_left = nullptr;
            }
            else
            {
                node->m_parent->m_right = nullptr;
            }

            delete node;


        }

        else if (value < node->m_value)
        {
            deleteLeaf(node->m_left, value);
        }

        else
        {
            deleteLeaf(node->m_right, value);
        }
    }
}



template<typename T>
void CRedBlackTree<T>::deleteCaseOne(NConstants::sNode<T> *node)
{
    if (nullptr != node->m_parent)
    {
        deleteCaseTwo(node);
    }
}



template<typename T>
void CRedBlackTree<T>::deleteCaseTwo(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* sibling = getSibling(node);

    if (sibling->m_color == NConstants::RED)
    {
        node->m_parent->m_color = NConstants::RED;
        sibling->m_color = NConstants::BLACK;

        if (node == node->m_parent->m_left)
        {
            rotateLeft(node->m_parent);
        }

        else
        {
            rotateRight(node->m_parent);
        }
    }

    deleteCaseThree(node);
}



template<typename T>
void CRedBlackTree<T>::deleteCaseThree(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* sibling = getSibling(node);

    if (NConstants::BLACK == node->m_parent->m_color &&
        NConstants::BLACK == sibling->m_color &&
        NConstants::BLACK == sibling->m_left->m_color &&
        NConstants::BLACK == sibling->m_right->m_color)
    {
        sibling->m_color = NConstants::RED;
        deleteCaseOne(node->m_parent);
    }

    else
    {
        deleteCaseFour(node);
    }
}



template<typename T>
void CRedBlackTree<T>::deleteCaseFour(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* sibling = getSibling(node);

    if (nullptr == sibling->m_left)
    {
        deleteCaseFive(node);
    }

    else if (NConstants::RED == node->m_parent->m_color &&
        NConstants::BLACK == node->m_color &&
        NConstants::BLACK == sibling->m_color &&
        NConstants::BLACK == sibling->m_left->m_color &&
        NConstants::BLACK == sibling->m_right->m_color)
    {
        sibling->m_color = NConstants::RED;
        node->m_parent->m_color = NConstants::BLACK;
    }

    else
    {
        deleteCaseFive(node);
    }
}



template<typename T>
void CRedBlackTree<T>::deleteCaseFive(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* sibling = getSibling(node);

    if (NConstants::BLACK == sibling->m_color)
    {
        if (node == node->m_parent->m_left
            && NConstants::BLACK == sibling->m_right->m_color
            && NConstants::RED == sibling->m_left->m_color)
        {
            sibling->m_color = NConstants::RED;
            sibling->m_left->m_color = NConstants::BLACK;
            rotateRight(sibling);
        }

        else if (node == node->m_parent->m_right
                 && NConstants::BLACK == sibling->m_left->m_color
                 && NConstants::RED == sibling->m_right->m_color)
        {
            sibling->m_color = NConstants::RED;
            sibling->m_right->m_color = NConstants::BLACK;
            rotateLeft(sibling);
        }
    }

    deleteCaseSix(node);
}



template<typename T>
void CRedBlackTree<T>::deleteCaseSix(NConstants::sNode<T> *node)
{
    NConstants::sNode<T>* sibling = getSibling(node);

    sibling->m_color = node->m_parent->m_color;
    node->m_parent->m_color = NConstants::BLACK;

    if (node == node->m_parent->m_left)
    {
        sibling->m_right->m_color = NConstants::BLACK;
        rotateLeft(node->m_parent);
    }

    else
    {
        sibling->m_left->m_color = NConstants::BLACK;
        rotateRight(node->m_parent);
    }
}



template<typename T>
void CRedBlackTree<T>::show()
{
    if (nullptr == m_root)
    {
        std::cout<<"Nothing to show";
        return;
    }
    show(m_root, 0);
}



template<typename T>
void CRedBlackTree<T>::show(NConstants::sNode<T> *node, const int &depth)
{
    if (nullptr != node->m_left)
    {
        show(node->m_left, depth+1);
    }

    for (int i=0; i<depth; ++i)
    {
        std::cout<<"    ";
    }
    std::cout << node->m_value << "\n\n";

    if (nullptr != node->m_right)
    {
        show(node->m_right, depth+1);
    }


}



template<typename T>
void CRedBlackTree<T>::preOrderTraversal()
{
    preOrderTraversal(m_root);
}



template<typename T>
void CRedBlackTree<T>::inOrderTraversal()
{
    inOrderTraversal(m_root);
}



template<typename T>
void CRedBlackTree<T>::postOrderTraversal()
{
    postOrderTraversal(m_root);
}



template<typename T>
void CRedBlackTree<T>::clear(NConstants::sNode<T>* node)
{

    if (nullptr != node)
    {
        clear(node->m_right);
        node->m_right = nullptr;

        clear(node->m_left);
        node->m_left = nullptr;

        delete node;
    }
}



template<typename T>
void CRedBlackTree<T>::preOrderTraversal(NConstants::sNode<T> *node)
{
    std::cout<<node->m_value;

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
void CRedBlackTree<T>::inOrderTraversal(NConstants::sNode<T> *node)
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
void CRedBlackTree<T>::postOrderTraversal(NConstants::sNode<T> *node)
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
