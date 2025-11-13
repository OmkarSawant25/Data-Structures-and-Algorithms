#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    Stack_t *newNode = (Stack_t *)malloc(sizeof(Stack_t));
    
    if(newNode == NULL)         // If memory allocation Failed
        return FAILURE;
        
    newNode->data = data;       // Assign the data to the newNode
    newNode->link = *top;       // Update the link of newNode with previous head
    *top = newNode;             // Update the top with newNode
    return SUCCESS;
}