#include "stack.h"

int Pop(Stack_t **top)
{
    if(*top == NULL)        // If Top is NULL then the stack is empty so return failure
        return FAILURE;
        
    Stack_t *temp = *top;   // Take a temp structure variable and assign the top to it
    *top = (*top)->link;    // Update top with top of link
    free(temp);             // Free the temp
    return SUCCESS;
}