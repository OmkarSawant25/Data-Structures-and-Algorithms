#include "apc.h"

Status modules(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    /* check division by zero */
    if (division_by_zero(head2, tail2))
        return FAILURE;

    /* If dividend < divisor → remainder = dividend */
    if (comparelist(*head1, *head2) == FAILURE)
    {
        free_list(headR, tailR);
        copy_list(head1, tail1, headR, tailR);  // copy dividend as remainder
        return SUCCESS;
    }

    Dlist *remH = NULL, *remT = NULL;  // remainder
    Dlist *temp = *head1;              // MSB -> LSB

    while (temp)
    {
        /* bring down one digit */
        insert_at_last(&remH, &remT, temp->data);
        remove_leading_zero(&remH, &remT);

        /* subtract divisor repeatedly */
        while (remH && comparelist(remH, *head2) != FAILURE)
        {
            Dlist *resH = NULL, *resT = NULL;

            subtraction(&remH, &remT, head2, tail2, &resH, &resT);
            remove_leading_zero(&resH, &resT);

            free_list(&remH, &remT);

            remH = resH;
            remT = resT;
        }

        temp = temp->next;
    }

    /* final remainder is remH/remT */
    free_list(headR, tailR);
    *headR = remH;
    *tailR = remT;

    remove_leading_zero(headR, tailR);

    return SUCCESS;
}
