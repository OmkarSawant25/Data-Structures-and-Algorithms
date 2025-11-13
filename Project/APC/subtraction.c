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
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while (temp1 != NULL || temp2 != NULL)
    {
        int x = temp1 ? temp1->data : 0;
        int y = temp2 ? temp2->data : 0;

        x = x - borrow;

        if (x < y)
        {
            diff = (x + 10) - y;
            borrow = 1;
        }
        else
        {
            diff = x - y;
            borrow = 0;
        }

        insert_at_start(headR, tailR, diff);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    // Remove leading zeros
    // while ((*headR)->data == 0 && (*headR)->next != NULL)
    // {
    //     Dlist *temp = *headR;
    //     *headR = (*headR)->next;
    //     (*headR)->prev = NULL;
    //     free(temp);
    // }
    
    remove_leading_zero(headR);
    return SUCCESS;
}
