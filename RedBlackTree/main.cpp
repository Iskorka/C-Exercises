#include <iostream>
#include "credblacktree.h"

using namespace std;

int main()
{
    CRedBlackTree<char> tree;

    tree.insert('S');
    tree.insert('E');
    tree.insert('A');
    tree.insert('R');
    tree.insert('C');
    tree.insert('H');
    tree.insert('X');
    tree.insert('M');
    tree.insert('P');
    tree.insert('L');

    tree.show();

    cout<<endl<<endl<<"Pre Order Traversal: ";

    tree.preOrderTraversal();

    cout<<endl<<"In Order Traversal: ";

    tree.inOrderTraversal();

    cout<<endl<<"Post Order Traversal: ";

    tree.postOrderTraversal();

    cout<<endl<<endl;

    tree.deleteLeaf('P');

    cout<<endl<<endl;
    tree.show();

    return 0;
}
