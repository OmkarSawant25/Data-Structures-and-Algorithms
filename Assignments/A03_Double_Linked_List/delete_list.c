/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Delete Entire Doubly Linked List (DLL)

Description : This file implements the function to delete all nodes 
              of a Doubly Linked List (DLL) one by one, freeing 
              allocated memory and resetting head and tail pointers 
              to NULL after deletion.

Cases Handled :
              - Empty list  -> Return LIST_EMPTY
              - Non-empty   -> Delete nodes sequentially and clear pointers
*/

#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;                 // Temporary pointer to traverse the list
    
    if (*head == NULL)                   // If list is empty
        return FAILURE;                  // Nothing to delete, return failure
    
    else
    {
        while (temp != NULL)             // Traverse until end of list
        {
            // temp = (*head)->next;
            temp = temp->next;           // Move to next node
            free(*head);                 // Free current head node
            *head = temp;                // Update head to next node
        }
        
        *tail = NULL;                    // Set tail to NULL after deletion
        *head = NULL;                    // Set head to NULL after deletion
    }
    
    return SUCCESS;                      // Deletion successful
}
