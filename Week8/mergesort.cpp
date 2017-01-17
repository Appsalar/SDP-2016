
#include <iostream>
void mergeSort(int* arr, int size);
void mergeSortStep(int* arr, int size, int* buff);
void merge(int* a, int sizeA, int* b, int sizeB, int* buff);
 
 
void mergeSort(int* arr, int size)
{
    if(!arr || size == 0)
        return;
 
    int* buf = new int[size];
 
    mergeSortStep(arr, size, buf);
    delete[] buf;
}
 
void merge(int* a, int sizeA, int* b, int sizeB, int* buff)
{
    int i = 0;
    int ia = 0;
    int ib = 0;
 
    while(ia < sizeA && ib < sizeB)
    {
        if(a[ia] < b[ib])
        {
            buff[i] = a[ia];
            ++ia;
        }
        else
        {
            buff[i] = b[ib];
            ++ib;
        }
        ++i;
    }
 
    while(ia < sizeA)
    {
        buff[i] = a[ia];
        ++i;
        ++ia;
    }
 
    while(ib < sizeB)
    {
        buff[i] = b[ib];
        ++i;
        ++ib;
    }
}
 
void mergeSortStep(int* arr, int size, int* buff)
{
    if(size == 1 )
        return;
 
    int middle = size/2;
 
    mergeSortStep(arr, middle, buff);
    mergeSortStep(arr + middle, size - middle, buff);
 
    merge(arr, middle, arr + middle, size - middle, buff);
 
    for(int i = 0; i < size ; ++i)
        arr[i] = buff[i];
}
 
 
 
inline void print(int* p, int size)
{
    for(int i = 0; i < size; ++i)
        std::cout<< p[i] << " ";
    std::cout << std::endl;
}
 
int main()
{
    int arr[] = {3 , 5 ,1 ,2 ,7 ,21 , 12 ,45, 30 ,10};
    int size = sizeof(arr)/sizeof(int);
 
    print(arr, size);
 
    mergeSort(arr, size);
 
    print(arr, size);
 
    return 0;
}
