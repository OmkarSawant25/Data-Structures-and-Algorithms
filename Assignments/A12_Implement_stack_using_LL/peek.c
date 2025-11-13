#include "stack.h"

int Peek(Stack_t **top)
{
    if(*top == NULL)        // If top is NULL the stack is empty
        return FAILURE;
    
    return (*top)->data;    // Return the data of top most value
}