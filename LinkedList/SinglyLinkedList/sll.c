#include "Lists.h"

Status insert_at_last(Slist **head, int data)
{
    Slist *newNode = (Slist *)malloc(sizeof(Slist));
    if(newNode == NULL)
    {
        return FAILURE;
    }
    newNode->data = data;
    newNode->link = NULL;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Slist *temp = *head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    return SUCCESS;
}

void print_list(Slist *head)
{
    if(head == NULL)
    {
        printf("Error: Contains No elements\n");
    }
    else
    {
        while(head != NULL)
        {
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("NULL\n");
    }
}

Status insert_after(Slist **head, int g_data, int n_data)
{
    if (*head == NULL)
    {
        printf("List empty\n");
        return;
    }
    
    Slist *temp = *head;
    while(temp != NULL)
    {
        if(temp->data == g_data)
        {
            Slist *newNode = (Slist *) malloc(sizeof(Slist));
            newNode->data = n_data;
            newNode->link = temp->link;
            temp->link = newNode;
            return SUCCESS;
        }
        temp = temp->link; 
    }
    return FAILURE;
}