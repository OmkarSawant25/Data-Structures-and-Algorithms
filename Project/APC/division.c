/*******************************************************************************************************************************************************************
 Title               : Division
 Description         : This function performs division of two given large numbers and stores the quotient in the resultant list.
 Prototype           : int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 Input Parameters    : head1 : Pointer to the first node of the dividend list
					 : tail1 : Pointer to the last  node of the dividend list
					 : head2 : Pointer to the first node of the divisor list
					 : tail2 : Pointer to the last  node of the divisor list
					 : headR : Pointer to the first node of the quotient list
 Output              : Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"

Status division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* check division by zero */
	if (division_by_zero(head2, tail2))
		return FAILURE;

	/* if dividend < divisor, quotient = 0 */
	if (comparelist(*head1, *head2) == FAILURE)
	{
		insert_at_last(headR, tailR, 0);
		return SUCCESS;
	}

	Dlist *remH = NULL, *remT = NULL; // remainder list
	Dlist *temp = *head1;			  // pointer to dividend (MSB -> LSB)

	while (temp)
	{
		insert_at_last(&remH, &remT, temp->data); // bring down next digit
		remove_leading_zero(&remH, &remT);		  // clean leading zero

		int qdigit = 0; // quotient digit (0–9)

		/* subtract divisor repeatedly */
		while (comparelist(remH, *head2) != FAILURE) // run until the remH becomes less than head2
		{
			Dlist *resH = NULL, *resT = NULL; // for storing the result

			subtraction(&remH, &remT, head2, tail2, &resH, &resT); // rem = rem - divisor
			remove_leading_zero(&resH, &resT);

			remH = resH; // update remainder with the results
			remT = resT; // update remainder with the results

			qdigit++; // increase quotient digit
		}

		insert_at_last(headR, tailR, qdigit); // store quotient digit
		temp = temp->next;					  // move to next digit
	}

	remove_leading_zero(headR, tailR); // clean final result zero
	return SUCCESS;
}

// #include "apc.h"

// Status division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
// {
// 	/* 1. Check division by zero */
// 	if (divisor(head2, tail2))
// 		return FAILURE;

// 	/* 2. If dividend < divisor -> quotient = 0 */
// 	if (comparelist(*head1, *head2) == FAILURE)
// 	{
// 		insert_at_start(headR, tailR, 0);
// 		return SUCCESS;
// 	}

// 	Dlist *newH = NULL;
// 	Dlist *newT = NULL;

// 	copy_list(&newH, &newT, tail1);

// 	Dlist *headR1 = NULL;
// 	Dlist *tailR1 = NULL;
// 	unsigned long int count = 0;

// 	while (comparelist(newH, *head2) != FAILURE)
// 	{
// 		subtraction(&newH, &newT, head2, tail2, &headR1, &tailR1);
// 		remove_leading_zero(&headR1, &tailR1);

// 		newH = headR1;
// 		newT = tailR1;

// 		headR1 = NULL;
// 		tailR1 = NULL;

// 		count++;
// 	}
// 	if (count == 0)
// 	{
// 		insert_at_start(headR, tailR, 0);
// 	}
// 	else
// 	{
// 		while(count > 0)
// 		{
// 			insert_at_start(headR, tailR, count % 10);
// 			count /= 10;
// 		}
// 	}

// 	return SUCCESS;
// }
