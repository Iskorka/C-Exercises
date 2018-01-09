#include <iostream>
#include "cbinarytree.h"
using namespace std;

int main()
{
    CBinaryTree<int> tree;


    tree.add(4);
    tree.add(7);
    tree.add(3);
    tree.add(2);
    tree.add(18);
    tree.add(17);
    tree.add(19);
    tree.add(21);
    tree.add(20);

    tree.show();

    tree.clear(3);

    tree.show();

    //cout << tree.search(7)->val << endl;;

    return 0;
}
