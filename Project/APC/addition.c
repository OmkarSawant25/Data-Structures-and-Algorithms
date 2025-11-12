/*******************************************************************************************************************************************************************
 Title				: Addition
 Description		: This function performs addition of two given large numbers and store the result in the resultant list.
 Prototype			: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 Input Parameters	: head1: Pointer to the first node of the first double linked list.
					: tail1: Pointer to the last node of the first double linked list.
					: head2: Pointer to the first node of the second double linked list.
					: tail2: Pointer to the last node of the second double linked list.
					: headR: Pointer to the first node of the resultant double linked list.
 Output				: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

Status addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */

	int sum = 0, carry = 0, data = 0;

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	while(temp1 != NULL || temp2 != NULL || carry != 0)
	{
		int x = temp1 ? temp1->data : 0;
		int y = temp2 ? temp2->data : 0; 

		sum = x + y + carry;
		carry = sum / 10;
		data = sum % 10;

		insert_at_start(headR, tailR, data);

		if(temp1)
			temp1 = temp1->prev;
		if(temp2)
			temp2 = temp2->prev;
	}
	return SUCCESS;
}
