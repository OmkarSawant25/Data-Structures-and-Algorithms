/*
1. insert_at_first :

Input : head → pointer to first node.
        data → data to be inserted.

Read data from user and insert the given data in first position.

Cases : List empty, data = 10
        head = NULL , 
        After inserting data into list, list contains
        10 → NULL
        
        List not empty, data 40
        10 → 20 → 30 → NULL, 
        After inserting 40 into list
        40 → 10 → 20 → 30 → NULL
*/

#include "sll.h"

/* Function to insert a new node at the beginning of the list */
int insert_at_first(Slist **head, data_t data)
{
    Slist *newNode = (Slist *)malloc(sizeof(Slist));   // Allocate memory for new node
    
    if(newNode == NULL)                                // Check for memory allocation failure
        return FAILURE;
    
    newNode->data = data;                              // Store data in new node
    newNode->link = NULL;                              // Initialize link as NULL
    
    if(*head == NULL)                                  // If list is empty
    {
        *head = newNode;                               // New node becomes the head
    }
    else
    {
        newNode->link = *head;                         // Point new node to current head
        *head = newNode;                               // Update head to new node
    }
    
    return SUCCESS;                                    // Return success status
}
