#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

/* Doubly Linked List Node */
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

/* Status codes */
typedef enum
{
	FAILURE = 0,
	SUCCESS
} Status;

/* Validation functions */
Status validate_input_arguments(int argc, char *argv[]);
Status valid_operator(char *op);
Status valid_number(char *nums);

/* DLL creation and conversion */
Status string_to_list(Dlist **head, Dlist **tail, char *num);
Status insert_at_start(Dlist **head, Dlist **tail, int data);
Dlist *create_new_node(int data);

/* Display */
void print_list(const char *msg, Dlist *head);

/* Arithmetic operations */
Status addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
Status subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
Status multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
Status division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Various Operations */
void remove_leading_zero(Dlist **head);
Status comparelist(Dlist *head1, Dlist *head2);
int length(Dlist *head);

void free_list(Dlist **head, Dlist **tail);
void insert_at_last(Dlist **head, Dlist **tail, int data);
int divisor(Dlist **head, Dlist **tail);

#endif
