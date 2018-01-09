#include <iostream>
#include "CRedBlackTree.hpp"

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

    tree.preOrderTraversal();
    cout<<"\n";
    tree.inOrderTraversal();
    cout<<"\n";
    tree.postOrderTraversal();
    cout<<"\n";

    cout<<tree.search('H');
    cout<<"\n"<<tree.getSize();
    return 0;
}
