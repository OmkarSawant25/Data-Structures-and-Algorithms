#include "main.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

data_t selection(data_t *arr, data_t size )
{
    for(int i = 0; i < size - 1; i++)
    {
        int idx = i;
        int small = arr[i];
        for(int j = i + 1; j < size; j++)
        {
            if(small > arr[j])
            {
                small = arr[j];
                idx = j;
            }
        }
        if(small != arr[i])
        {
            swap(&arr[idx],&arr[i]);
        }
    }
}
