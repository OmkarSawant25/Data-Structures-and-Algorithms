#ifndef LISTS_H
#define LISTS_H

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

#endif