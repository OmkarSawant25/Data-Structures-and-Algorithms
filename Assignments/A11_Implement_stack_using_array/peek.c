#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{
    if(s->top == -1)     // If our stack is empty then return FAILURE
        return FAILURE;
    
    return s->stack[s->top];    // return the top element
}