#include "sll.h"

/* Function to print all elements of the linked list */
void print_list(Slist *head)
{
	if (head == NULL)                          // Check if list is empty
	{
		printf("INFO : List is empty\n");      // Print message if no nodes
	}
    else
    {
	    while (head)                           // Traverse through each node
	    {
		    printf("%d -> ", head->data);      // Print data of current node
		    head = head->link;                 // Move to next node
	    }

	    printf("NULL\n");                      // Indicate end of the list
    }
}
