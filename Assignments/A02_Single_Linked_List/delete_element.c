/* Write a function to delete the given data in the single linked list. */

#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    if(*head == NULL)                    // if list is empty, nothing to delete
    {
        return FAILURE;
    }
    
    Slist *temp = *head;                 // pointer to scan the list
    Slist *prev = NULL;                  // pointer to track previous node
    
    while(temp != NULL)                  // loop through all nodes
    {
        if(temp->data == data)           // found the node to delete
        {
            if(prev == NULL)             // if node is the first (head)
            {
                *head = temp->link;      // move head to next node
                free(temp);              // free memory
            }
            else
            {
                prev->link = temp->link; // bypass the node to delete
                free(temp);              // free memory
            }
            return SUCCESS;              // deletion done
        }
        prev = temp;                     // move prev to current
        temp = temp->link;               // move to next node
    }
    return DATA_NOT_FOUND;               // data not found in list
}
