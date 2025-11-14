#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    if (*front == NULL)                // Queue empty
        return FAILURE;
     
    Queue_t *temp = *front;            // Node to delete

    if (*front == *rear)               // Only one element
    {
        free(temp);
        *front = NULL;
        *rear  = NULL;
        return SUCCESS;
    }
    
    *front = (*front)->link;           // Move front forward
    (*rear)->link = *front;            // Maintain circular link
    free(temp);                        // Free old front node

    return SUCCESS;
}
