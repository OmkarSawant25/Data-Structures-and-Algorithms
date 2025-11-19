#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    Slist *temp = *head;
    Slist *prev = NULL;
    
    while(temp->link != NULL)
    {
        if(temp->data == data)
        {
            prev = temp;
        }
        temp = temp->link;
    }
    
    if(temp->data == data)
    {
        prev = temp;
    }
    
    if(prev == NULL)
        return DATA_NOT_FOUND;
        
    temp->link = prev;
    return SUCCESS;
}