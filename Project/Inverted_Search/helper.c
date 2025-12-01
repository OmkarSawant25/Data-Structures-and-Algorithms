#include "inverted_search.h"

Status initialise_hash(Hash_t *hash)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash->index = i;
        hash->m_link = NULL;
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

    if(newnode == NULL)
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

    if(newnode == NULL)
        return NULL;
    
    strcpy(newnode->file_name, filename);
    newnode->word_count = 1;
    newnode->link = NULL;
    
    return newnode;
}