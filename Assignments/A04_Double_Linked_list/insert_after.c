/*
[#] insert_after

Input : head  → pointer to pointer of first node.
        tail  → pointer to pointer of last node.
        gdata → given data (should be present in the list).
        ndata → data to be inserted in the list after gdata.
        
Cases : List Empty
        List Non-Empty
        Given data present
        Given data not present
*/

#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if (*head == NULL && *tail == NULL)                 // if list is empty
        return LIST_EMPTY;

    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));    // create new node
    if (newNode == NULL)                                // check memory allocation
        return FAILURE;

    newNode->data = ndata;                              // assign new data
    newNode->prev = NULL;
    newNode->next = NULL;

    Dlist *temp = *head;                                // pointer to traverse list

    while (temp != NULL)                                // traverse until end
    {
        if (temp->data == gdata)                        // found given data
        {
            if (temp != *tail)                          // Case: inserting in middle
            {
                newNode->next = temp->next;              // connect new node’s next to current’s next
                newNode->prev = temp;                    // new node’s prev points to current
                temp->next->prev = newNode;              // next node’s prev updated to new node
                temp->next = newNode;                    // current’s next updated to new node
            }
            else                                         // Case: inserting after last node (tail)
            {
                temp->next = newNode;                    // connect last node to new node
                newNode->prev = temp;                    // link back from new node
                *tail = newNode;                         // update tail pointer
            }
            return SUCCESS;                              // insertion done
        }
        temp = temp->next;                              // move to next node
    }

    free(newNode);                                      // free memory if data not found
    return DATA_NOT_FOUND;                              // given data not found
}
