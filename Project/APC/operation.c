#include "apc.h"

Status valid_number(char *nums)
{
    for (int i = 0; nums[i] != '\0'; i++)
    {
        if (nums[i] < '0' || nums[i] > '9')
            return FAILURE;
    }
    return SUCCESS;
}

Status valid_operator(char *op)
{
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
    {
        return SUCCESS;
    }
    return FAILURE;
}

Status validate_input_arguments(int argc, char *argv[])
{
    if (argc != 4)
        return FAILURE;

    if (valid_number(argv[1]) == FAILURE)
    {
        printf("Error : Invalid Number -> %s\n", argv[1]);
        return FAILURE;
    }
    if (valid_operator(argv[2]) == FAILURE)
    {
        printf("Error : Invalid Operator -> %s\n", argv[2]);
        return FAILURE;
    }
    if (valid_number(argv[3]) == FAILURE)
    {
        printf("Error : Invalid Number -> %s\n", argv[3]);
        return FAILURE;
    }
    return SUCCESS;
}

Dlist *create_new_node(int data)
{
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
    if (newNode == NULL)
        return NULL;

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Status insert_at_start(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = create_new_node(data);
    if (newNode == NULL)
        return FAILURE;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    return SUCCESS;
}

Status string_to_list(Dlist **head, Dlist **tail, char *num)
{
    int len = strlen(num) - 1;
    for (int i = len; i >= 0; i--)
    {
        int data = num[i] - '0';
        if (insert_at_start(head, tail, data) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

void print_list(const char *msg, Dlist *head)
{
    printf("%s", msg);
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}


int length(Dlist *head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

Status comparelist(Dlist *head1, Dlist *head2)
{
    int x = length(head1);
    int y = length(head2);

    if (x > y)
        return SUCCESS;   
    if (x < y)
        return FAILURE;   

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            return SUCCESS;  

        if (temp1->data < temp2->data)
            return FAILURE;  

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return SUCCESS; // if both are equal
}
