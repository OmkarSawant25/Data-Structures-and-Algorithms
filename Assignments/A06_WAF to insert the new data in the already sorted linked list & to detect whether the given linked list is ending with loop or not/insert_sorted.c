#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{
    Slist *newNode = (Slist *)malloc(sizeof(Slist));
    newNode->data = data;
    newNode->link = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return SUCCESS;
    }
    else
    {
        Slist *temp = *head;
        Slist *prev = NULL;
        while(temp->link != NULL)
        {
            if(data < temp->data)
            {
                if(temp == *head)
                {
                    newNode->link = *head;
                    *head = newNode;
                }
                else
                {
                    newNode->link = prev->link;
                    prev->link = newNode;
                }
                return SUCCESS;
            }
            prev = temp;
            temp = temp->link;
        }
        if(data < temp->data)
        {
            if(prev == NULL)
            {
                newNode->link = temp;
                *head = newNode;
            }
            else
            {
                newNode->link = prev->link;
                prev->link = newNode;
            }
        }
        else
        {
            temp->link = newNode;
        }
        return SUCCESS;
    }
    return FAILURE;
} 