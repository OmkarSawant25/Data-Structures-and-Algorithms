#include <stdio.h>
#include <stdlib.h>
#include "traffic.h"

int main()
{
    Queue *front = NULL;
    Queue *rear = NULL;
    char signal = 'R';
    int choice, car_num;

    printf("======================== 🚦 Traffic Signal Simulation 🚦 ========================\n\n");

    while (1)
    {
        printf("1. Change signal\n");
        printf("2. Add car\n");
        printf("3. Pass car\n");
        printf("4. Show waiting cars\n\n");
        // printf("Enter your choice: ");
        // scanf("%d", &choice);
        // printf("Current signal: %c\n\n", signal);
        if (signal == 'R')
            printf("Current signal : RED 🔴\n\n");
        else if (signal == 'Y')
            printf("Current signal : YELLOW 🟡\n\n");
        else
            printf("Current signal : GREEN 🟢\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            change_signal(&signal);
            if (signal == 'R')
                printf("Signal changes to RED 🔴\n\n");
            else if (signal == 'Y')
                printf("Signal changes to YELLOW 🟡\n\n");
            else
                printf("Signal changes to GREEN 🟢\n\n");
            break;

        case 2:
            printf("Enter car number: ");
            scanf("%d", &car_num);
            add_car(&front, &rear, car_num);
            break;

        case 3:
            pass_car(&front, &rear, signal);
            break;

        case 4:
            show_queue(front, rear);
            break;

        default:
            printf("Invalid choice\n\n");
        }
    }

    return 0;
}

void enqueue(Queue **front, Queue **rear, int car)
{
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode->data = car;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        newNode->next = *front;
        *rear = newNode;
    }

    printf("Car %d added to queue 🚗\n\n", car);
}

void dequeue(Queue **front, Queue **rear)
{
    if (*front == NULL)
    {
        printf("There are no cars available at the signal\n\n");
        return;
    }

    Queue *temp = *front;
    int removed_car = temp->data;

    if (*front == *rear)
    {
        *front = *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
        (*rear)->next = *front;
    }

    free(temp);
    printf("Car %d passed the signal\n\n", removed_car);
}

void show_queue(Queue *front, Queue *rear)
{
    if (front == NULL)
    {
        printf("INFO : Queue is Empty\n\n");
        return;
    }

    printf("Cars in the Signal are in the following order:\n");

    Queue *temp = front;
    int count = 1;

    do
    {
        printf("%d. %d\n", count++, temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

void change_signal(char *signal)
{
    if (*signal == 'R')
        *signal = 'Y';
    else if (*signal == 'Y')
        *signal = 'G';
    else
        *signal = 'R';
}

void add_car(Queue **front, Queue **rear, int car)
{
    enqueue(front, rear, car);
}

void pass_car(Queue **front, Queue **rear, char signal)
{
    if (*front == NULL)
    {
        printf("No cars to pass\n\n");
        return;
    }

    if (signal == 'G')
    {
        dequeue(front, rear);
    }
    else if (signal == 'Y')
    {
        printf("Yellow signal 🟡 — Cars must wait\n\n");
    }
    else
    {
        printf("Red signal 🔴 — Cars cannot pass\n\n");
    }
}
