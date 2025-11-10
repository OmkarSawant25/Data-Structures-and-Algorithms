/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Delete First Node (DLL)

Description : This file implements the function to delete the first 
              node of a Doubly Linked List (DLL). The function ensures 
              proper memory deallocation and updates the head pointer.

Cases Handled :
              - Empty list     -> Return LIST_EMPTY
              - Single node    -> Set head and tail to NULL
              - Multiple nodes -> Update head to next node
*/

#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    // If list is empty, nothing to delete
    if (*head == NULL)                   
        return FAILURE;

    // If there is only one node
    if (*head == *tail)                  
    {
        free(*head);        // delete that single node
        *head = NULL;       // head becomes empty
        *tail = NULL;       // tail becomes empty
    }
    else
    {
        Dlist *temp = *head;    // store current head
        *head = temp->next;     // move head to next node
        (*head)->prev = NULL;   // new head has no previous link
        free(temp);             // free old head node
    }
    return SUCCESS;             // deletion successful
}
