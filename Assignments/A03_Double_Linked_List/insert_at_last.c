/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Insert Node at End (DLL)

Description : This file implements the function to insert a new node 
              at the end of a Doubly Linked List (DLL). The function 
              links the new node to the previous tail and updates 
              the tail pointer accordingly.

Cases Handled :
              - Empty list  -> head = newNode, tail = newNode
              - Non-empty   -> newNode added after current tail
*/

#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));  // Create new node (take memory)
    
    if(newNode == NULL)         // If memory not available, return failure
        return FAILURE;
    
    newNode->prev = NULL;       // Set previous pointer to NULL for now
    newNode->data = data;       // Store the given data
    newNode->next = NULL;       // New node will be last, so next = NULL
    
    if(*head == NULL && *tail == NULL)  // If list is empty
    {
        *head = newNode;        // New node becomes head
        *tail = newNode;        // New node becomes tail
    }
    else
    {
        newNode->prev = *tail;      // Link new node back to old tail
        (*tail)->next = newNode;    // Old tail’s next now points to new node
        *tail = newNode;            // Update tail to new node
    }
    return SUCCESS;                 // Insertion successful
}
