#include "queue.h"

/* Function to insert the element */
int enqueue(Queue_t *q, int data)
{
    if (IsQueueFull(q) == SUCCESS)          // Queue is full -> insertion not possible
        return FAILURE;

    if (q->rear == -1)                      // First insertion -> set front to 0
        q->front = 0;

    q->rear = (q->rear + 1) % q->capacity;  // Move rear forward circularly
    q->Que[q->rear] = data;                 // Insert the data at new rear position
    (q->count)++;                           // Increase number of elements

    return SUCCESS;                         // Successful insertion
}
