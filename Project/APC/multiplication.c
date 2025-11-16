/*******************************************************************************************************************************************************************
*Title				: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype			: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
					: tail1: Pointer to the last node of the first double linked list.
					: head2: Pointer to the first node of the second double linked list.
					: tail2: Pointer to the last node of the second double linked list.
					: headR: Pointer to the first node of the resultant double linked list.
*Output				: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"

Status multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = *tail2;                     // pointer for number2 (LSB to MSB)

    int result, carry = 0, data, count = 0;

    while (temp2 != NULL)                      // pick each digit of number2
    {
        Dlist *temp1 = *tail1;                 // pointer for number1
        Dlist *headR1 = NULL;                  // partial result list
        Dlist *tailR1 = NULL;
        carry = 0;

        while (temp1 != NULL)                  // multiply digit by digit
        {
            result = temp1->data * temp2->data + carry;
            carry = result / 10;
            data = result % 10;

            insert_at_start(&headR1, &tailR1, data);
            temp1 = temp1->prev;
        }

        if (carry > 0)                         // insert remaining carry
        {
            insert_at_start(&headR1, &tailR1, carry);
        }

        for (int i = 0; i < count; i++)        // add zeros based on place value
        {
            insert_at_last(&headR1, &tailR1, 0);
        }

        if (*headR == NULL)                    // first partial result
        {
            *headR = headR1;
            *tailR = tailR1;
        }
        else
        {
            Dlist *headR2 = NULL;
            Dlist *tailR2 = NULL;

            addition(&headR1, &tailR1, headR, tailR, &headR2, &tailR2);   // add previous result

            free_list(headR, tailR);           // free old result
            free_list(&headR1, &tailR1);       // free partial list

            *headR = headR2;                   // update result
            *tailR = tailR2;
        }

        count++;                               // increase zero count
        temp2 = temp2->prev;                   // move to next digit
    }

    return SUCCESS;
}
