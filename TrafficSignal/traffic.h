#ifndef TRAFFIC_H
#define TRAFFIC_H

typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

void enqueue(Queue **front, Queue **rear, int car);
void dequeue(Queue **front, Queue **rear);
void show_queue(Queue *front, Queue *rear);

void change_signal(char *signal);
void add_car(Queue **front, Queue **rear, int car);
void pass_car(Queue **front, Queue **rear, char signal);

#endif
