#include "queue.h"

/* Function to check whether the queue is full */
int IsQueueFull(Queue_t *q)
{
    if (q->count == q->capacity)     // If count equals capacity -> queue is full
        return SUCCESS;
    return FAILURE;                  // Otherwise, queue is not full
}

/* Function to check whether the queue is empty */
int IsQueueEmpty(Queue_t *q)
{
    if (q->count == 0)               // If count is zero -> queue is empty
        return SUCCESS;
    return FAILURE;                  // Otherwise, queue has elements
}
