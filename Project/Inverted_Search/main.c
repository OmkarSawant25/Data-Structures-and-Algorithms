#include "inverted_search.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Invalid Number of Arguments!\n");
        printf("Info : ./a.out f1.txt f2.txt ... fn.txt\n");
        return FAILURE;
    }

    File_list *head = NULL;

    if (read_and_validate_input_arguments(argc, argv, &head) == FAILURE)
    {
        fprintf(stderr, "Validation Failed\n");
        return FAILURE;
    }

    Hash_t hash_array[HASH_SIZE];

    if (initialise_hash(hash_array) == SUCCESS)
    {
        printf("Hash Table Initialised successfully!\n");
    }

    int choice;
    char backupfilename[WORD_SIZE];
    char search[WORD_SIZE];
    bool create_flag = false;

    while (1)
    {
        printf("1. Create Database.\n");
        printf("2. Display Database.\n");
        printf("3. Search Database.\n");
        printf("4. Save Database.\n");
        printf("5. Update Database.\n");
        printf("6. Exit.\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (create_flag)
            {
                fprintf(stderr, "INFO: DATABASE already created\n");
                break;
            }
            if (create_database(hash_array, head) == SUCCESS)
            {
                printf("Database created successfully.\n");
                create_flag = true;
            }
            break;

        case 2:
            display_database(hash_array);
            break;

        case 3:
            printf("Enter the word you want to search : ");
            scanf("%s", search);
            search_database(hash_array, search);
            break;

        case 4:
            printf("Enter backup file name to save: ");
            scanf(" %s", backupfilename);
            save_database(hash_array, backupfilename);
            break;

        case 5:
            if (create_flag)
            {
                fprintf(stderr, "INFO: Cannot update because database is already created.\n");
                fprintf(stderr, "INFO: Restart the program if you want to load a backup database.\n");
                break;
            }
            printf("Enter the database file to update: ");
            scanf("%s", backupfilename);
            update_database(hash_array, backupfilename, &head);
            print_file_list(&head);
            break;

        case 6:
            return 0;

        default:
            fprintf(stderr, "Error : Invalid Input!\n");
        }
    }
}
