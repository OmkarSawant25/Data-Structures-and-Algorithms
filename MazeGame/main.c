#include <stdio.h>
#include "maze.h"

void Display(int *row, int *col, char arr[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == *row && j == *col)
                printf("* ");
            else
                printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("w->up  s->down  a->left  d->right  b->back\n\n");
}

void do_operation(int *row, int *col, char arr[4][4], maze *m, char *a)
{
    char ch = *a;

    if (ch == 'w' || ch == 'W')
    {
        if (*row == 0)
        {
            printf("Operation not valid\n");
            return;
        }
        (*row)--;
    }
    else if (ch == 's' || ch == 'S')
    {
        if (*row == 3)
        {
            printf("Operation not valid\n");
            return;
        }
        (*row)++;
    }
    else if (ch == 'a' || ch == 'A')
    {
        if (*col == 0)
        {
            printf("Operation not valid\n");
            return;
        }
        (*col)--;
    }
    else if (ch == 'd' || ch == 'D')
    {
        if (*col == 3)
        {
            printf("Operation not valid\n");
            return;
        }
        (*col)++;
    }

    if (arr[*row][*col] == '0')
        printf("Use Backward as the this path is Blocked\n");
}

void push(int *row, int *col)
{
    top++;
    stack[top].row = *row;
    stack[top].col = *col;
}

void pop()
{
    if (top >= 0)
        top--;
}

int main()
{
    char arr[4][4] =
    {
        {'S','1','0','1'},
        {'0','1','0','E'},
        {'0','1','0','1'},
        {'1','1','1','1'}
    };

    int row = 0, col = 0;
    char ch;

    do
    {
        push(&row, &col);

        Display(&row, &col, arr);
        scanf(" %c", &ch);

        if (ch == 'b' || ch == 'B')
        {
            pop();
            if (top >= 0)
            {
                row = stack[top].row;
                col = stack[top].col;
            }
            continue;
        }

        do_operation(&row, &col, arr, stack, &ch);

    } while (arr[row][col] != 'E');

    printf("🎉 Congratulations 🍾👏\n📍 You reached your destination\n");
    return 0;
}
