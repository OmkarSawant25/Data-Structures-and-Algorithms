/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Print Doubly Linked List (DLL)

Description : This file implements the function to traverse and print 
              all nodes of a Doubly Linked List (DLL) from head to tail. 
              It displays data elements and helps verify list operations.

Cases Handled :
              - Empty list  -> Display "List is empty"
              - Non-empty   -> Print all node values in sequence
*/

#include "dll.h"

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}