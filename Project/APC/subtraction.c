/*******************************************************************************************************************************************************************
*Title				: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype			: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
					: tail1: Pointer to the last node of the first double linked list.
					: head2: Pointer to the first node of the second double linked list.
					: tail2: Pointer to the last node of the second double linked list.
					: headR: Pointer to the first node of the resultant double linked list.
*Output				: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"

Status subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int diff = 0, borrow = 0;

    Dlist *temp1 = *tail1;                     // pointer for number1 (LSB to MSB)
    Dlist *temp2 = *tail2;                     // pointer for number2 (LSB to MSB)

    while (temp1 != NULL || temp2 != NULL)     // continue till all digits processed
    {
        int x = temp1 ? temp1->data : 0;       // take digit from list1, else 0
        int y = temp2 ? temp2->data : 0;       // take digit from list2, else 0

        x = x - borrow;                        // subtract previous borrow

        if (x < y)                             // need to borrow
        {
            diff = (x + 10) - y;               // adjust by adding 10
            borrow = 1;                        // borrow for next step
        }
        else
        {
            diff = x - y;                      // normal subtraction
            borrow = 0;
        }

        insert_at_start(headR, tailR, diff);   // insert result digit at start

        if (temp1) temp1 = temp1->prev;        // move pointers
        if (temp2) temp2 = temp2->prev;
    }

    remove_leading_zero(headR,tailR);                // remove unnecessary leading zeros

    return SUCCESS;
}
