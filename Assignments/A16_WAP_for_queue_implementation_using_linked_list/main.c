/*
Name        : Omkar Ashok Sawant
Date        : 14/11/2025
Program     : Queue Operations using Linked List (Enqueue, Dequeue, Print)

Description : This program implements basic Queue operations using a 
              singly linked list. The Queue follows the FIFO 
              (First In, First Out) principle.

              Supported Operations:
                1) Enqueue(front, rear, data)
                     -> Insert a new node at the rear end of the queue.
                     -> If the queue is empty, both front and rear are
                        updated to the new node.

                2) Dequeue(front, rear)
                     -> Delete a node from the front end of the queue.
                     -> If the queue becomes empty after deletion,
                        front and rear are set to NULL.

                3) Print_queue(front)
                     -> Display all nodes from front to rear.

              The functions operate on dynamically allocated nodes to
              demonstrate linked-list-based Queue implementation.

Input       : Function arguments (front pointer, rear pointer, data).
Output      : Updated Queue displayed after each operation.
*/


#include "queue.h"

int main()
{
	Queue_t *front = NULL, *rear = NULL;

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
				if (enqueue(&front, &rear, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 2:
				/* Function to dequeueue the queue */
				if (dequeue(&front, &rear) == FAILURE)
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
				print_queue(front, rear);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}