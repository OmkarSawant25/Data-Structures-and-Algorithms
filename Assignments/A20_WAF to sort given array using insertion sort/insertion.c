#include "main.h"

data_t insertion(data_t *arr, data_t size)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
    return 1;
}
