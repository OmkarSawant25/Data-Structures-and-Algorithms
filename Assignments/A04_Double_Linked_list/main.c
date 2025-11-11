/*
Name        : Omkar Ashok Sawant
Date        : 11/11/2025
Program     : Additional Doubly Linked List (DLL) Operations

Description : This program implements additional operations on a
              Doubly Linked List (DLL). It demonstrates insertion 
              and deletion functionalities based on given data or 
              position within the list.

              Supported Operations:
                1) dl_insert_after()
                     -> Insert new data after a given data value.

                2) dl_insert_before()
                     -> Insert new data before a given data value.

                3) dl_delete_element()
                     -> Delete a node containing the given data.

              The program allows the user to perform the above 
              operations interactively and displays the list 
              after each modification.

Input       : User choice and data values from standard input.
Output      : Updated Doubly Linked List displayed after operations.

Return Codes:
                SUCCESS             -> Operation completed successfully
                FAILURE             -> Operation failed
                LIST_EMPTY          -> List is empty
                DATA_NOT_FOUND      -> Given data not found in the list
                POSITION_NOT_FOUND  -> Invalid position (if applicable)
*/


#include "dll.h"

int main()
{
	int option, data, gdata, ret;


	Dlist *head = NULL; /* initialize the header to NULL */
	Dlist *tail = NULL; /* initialize the tail to NULL */

	printf("1. Insert first\n2. Insert before\n3. Insert after\n4. Delete element\n5. Print list\n6. Exit\nEnter your choice : ");
	while(1)
	{

		/*ask user options*/
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				/* To insert the element at last */
				printf("Enter the data you have to insert : ");
				scanf("%d", &data);

				/* If the return value is 0 link sucess else not success */
				if (dl_insert_last(&head, &tail, data) == -1)
				{
					printf("INFO : Insert last Failure\n");
				}
				break;
			case 2:
				/* To insert the element before a number present in the list */
				printf("Enter the gdata : ");
				scanf("%d", &gdata); /* Scaning the number */
				printf("Enter the number you have insert before %d : ", gdata);

				/* Scaning the new number to insert */
				scanf("%d", &data);

				/* If the link is Success it retuns 0 else it returns -1 */
				if ((ret = dl_insert_before(&head, &tail, gdata, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Insert before Successfull\n" );
				}
				break;
			case 3:
				/* To insert the element after the number present in the list */
				printf("Enter the gdata : ");
				scanf("%d", &gdata);/* Scaning the existing number */
				printf("Enter the number you have to insert after %d : ", gdata);

				/* Scaning the new number to insert */
				scanf("%d", &data); 

				/* If the link is Success it will return 0 else it will return -1 */
				if ((ret = dl_insert_after(&head, &tail, gdata, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Insert after Successfull\n" );
				}
				break;
			case 4:
				/* To delete the element present in the list */
				printf("Enter the element you have to delete : ");
				scanf("%d", &data); /* Scaning the number to delete */

				/* If the delete is completed it will return 0 else it will return -1 */
				if ((ret = dl_delete_element(&head, &tail, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Delete element Successfull\n" );
				}
				break;
			case 5:
				/* Calling the function to print the list */
				print_list(head);
				break;
			case 6:
				return SUCCESS;

			default: printf("Enter proper choice !!\n");
					 break;
		}

	}

	return SUCCESS;
}