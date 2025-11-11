/*
[#] delete_element

Input : head → pointer to pointer of first node.
        tail → pointer to pointer of last node.
        data → data to be deleted from the list.
        
Cases : List Empty
        List Non-Empty
        Given data present
        Given data not present
*/

#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{
    if (*head == NULL && *tail == NULL)                 // if list is empty
        return LIST_EMPTY;

    /* Case 1: Only one node in the list */
    if (*head == *tail && (*head)->data == data)
    {
        free(*head);                                    // free single node
        *head = NULL;                                   // reset head
        *tail = NULL;                                   // reset tail
        return SUCCESS;
    }

    /* Case 2: Data found at the head node */
    if ((*head)->data == data)
    {
        Dlist *temp = *head;                            // store head temporarily
        *head = (*head)->next;                          // move head to next node
        (*head)->prev = NULL;                           // remove back link
        free(temp);                                     // free old head
        return SUCCESS;
    }

    /* Case 3: Traverse to find the node to delete */
    Dlist *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == data)                         // found the data
        {
            if (temp->next != NULL)                     // Case: middle node
            {
                temp->prev->next = temp->next;           // link previous to next
                temp->next->prev = temp->prev;           // link next back to previous
            }
            else                                         // Case: last node (tail)
            {
                temp->prev->next = NULL;                 // set prev’s next to NULL
                *tail = temp->prev;                      // update tail pointer
            }

            free(temp);                                 // free deleted node
            return SUCCESS;                             // deletion successful
        }
        temp = temp->next;                              // move to next node
    }

    /* Case 4: Given data not found */
    return DATA_NOT_FOUND;
}
