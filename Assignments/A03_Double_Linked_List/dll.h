/*
Name        : Omkar Ashok Sawant
Date        : 10/11/2025
Program     : Header File for Doubly Linked List (DLL)

Description : This header file defines the structure, macros, and 
              function prototypes required for performing operations 
              on a Doubly Linked List (DLL). All the implementation 
              files include this header for shared definitions.

Contents    :
              - Structure definition for Dlist
              - Macros for SUCCESS, FAILURE, and LIST_EMPTY
              - Function declarations for all DLL operations

*/

#ifndef DLL_H
#define DLL_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_delete_first(Dlist **head, Dlist **tail);
int dl_delete_last(Dlist **head, Dlist **tail);
int dl_delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
#endif