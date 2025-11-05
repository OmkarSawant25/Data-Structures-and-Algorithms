/*
2. Insert_at_last :

Input : head → pointer to first node
        data → data to be inserted at the end.
        
Cases : 1. List empty – Update the head with new node address.
        2. List not empty – Traverse to the last node and establish the link between last node and new node.
*/
#include "sll.h"

/* Function to insert a new node at the end of the list */
int insert_at_last(Slist **head, data_t data)
{
    Slist *newnode = malloc(sizeof(Slist));   // Allocate memory for new node
    
    if(newnode == NULL)                       // Check if memory allocation failed
        return FAILURE;
    
    newnode -> data = data;                   // Store data in new node
    newnode -> link = NULL;                   // Initialize link as NULL (last node)
    
    if(*head == NULL)                         // If list is empty
    {
        *head = newnode;                      // New node becomes head
    }
    else
    {
        Slist *temp = *head;                  // Create temp pointer for traversal
        while(temp -> link != NULL)           // Traverse till last node
        {
            temp = temp -> link;              // Move to next node
        }
        temp -> link = newnode;               // Link new node at the end
    }
    
    return SUCCESS;                           // Return success status
}
