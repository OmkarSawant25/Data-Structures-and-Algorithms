#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    Queue_t *newNode = (Queue_t *)malloc(sizeof(Queue_t));
    if (newNode == NULL)              // Memory allocation failed
        return FAILURE;

    newNode->data = data;             // Store the data
    newNode->link = NULL;             // Will be updated for circular link

    if (*rear == NULL)                // Queue is empty
    {
        *front = newNode;             // First node becomes front
        *rear  = newNode;             // And also rear
        newNode->link = newNode;      // circular link to itself
    }
    else                              // Queue has elements
    {
        (*rear)->link = newNode;      // Link old rear to new node
        *rear = newNode;              // Update rear to new node
        newNode->link = *front;       // Maintain circular nature
    }
    
    return SUCCESS;                   // Successful insertion
}
