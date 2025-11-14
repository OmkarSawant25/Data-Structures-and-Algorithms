#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
	if(s->top == (s->capacity - 1))        // If top is equal to capacity - 1 then return Failure as Stack is full
	    return FAILURE;
	
	(s->top)++;                            // Increment the top value
	s->stack[s->top] = element;            // Insert the element in stack
	return SUCCESS;                        // Return SUCCESS
}