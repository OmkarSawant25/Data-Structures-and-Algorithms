#include "apc.h"

/* Validate number string – must contain only digits */
Status valid_number(char *nums)
{
    for (int i = 0; nums[i] != '\0'; i++)
    {
        if(nums[i] == '+' || nums[i] == '-')
            continue;
        if (nums[i] < '0' || nums[i] > '9')
            return FAILURE;
    }
    return SUCCESS;
}

/* Validate operator – allowed operators: +  -  X/x  / */
Status valid_operator(char *op)
{
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
        strcmp(op, "X") == 0 || strcmp(op, "x") == 0 ||
        strcmp(op, "/") == 0)
    {
        return SUCCESS;
    }
    return FAILURE;
}

/* Validate number of arguments and each input */
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

/* Create new DLL node */
Dlist *create_new_node(int data)
{
    Dlist *newNode = malloc(sizeof(Dlist));
    if (newNode == NULL)
        return NULL;

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* Insert node at beginning */
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

/* Convert string to doubly linked list */
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

/* Print DLL as number */
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

/* Count number of nodes */
int length(Dlist *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

/* Compare two DLL numbers (returns SUCCESS if num1 >= num2) */
Status comparelist(Dlist *head1, Dlist *head2)
{
    int x = length(head1);
    int y = length(head2);

    if (x > y)
        return SUCCESS;
    if (x < y)
        return FAILURE;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return SUCCESS;

        if (head1->data < head2->data)
            return FAILURE;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SUCCESS;        // equal
}

/* Remove unnecessary leading zeros */
// void remove_leading_zero(Dlist **head)
// {
//     while ((*head)->data == 0 && (*head)->next != NULL)
//     {
//         Dlist *temp = *head;
//         *head = (*head)->next;
//         (*head)->prev = NULL;
//         free(temp);
//     }
// }

void remove_leading_zero(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && *head != *tail)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    Dlist *t = *head;
    while (t && t->next)
        t = t->next;

    *tail = t;
}


/* Free entire DLL */
void free_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;

    while (temp)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;
}

/* Insert node at end */
void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (!*head && !*tail)
    {
        *head = *tail = new;
    }
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }
}

void copy_list(Dlist **newH, Dlist **newT, Dlist **tail1)
{
    Dlist *temp = *tail1;
    while(temp)
    {
        insert_at_start(newH,newT,temp->data);
        temp = temp->prev;
    }
}

/* check if divisor is zero */
int division_by_zero(Dlist **head, Dlist **tail)
{
	if (*head == *tail && (*head)->data == 0)
		return 1;
	else
		return 0;
}

