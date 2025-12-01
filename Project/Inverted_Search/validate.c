#include "inverted_search.h"

Status read_and_validate_input_arguments(int argc, char *argv[], File_list **file)
{
    printf("==============================================================\n");
    printf("               Validating the Input Files\n");
    printf("==============================================================\n");

    int count = 0;

    for (int i = 1; i < argc; i++)
    {
        // Check the extension
        if (validate_file_extension(argv[i]) == FAILURE)
        {
            fprintf(stderr, "Error: '%s' has invalid extension. It must be .txt\n", argv[i]);
            continue;
        }

        // Check if the file is present or not
        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL)
        {
            fprintf(stderr, "Error: File Not found! Unable to find the FILE '%s'.\n", argv[i]);
            continue;
        }

        // Validate the file is empty or not
        if (validate_file_size(fptr) == 0)
        {
            fprintf(stderr, "Error: File '%s' is Empty!\n", argv[i]);
            fclose(fptr);
            continue;
        }
        fclose(fptr);

        if (validate_duplicate_file(argv[i], file) == DUPLICATE)
        {
            fprintf(stderr, "Error: Duplicate File of name '%s' spotted.\n", argv[i]);
            continue;
        }

        if (insert_at_last(file, argv[i]) == FAILURE)
        {
            fprintf(stderr, "Error: Insertion of File '%s' in the List Failed!\n", argv[i]);
            continue;
        }
        printf("Info : File '%s' Inserted Successfully.\n", argv[i]);
        count++;
    }
    printf("==============================================================\n");
    if(!count)
        return FAILURE;
    return SUCCESS;
}

Status validate_file_extension(char *argv)
{
    // Find the file extension
    char *dot = strrchr(argv, '.');
    if (dot == NULL)
    {
        fprintf(stderr, "Error: File '%s' has no extension.\n", argv);
        return FAILURE;
    }

    // Compare with valid extensions
    if (strcmp(dot, ".txt") == 0)
        return SUCCESS;

    fprintf(stderr, "Error: File '%s' has unsupported extension.\n", argv);
    return FAILURE;
}

long validate_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr);

    if (size == -1)
        return 0;

    fseek(fptr, 0, SEEK_SET);
    return size;
}

Status validate_duplicate_file(char *argv, File_list **file)
{
    if (*file == NULL)
        return SUCCESS;
    else
    {
        File_list *temp = *file;
        while (temp != NULL) // Traverse through the list
        {
            if (strcmp(temp->file_name, argv) == 0)
            {
                return DUPLICATE;
            }
            temp = temp->next; // Go to next node
        }
    }
    return SUCCESS;
}

Status insert_at_last(File_list **head, char *argv)
{
    File_list *newnode = malloc(sizeof(File_list)); // Allocate memory for new node

    if (newnode == NULL) // Check if memory allocation failed
        return FAILURE;

    strcpy(newnode->file_name, argv); // Store file name in new node
    newnode->next = NULL;             // Initialize link as NULL (last node)

    if (*head == NULL) // If list is empty
    {
        *head = newnode; // New node becomes head
    }
    else
    {
        File_list *temp = *head;   // Create temp pointer for traversal
        while (temp->next != NULL) // Traverse till last node
        {
            temp = temp->next; // Move to next node
        }
        temp->next = newnode; // Link new node at the end
    }
    return SUCCESS; // Return success status
}


