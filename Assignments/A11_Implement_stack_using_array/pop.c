#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{	
	if(s->top == -1)        // If top is equal to -1 then return Failure
	   return FAILURE;
	
	(s->top)--;             // Decrement the top
	return SUCCESS;
}