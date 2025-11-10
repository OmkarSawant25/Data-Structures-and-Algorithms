/*
2. insert_before

Input : head → pointer to first node.
        gdata → given data (should be present in the list).
        ndata → data to be inserted in the list before gdata.
        
Cases : List Empty
        List Non-Empty
        Given data present
        Given data not present
*/

#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    if(*head == NULL)                         // if list is empty
        return LIST_EMPTY;

    Slist *temp = *head;                      // pointer to move through list
    Slist *prev = NULL;                       // pointer to track previous node
    
    while(temp != NULL)                       // go through the list
    {
        if(temp->data == g_data)              // found the node before which we have to insert
        {
            Slist *new = (Slist *) malloc(sizeof(Slist));   // create new node
            if(new == NULL)                   // check memory allocation
                return FAILURE;

            new->data = ndata;                // put new data
            new->link = temp;                 // new node points to current node
            
            if(prev == NULL)                  // if inserting before head
            {
                *head = new;                  // new node becomes head
            }
            else
            {
                prev->link = new;             // connect previous node to new node
            }
            return SUCCESS;                   // insertion done
        }
        prev = temp;                          // move prev to current
        temp = temp->link;                    // move to next node
    }

    return DATA_NOT_FOUND;                    // if g_data not found in list
}
