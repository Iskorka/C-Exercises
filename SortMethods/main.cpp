#include <iostream>
#include "CSort.hpp"

#include "windows.h"

using namespace std;
int arr[5] = {1,2,6,2,5};

int main()
{
    cout<<"bubble sort : ";
    CSort<int>::bubbleSortAscending(arr, 5);

    cout<<endl<<"shuffle: ";
    CSort<int>::shuffle(arr, 5);

    cout<<endl<<"insertion sort: ";
    CSort<int>::insertionSortAscending(arr, 5);

    cout<<endl<<"shuffle: ";
    CSort<int>::shuffle(arr, 5);

    cout<<endl<<"shell sort: ";
    CSort<int>::shellSort(arr, 5);

    cout<<endl<<"shuffle: ";
    CSort<int>::shuffle(arr, 5);

    cout<<endl<<"comb sort: ";
    CSort<int>::combSort(arr, 5);

    cout<<endl;

    return 0;
}
