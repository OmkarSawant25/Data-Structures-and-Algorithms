#ifndef APC_H
#define APC_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

typedef enum
{
	FAILURE = 0,
	SUCCESS
} Status;

/* Include the prototypes here */
Status validate_input_arguments(int argc,char *argv[]);
Status valid_operator(char *op);
Status valid_number(char *nums);

Status string_to_list(Dlist **head, Dlist **tail, char *num);
Status insert_at_start(Dlist **head, Dlist **tail, int data);
Dlist *create_new_node(int data);

void print_list(const char *msg, Dlist *head);

Status addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

void remove_leading_zero(Dlist **head);
Status comparelist(Dlist *head1, Dlist *head2);
int length(Dlist *head);
Status subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

#endif
