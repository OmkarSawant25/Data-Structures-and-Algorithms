#include "inverted_search.h"

Status initialise_hash(Hash_t *hash)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash[i].index = i;
        hash[i].m_link = NULL;
    }
    return SUCCESS;
}

void find_index(int *index, char *buffer)
{
    if (isupper(buffer[0]))
    {
        *index = buffer[0] - 'A';
    }
    else if (islower(buffer[0]))
    {
        *index = buffer[0] - 'a';
    }
    else
    {
        *index = 26;
    }
}

Main_node *create_main_node(char *word)
{
    Main_node *newnode = (Main_node *)malloc(sizeof(Main_node));

    if (newnode == NULL)
        return NULL;

    strcpy(newnode->word, word);
    newnode->file_count = 1;
    newnode->m_link = NULL;
    newnode->s_link = NULL;

    return newnode;
}

Sub_node *create_sub_node(char *filename)
{
    Sub_node *newnode = (Sub_node *)malloc(sizeof(Sub_node));

    if (newnode == NULL)
        return NULL;

    strcpy(newnode->file_name, filename);
    newnode->word_count = 1;
    newnode->s_link = NULL;

    return newnode;
}

Status validate_backup_database(FILE *fptr)
{
    char ch;
    ch = fgetc(fptr); // First character
    if (ch != '#')
        return FAILURE;

    fseek(fptr, -2, SEEK_END); // Move to second last position '#\n'
    ch = fgetc(fptr);          // Last character
    if (ch != '#')
        return FAILURE;

    rewind(fptr); // Reset file pointer
    return SUCCESS;
}

Status delete_duplicate_file(File_list **head, char *file_name)
{
    File_list *curr = *head;
    File_list *prev = NULL;

    while (curr)
    {
        if (strcmp(file_name, curr->file_name) == 0)
        {
            if (prev == NULL)
            {
                File_list *temp = *head;
                *head = temp->next;
                free(temp);
            }
            else
            {
                prev->next = curr->next;
                free(curr);
            }
            return SUCCESS;
        }
        prev = curr;
        curr = curr->next;
    }
    return FAILURE;
}

void print_file_list(File_list **file_list)
{
    printf("FileList: ");
    File_list *temp = *file_list;
    while (temp)
    {
        printf("-> %s ", temp->file_name);
        temp = temp->next;
    }
    printf("\n");
}