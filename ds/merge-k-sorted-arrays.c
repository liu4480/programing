// Last Update:2018-02-27 14:09:42
/**
 * @file merge-k-sorted-arrays.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <iostream>
#include <limits.h>
using namespace std;

struct MinHeapNode
{
    int element;
    int i;
    int j;
};

void swap(MinHeapNode *x, MinHeapNode *y);

class MinHeap
{
    MinHeapNode *harr;
    int heap_size;
public:
    MinHeap(MinHeapNode a[], int size);

    void MinHeapify(int);

    int left(int i) { return (2 * i + 1);}

    int right(int i) { return (2 * i + 2);}

    MinHeapNode getMin() { return harr[0]; }

    void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};

int *mergeKArrays(int *arr[], int k, int n)
{
    int *output = new int[n * k], i, count;

    MinHeapNode *harr = new MinHeapNode[k];
    for(i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    MinHeap hp(harr, k);

    for(count = 0; count < n*k; count++)
    {
        MinHeapNode root = hp.getMin();
        output[count] = root.element;

        if(root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        else
            root.element = INT_MAX;
        hp.replaceMin(root);
    }
    return output;
}

MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while(i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if(r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if(smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode tmp = *x;
    *x = *y;
    *y = tmp;
}

void printArray(int arr[], int size)
{
    for(int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int **arr = new int*[3];
    for(int i=0; i < 3; i++)
        arr[i] = new int[4];
    arr = {2, 6, 12, 34, 1, 9, 20, 1000, 23, 34, 90, 2000};
    //arr = {{2, 6, 12, 34},
    //       {1, 9, 20, 1000},
    //       {23, 34, 90, 2000}};

    int *output = mergeKArrays(arr, 3, 4);
    cout << "Merged array is " << endl;
    printArray(output, 4 * 3);

    return 0;
}
