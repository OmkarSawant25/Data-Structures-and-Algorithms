#include "main.h"

void swap(int a, int b, int *arr)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    int pivot = first;
    int p= first + 1;
    int q = last;
    
    while(p <= q)
    {
        while(arr[p] <= arr[pivot])
            p++;
        while(arr[q] > arr[pivot])
            q--;
        if(p < q)
            swap(p, q, arr);
    }
    swap(q, pivot, arr);
    return q;
}
