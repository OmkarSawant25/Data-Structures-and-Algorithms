#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
    if(head == NULL)                // if head is null return list is empty
        return LIST_EMPTY;
    
    if(pos == 0)
        return FAILURE;

    Slist *fast = head;             // initialize the fast with head
    Slist *slow = head;             // initialize the slow with head
    
    int count = 1;                  // declare count as 1
    while(fast != NULL)             // Run the loop until fast reaches NULL
    {
        if(count <= pos)            // if count is less than or equal to position then move the fast pointer only
        {
            fast = fast->link;
        }
        else                        // else move both the pointers
        {
            fast = fast->link;      
            slow = slow->link;
        }
        count++;                    // Increase the count
    }
    if(count > pos)                 // If count is greater than position the return the data
    {
        *data = slow->data;
        return SUCCESS;
    }
    else                            // else position not found
        return FAILURE;
} 