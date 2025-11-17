/*******************************************************************************************************************************************************************
*Title				: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype			: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
					: tail1: Pointer to the last node of the first double linked list.
					: head2: Pointer to the first node of the second double linked list.
					: tail2: Pointer to the last node of the second double linked list.
					: headR: Pointer to the first node of the resultant double linked list.
*Output				: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"

int divisor(Dlist **head, Dlist **tail)
{
	if (*head == *tail && (*head)->data == 0)
		return 1;
	else
		return 0;
}
Status division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* 1. Check division by zero */
	if (divisor(head2, tail2))
		return FAILURE;

	/* 2. If dividend < divisor -> quotient = 0 */
	if (comparelist(*head1, *head2) == FAILURE)
	{
		insert_at_start(headR, tailR, 0);
		return SUCCESS;
	}

	Dlist *newH = NULL;
	Dlist *newT = NULL;

	copy_list(&newH, &newT, tail1);

	Dlist *headR1 = NULL;
	Dlist *tailR1 = NULL;
	unsigned long int count = 0;

	while (comparelist(newH, *head2) != FAILURE)
	{
		subtraction(&newH, &newT, head2, tail2, &headR1, &tailR1);
		remove_leading_zero(&headR1, &tailR1);

		newH = headR1;
		newT = tailR1;

		headR1 = NULL;
		tailR1 = NULL;

		count++;
	}
	if (count == 0)
	{
		insert_at_start(headR, tailR, 0);
	}
	else
	{
		while(count > 0)
		{
			insert_at_start(headR, tailR, count % 10);
			count /= 10;
		}
	}

	return SUCCESS;
}
