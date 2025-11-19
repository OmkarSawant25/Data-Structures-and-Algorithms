#include "main.h"

data_t bubble(data_t *arr, int size )
{
    for(data_t i = 0; i < size - 1; i++)
    {
        for(data_t j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 1;
}
