#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{
    if(head == NULL)                // If head is null then return list is empty
        return LIST_EMPTY;
    
    Slist *fast = head;             // Initialize the fast pointer with head
    Slist *slow = head;             // Initialize the slow pointer with head
    
    while(fast != NULL && fast->link != NULL) // traverse the fast until it reaches null
    {
        slow = slow->link;          // move the slow to the next
        fast = fast->link->link;    // move the fast for two times
    }
    
    *mid = slow->data;              // Update the mid with the data of slow
    return SUCCESS;
} 