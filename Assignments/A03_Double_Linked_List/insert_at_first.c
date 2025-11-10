/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Insert Node at Beginning (DLL)

Description : This file implements the function to insert a new node 
              at the beginning of a Doubly Linked List (DLL). The 
              function correctly updates both head and tail pointers 
              based on whether the list is empty or not.

Cases Handled :
              - Empty list  -> head = newNode, tail = newNode
              - Non-empty   -> newNode becomes the new head
*/

#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));   // Create new node (allocate memory)

    if (newNode == NULL)                               // If memory allocation fails
        return FAILURE;

    newNode->prev = NULL;                              // For first node, prev = NULL
    newNode->data = data;                              // Store given data
    newNode->next = NULL;                              // Next will be set if list not empty

    if (*head == NULL && *tail == NULL)                // If list is empty
    {
        *head = newNode;                               // New node becomes head
        *tail = newNode;                               // New node becomes tail
    }
    else                                               // If list already has nodes
    {
        newNode->next = *head;                         // New node’s next points to current head
        (*head)->prev = newNode;                       // Current head’s prev points back to new node
        *head = newNode;                               // Update head to new node
    }

    return SUCCESS;                                    // Insertion successful
}
