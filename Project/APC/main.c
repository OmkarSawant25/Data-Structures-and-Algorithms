/**************************************************************************************************************************************************************
 *Title			: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "apc.h"

int main(int argc, char *argv[])
{
	if (validate_input_arguments(argc, argv) == FAILURE)
	{
		printf("Error : Invalid Input Arguments !\n");
		return FAILURE;
	}

	/* Declare the pointers */
	Dlist *head1 = NULL;
	Dlist *tail1 = NULL;
	Dlist *head2 = NULL;
	Dlist *tail2 = NULL;
	Dlist *headR = NULL;
	Dlist *tailR = NULL;

	char option;

	if (string_to_list(&head1, &tail1, argv[1]) == FAILURE || string_to_list(&head2, &tail2, argv[3]) == FAILURE)
	{
		printf("Error : Conversion to list failed!\n");
		return FAILURE;
	}
	char operator = argv[2][0];

	switch (operator)
	{
	case '+':
	{
		/* call the function to perform the addition operation */
		if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
		{
			printf("Error : Addition Operation Failed\n");
			return FAILURE;
		}
		break;
	}
	case '-':
	{
		/* call the function to perform the subtraction operation */

		remove_leading_zero(&head1);
		remove_leading_zero(&head2);
		
		if (comparelist(head1, head2) == FAILURE)
		{
			if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == FAILURE)
			{
				printf("Error : Subtraction Operation Failed\n");
				return FAILURE;
			}
			headR->data = -(headR->data);
		}
		else
		{
			if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
			{
				printf("Error : Subtraction Operation Failed\n");
				return FAILURE;
			}
		}

		break;
	}

	case '*':
		/* call the function to perform the multiplication operation */
		break;
	case '/':
		/* call the function to perform the division operation */
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
	}

	print_list("Number 1: ", head1);
	print_list("Number 2: ", head2);
	print_list("Result  : ", headR);

	return 0;
}
