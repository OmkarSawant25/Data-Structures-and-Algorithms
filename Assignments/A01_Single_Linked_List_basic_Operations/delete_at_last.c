/*
4. delete_last

Input : head → pointer to first node
Cases : 1. List empty → Return LIST_EMPTY (in empty list node can’t be deleted)
        2. List not empty → Traverse to the last node, update the previous node address and delete the last node.
*/

#include "sll.h"

/* Function to delete the last node from the list */
int sl_delete_last(Slist **head)
{
    Slist *temp = *head;                      // Create a temporary pointer to traverse the list
    
    if(*head == NULL)                         // If the list is empty
    {
        return FAILURE;                       // Return failure (nothing to delete)
    }
    
    if(temp->link == NULL)                    // If there is only one node
    {
        free(*head);                          // Free that single node
        *head = NULL;                         // Make head NULL (list becomes empty)
        return SUCCESS;                       // Return success
    }
    else
    {
        Slist *prev;                          // Pointer to keep track of previous node
        
        while(temp->link != NULL)             // Traverse to the last node
        {
            prev = temp;                      // Store current node as previous
            temp = temp->link;                // Move to next node
        }
        
        free(temp);                           // Delete the last node
        prev->link = NULL;                    // Set second last node’s link to NULL
        return SUCCESS;                       // Return success after deletion
    }
}
