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
    int sum = 0, carry = 0, data = 0;

    Dlist *temp1 = *tail1;                     // pointer for number1 (LSB to MSB)
    Dlist *temp2 = *tail2;                     // pointer for number2 (LSB to MSB)

    while (temp1 != NULL || temp2 != NULL || carry != 0)      // continue while digits/carry remain
    {
        int x = (temp1) ? temp1->data : 0;     // take digit from list1, else 0
        int y = (temp2) ? temp2->data : 0;     // take digit from list2, else 0

        sum = x + y + carry;                   // add digits + carry
        carry = sum / 10;                      // update carry
        data = sum % 10;                       // extract unit digit

        insert_at_start(headR, tailR, data);   // insert at start

        if (temp1)                             
            temp1 = temp1->prev;               // move to previous digit in list1

        if (temp2)
            temp2 = temp2->prev;               // move to previous digit in list2
    }

    return SUCCESS;
}

