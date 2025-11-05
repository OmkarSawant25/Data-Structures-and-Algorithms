/*
5. delete_list

Input : head → pointer to first node

Cases : 1. List empty → Return LIST_EMPTY (in empty list node can’t be deleted)
        2. List not empty → Delete all nodes one by one.
        
NOTE : Should not update head directly with NULL without freeing the nodes.
*/

#include "sll.h"

/* Function to delete all nodes in the list */
int sl_delete_list(Slist **head)
{
    Slist *temp = *head;                      // Temporary pointer to traverse the list
    
    if(*head == NULL)                         // If the list is empty
    {
        return FAILURE;                       // Return failure (nothing to delete)
    }
    else
    {
        while(temp != NULL)                   // Traverse the entire list
        {
            temp = temp->link;                // Move temp to next node
            free(*head);                      // Free the current head node
            *head = temp;                     // Update head to the next node
        }
    }
    
    return SUCCESS;                           // Return success after deleting all nodes
}
