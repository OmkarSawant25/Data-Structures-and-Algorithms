/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Delete Last Node (DLL)

Description : This file implements the function to delete the last 
              node of a Doubly Linked List (DLL). The function ensures 
              proper link updates and memory deallocation for the last node.

Cases Handled :
              - Empty list     -> Return LIST_EMPTY
              - Single node    -> Set head and tail to NULL
              - Multiple nodes -> Update tail to previous node
*/

#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
    if (*tail == NULL)                      // If list is empty
        return FAILURE;                     // Nothing to delete, return failure
    
    if (*head == *tail)                     // If list has only one node
    {
        free(*tail);                        // Free the only node
        *head = NULL;                       // Set head to NULL
        *tail = NULL;                       // Set tail to NULL
    }
    else                                    // If list has more than one node
    {
        Dlist *temp = *tail;                // Store current last node in temp
        (*tail)->prev->next = NULL;         // Disconnect last node from list
        *tail = (*tail)->prev;              // Move tail pointer to previous node
        free(temp);                         // Free the old last node
    }

    return SUCCESS;                         // Deletion successful
}
