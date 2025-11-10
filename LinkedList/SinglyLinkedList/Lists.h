#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Lists
{
    int data;
    struct Lists *link;
}Slist;

typedef enum
{
    FAILURE,
    SUCCESS
}Status;

Status insert_at_last(Slist **head, int data);
void print_list(Slist *head);
Status insert_after(Slist **head, int g_data, int n_data);


#endif