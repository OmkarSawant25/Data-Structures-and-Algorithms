#include "Lists.h"
#include <stdio.h>

int main()
{
	
	int option, data, key;

	Slist *head = NULL; //initialize the header to NULL
	printf("1. Insert last\n2. Insert After\n3. Print list\n4. Exit\n");
	while (1)
	{
		/*ask user options*/
		printf("Enter your choice : ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				printf("Enter the number that you want to insert at last: ");
				scanf("%d", &data);
				/*insert_at_last function call*/
				if (insert_at_last(&head, data) == FAILURE) //pass by reference
				{
					printf("INFO : Insertion Failure\n");
				}
				break;

            case 2:
                int g_data, n_data;
                printf("Enter the g_data & n_data: ");
                scanf("%d%d", &g_data, &n_data);
                if((insert_after(&head,g_data, n_data)) == SUCCESS)
                {
                    printf("Successfully added the data\n");
                }
                else
                {
					printf("INFO : Insertion Failure\n");
                }
			
			case 3:
				/* print list function call*/
				print_list(head);
					break;
	
			case 4:
				return SUCCESS;
			default: printf("Enter proper choice !!\n");
			
					 break;
		}
	    

	}
}

