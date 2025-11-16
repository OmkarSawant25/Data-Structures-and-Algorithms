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

Status division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	if (divisor(head2, tail1))
		return FAILURE;

	if (comparelist(*head1, *head2) == FAILURE)
	{
		insert_at_start(headR, tailR, 0);
		return SUCCESS;
	}
}

int divisor(Dlist **head, Dlist **tail)
{
	if (*head == *tail && (*head)->data == 0)
		return 1;
	else
		return 0;
}
