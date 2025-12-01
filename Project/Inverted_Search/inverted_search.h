#ifndef INVERTED_SEARCH
#define INVERTED_SEARCH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_SIZE 50
#define HASH_SIZE 27
#define WORD_SIZE 50

typedef struct node
{
    char file_name[FILE_SIZE];
    struct node *next;
} File_list;

typedef struct sub
{
    int word_count;
    char file_name[FILE_SIZE];
    struct sub *s_link;
} Sub_node;

typedef struct main
{
    int file_count;
    char word[WORD_SIZE];
    Sub_node *s_link;
    struct main *m_link;
} Main_node;

typedef struct hash
{
    int index;
    Main_node *m_link;
} Hash_t;

typedef enum
{
    FAILURE = 0,
    SUCCESS,
    DUPLICATE,
    EXIT
} Status;

Status read_and_validate_input_arguments(int argc, char *argv[], File_list **file);
Status validate_file_extension(char *argv);
long validate_file_size(FILE *fptr);
Status validate_duplicate_file(char *argv, File_list **file);
Status insert_at_last(File_list **head, char *argv);
Status initialise_hash(Hash_t *hash);

Status create_database(Hash_t *hash_array, File_list *head);
void find_index(int *index, char *buffer);
Main_node *create_main_node(char *word);
Sub_node *create_sub_node(char *filename);

#endif