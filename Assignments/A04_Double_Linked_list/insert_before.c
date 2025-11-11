/*
[#] insert_before

Input : head  → pointer to pointer of first node.
        tail  → pointer to pointer of last node.
        gdata → given data (should be present in the list).
        ndata → data to be inserted in the list before gdata.
        
Cases : List Empty
        List Non-Empty
        Given data present
        Given data not present
*/

#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if (*head == NULL && *tail == NULL)                 // if list is empty
        return LIST_EMPTY;

    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));    // create new node
    if (newNode == NULL)                                // check memory allocation
        return FAILURE;

    newNode->data = ndata;                              // assign data
    newNode->prev = NULL;
    newNode->next = NULL;

    if ((*head)->data == gdata)                         // if inserting before head
    {
        newNode->next = *head;                          // new node points to current head
        (*head)->prev = newNode;                        // current head points back to new node
        *head = newNode;                                // new node becomes the head
        return SUCCESS;
    }

    Dlist *temp = *head;                                // pointer to traverse list
    while (temp != NULL)
    {
        if (temp->data == gdata)                        // found the node before which to insert
        {
            newNode->next = temp;                       // connect new node to current node
            newNode->prev = temp->prev;                 // link new node’s prev to previous node
            temp->prev->next = newNode;                 // link previous node’s next to new node
            temp->prev = newNode;                       // current node’s prev points to new node
            return SUCCESS;                             // insertion successful
        }
        temp = temp->next;                              // move to next node
    }

    free(newNode);                                      // free memory if data not found
    return DATA_NOT_FOUND;                              // given data not found
}
