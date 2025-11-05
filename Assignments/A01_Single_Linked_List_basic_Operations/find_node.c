/*
6. find_node

Inputs : head → pointer to first node.
         data → data to be found in the list.
Cases  : List empty
         List not empty
            1. Data found
            2. Data not found
            
        1. List empty → Return LIST_EMPTY (in empty list can’t search data)
        2. List not empty
              1. Traverse through the list to search the data
              2. If data found return DATA_FOUND
        3. Else return DATA_NOT_FOUND
*/

#include "sll.h"

/* Function to find a node containing given data in the list */
int find_node(Slist *head, data_t data)
{
    int count = 1;                             // Counter to track node position
    
    if(head == NULL)                           // If the list is empty
    {
        return FAILURE;                        // Return failure (nothing to search)
    }
    else
    {
        while(head != NULL)                    // Traverse through the list
        {
            if(head->data == data)              // If data is found
            {
                return count;                   // Return position where data is found
            }
            count++;                            // Move to next node position
            head = head->link;                  // Go to next node
        }
    }
    
    return FAILURE;                             // Return failure if data not found
}
