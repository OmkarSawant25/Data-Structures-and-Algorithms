/*
3. delete_first :

Input   : head → pointer to the first node.

Cases   : 1. List empty → Return LIST_EMPTY (in empty list node can’t be deleted)
          2. List not empty → Update the head with next node address, delete the first node.
          
Example : head → 10 → 20 → 30 → 40 → 50 → NULL
          head → 20 → 30 → 40 → 50 → NULL
*/

#include "sll.h"

/* Function to delete the first node from the list */
int sl_delete_first(Slist **head)
{
    if(*head == NULL)                         // If the list is empty
    {
        return FAILURE;                       // Return failure (nothing to delete)
    }
    else
    {
        Slist *temp = *head;                  // Temporary pointer to store current head
        *head = temp->link;                   // Move head to the next node
        free(temp);                           // Delete the old first node
        return SUCCESS;                       // Return success after deletion
    }
}
