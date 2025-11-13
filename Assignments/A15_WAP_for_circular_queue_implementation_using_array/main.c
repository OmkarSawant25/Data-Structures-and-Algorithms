/*
Name        : Omkar Ashok Sawant
Date        : 13/11/2025
Program     : Queue Operations (Enqueue, Dequeue, Print)

Description : This program implements basic operations on a Queue data
              structure using an array. It demonstrates inserting and 
              deleting elements in FIFO (First In, First Out) order.

              Supported Operations:
                1) Enqueue(queue, data)
                     -> Insert new data at the rear end of the queue.

                2) Dequeue(queue)
                     -> Delete data from the front end of the queue.

                3) Print_queue(queue)
                     -> Display all elements from front to rear.

              The program allows the user to perform the above 
              operations interactively and prints the queue after
              each modification.

Input       : User choice and data values from standard input.
Output      : Updated Queue displayed after each operation.

*/

#include "queue.h"

int create_queue(Queue_t *q, int size)
{
    q->capacity = size;
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    q->Que = malloc(sizeof(int *) * size);
    if(q->Que == NULL)
        return FAILURE;
    return SUCCESS;
}

int main()
{
	Queue_t q;
	int size;
	printf("Enter the size of the queue : ");
	scanf("%d", &size);
	if (create_queue(&q, size) == FAILURE)
	{
	    printf("INFO : Queue not created\n");
	    return FAILURE;
	}

	char ch;
	int choice, data;
	printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");
	while (1)
	{
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&q, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 2:
				/* Function to dequeueue the queue */
				if (dequeue(&q) == FAILURE)
				{
					printf("INFO : Queue is empty\n");
				}
				else
				{
					printf("INFO : Dequeue successfull\n");
				}
				break;
			case 3:
				/* Function to print the queue */
				print_queue(q);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}