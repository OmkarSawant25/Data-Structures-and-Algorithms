#include "inverted_search.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Invalid Number of Arguments!\n");
        printf("Info : ./a.out f1.txt f2.txt ... fn.txt\n");
        return FAILURE;
    }

    File_list *head = NULL;

    if(read_and_validate_input_arguments(argc, argv, &head) == FAILURE)
    {
        fprintf(stderr, "Validation Failed\n");
        return FAILURE;
    }
    
    Hash_t hash_array[HASH_SIZE];
    
    if(initialise_hash(hash_array) == SUCCESS)
    {
        printf("Hash Table Initialised successfully!\n");
    }

    while(1)
    {
        int choice;
        printf("1. Create Database.\n");
        printf("2. Display Database.\n");
        printf("3. Search Database.\n");
        printf("4. Save Database.\n");
        printf("5. Update Database.\n");
        printf("6. Exit.\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(create_database(hash_array, head) == SUCCESS)
                {
                    printf("Database created successfully.\n");
                }
                break;
            case 2:
                display_database(hash_array);
                break;
            // case 3:
            //     search_database();
            //     break;
            // case 4:
            //     save_database();
            //     break;
            // case 5:
            //     update_database();
            //     break;
            case 6:
                return EXIT;
            default: 
                fprintf(stderr,"Error : Invalid Input!\n");
        }
    }
    return SUCCESS;
}
