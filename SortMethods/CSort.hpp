#ifndef CSORT_HPP
#define CSORT_HPP

#include "random"
#include "ctime"

template
<typename T>
class CSort
{
public:
    CSort();

    static void bubbleSortAscending(T *array, const int &size);
    static void bubbleSortDescending(T *array, const int &size);

    static void insertionSortAscending(T *array, const int &size);
    static void insertionSortDescending(T *array, const int &size);

    static void combSort(T* array, const int &size);

    static void shellSort(T* array, const int &size);

    static void shuffle(T* array, const int &size);

private:
    CSort(const CSort& sort);
    CSort& operator=(const CSort& sort);
};

#endif // CSORT_HPP



template<typename T>
void CSort<T>::bubbleSortAscending(T* array, const int &size)
{
    if (1 == size)
    {
        return;
    }

    else
    {
        for (int i=0; i<size; ++i)
        {
            for (int j=i; j>0; --j)
            {
                if (array[j]>array[j+1])
                {
                    std::swap(array[j], array[j+1]);
                }
            }
        }

        for (int i=0; i<size; ++i)
        {
            std::cout<<array[i]<<' ';
        }
    }
}



template<typename T>
void CSort<T>::bubbleSortDescending(T *array, const int &size)
{
    if (1 == size)
    {
        return;
    }

    else

    {
        for (int i=size-1; i>0; --i)
        {
            for (int j=0; j<i; ++j)
            {
                if (array[j]<array[j+1])
                {
                    std::swap(array[j], array[j+1]);
                }
            }
        }

        for (int i=0; i<size; ++i)
        {
            std::cout<<array[i]<<' ';
        }
    }
}



template<typename T>
void CSort<T>::insertionSortAscending(T* array, const int &size)
{
    if (1 == size)
    {
        return;
    }

    else
    {
        T temp;
        int i, j;

        for ( i=0; i < size; i++)
        {
            temp = array[i];

            for ( j=i-1; j>=0 && array[j] > temp; j--)
            {
                array[j+1] = array[j];
            }

            array[j+1] = temp;
        }
    }

    for (int i=0; i<size; ++i)
    {
        std::cout<<array[i]<<' ';
    }
}

template<typename T>
void CSort<T>::combSort(T *array, const int &size)
{
    if (1 == size)
    {
        return;
    }

    else
    {
        double stepChange = 1.3;
        double step = size-1;

        while (step>=1)
        {
            for (int i=0; i+step < size; ++i)
            {
                if (array[i]>array[static_cast<int>(i+step)])
                {
                    std::swap(array[i], array[static_cast<int>(i+step)]);
                }
            }

            step /= stepChange;
        }

        bubbleSortAscending(array, size);
    }
}


template<typename T>
void CSort<T>::shellSort(T *array, const int &size)
{
    int i, j, k;
    T temp;

    for (k=size/2; k>0; k/=2)
    {
        for (i=k; i<size; ++i)
        {
            temp = array[i];
            for (j=i; j>=k; j-=k)
            {
                if (temp < array[j-k])
                {
                    array[j] = array[j-k];
                }

                else
                {
                    break;
                }
            }
            array[j] = temp;
        }
    }


    for (int i=0; i<size; ++i)
    {
        std::cout<<array[i]<<' ';
    }
}

template<typename T>
void CSort<T>::shuffle(T *array, const int &size)
{
    srand(time(0));

    for (int i=0; i<size; ++i)
    {
        std::swap(array[i], array[rand() % size]);
    }


    for (int i=0; i<5; ++i)
    {
        std::cout<<array[i]<<' ';
    }
}
