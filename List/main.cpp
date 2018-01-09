#include <iostream>
#include <clist.h>

using namespace std;

int main()
{
    CList<int> l;

    for (int i=0; i<6; ++i)
    {
        l.add(i);
    }

    CIterator<int> iter = l.begin();
    CIterator<int> iter2 = l.end();

    cout<<*(iter+2);


    return 0;
}
