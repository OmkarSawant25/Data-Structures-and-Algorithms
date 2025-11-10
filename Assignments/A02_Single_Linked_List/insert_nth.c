/* Write a function to insert the given data exactly at the ‘n’ position in the single linked list.*/

#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    if(n <= 0)                          // Invalid position
        return POSITION_NOT_FOUND;
    
    Slist *newNode = (Slist *)malloc(sizeof(Slist));   // Allocate new node
    
    if (newNode == NULL)                // Check memory allocation
        return FAILURE;

    newNode->data = data;               // Store data
    newNode->link = NULL;               // Initialize link
    
    if(*head == NULL && n > 1)          // Empty list but position >1 → not possible
        return LIST_EMPTY;
    
    if (n == 1)                         // Insert at beginning (head)
    {
        newNode->link = *head;          // Point new node to current head
        *head = newNode;                // Update head
        return SUCCESS;
    }
    
    int count = 1;                      // Node counter
    Slist *temp = *head;                // Pointer to traverse list
    
    while(temp != NULL && count < n - 1) // Traverse to (n-1)th node
    {
        temp = temp->link;
        count++;
    }
    
    if(temp == NULL)                    // If position is out of range
    {
        free(newNode);                  // Free allocated memory
        return POSITION_NOT_FOUND;
    }
    
    newNode->link = temp->link;         // Link new node to next node
    temp->link = newNode;               // Link previous node to new node
    
    return SUCCESS;                     // Insertion successful
}
