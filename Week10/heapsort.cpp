#include <iostream>

void heapSort(int* pArr, int size);
void buildHeap(int* pArr, int size);
void Sift(int* pArr, int pos, int size);
void siftRecursive(int* pArr, int pos, int size);

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

    heapSort(arr, size);

    print(arr, size);

	return 0;
}


void heapSort(int* pArr, int size)
{
    buildHeap(pArr, size);

    int end = size - 1;
    while(end > 0)
    {
        std::swap(pArr[0], pArr[end]);
        Sift(pArr, 0, end);
        --end;
    }
}

void buildHeap(int* pArr, int size)
{
    int start = size / 2;

    while(start >= 0)
    {
        Sift(pArr, start, size);
        --start;
    }
}

void Sift(int* pArr, int pos, int size)
{
    int elem = pArr[pos];

    int root = pos;
    int child = 2*pos + 1;
    while(child < size)
    {
        if(child + 1 < size && pArr[child] < pArr[child + 1])
            ++child;

        if(elem > pArr[child])
            break;
        else
        {
            pArr[root] = pArr[child];
            root = child;
            child = 2 * root + 1;
        }
    }
    pArr[root] = elem;
}


void siftRecursive(int* pArr, int pos, int size)
{
    int left = 2*pos + 1;
    int right = left + 1;
    int largest = pos;

    if(left< size && pArr[left] > pArr[largest])
        largest = left;

    if(right < size && pArr[right] > pArr[largest])
        largest = right;

    /// ако някое от децата е по-голямо
    if(largest != pos)
    {
        std::swap(pArr[pos], pArr[largest]);
        siftRecursive(pArr, largest, size);
    }
}
