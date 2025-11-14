#ifndef MAZE_H
#define MAZE_H

// #include <stdio.h>

typedef struct node
{
    int row;
    int col;
}maze;

maze stack[100];
int top = -1;

void pop();
void push(int *row, int *col);
void do_operation(int *row, int *col, char arr[][*col], maze *m, char *a);
void Display(int *row, int *col, char arr[4][4]);

#endif