/*
1. insert_after :

Input : head → pointer to first node.
        gdata → given data (should be present in the list).
        ndata → data to be inserted in the list after gdata.
        
Cases : List Empty
        List Non-Empty
        Given data present
        Given data not present
*/

#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t n_data)
{
    if(*head == NULL)                 // if list is empty, nothing to insert after
        return LIST_EMPTY;
        
    Slist *temp = *head;              // start from the first node
    while(temp != NULL)
    {
        if(temp->data == g_data)      // check if current node has the given data
        {
            Slist *newNode = (Slist *) malloc (sizeof(Slist));   // create new node
            newNode->data = n_data;   // store new data in new node
            newNode->link = temp->link;   // link new node to next node
            temp->link = newNode;     // link current node to new node
            return SUCCESS;           // insertion successful
        }
        temp = temp->link;            // move to next node
    }
    return DATA_NOT_FOUND;            // given data not found in list
}
