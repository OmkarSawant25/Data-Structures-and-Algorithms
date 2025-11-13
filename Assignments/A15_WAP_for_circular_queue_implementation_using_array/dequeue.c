#include "queue.h"

/* Function to dequeue the element */
int dequeue(Queue_t *q)
{
    if (IsQueueEmpty(q) == SUCCESS)         // Queue empty -> deletion not possible
        return FAILURE;

    q->front = (q->front + 1) % q->capacity; // Move front forward circularly
    (q->count)--;                            // Reduce number of elements

    return SUCCESS;                          // Successful deletion
}
