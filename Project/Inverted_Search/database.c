#include "inverted_search.h"

Status create_database(Hash_t *hash_array, File_list *head)
{
    while (head != NULL)
    {
        FILE *fptr = fopen(head->file_name, "r");
        // printf("%s\n", head->file_name);
        if (fptr == NULL)
        {
            fprintf(stderr, "Error : Failed to open '%s' file\n", head->file_name);
            head = head->next;
            continue;
        }
        char buffer[WORD_SIZE];
        while (fscanf(fptr, "%s", buffer) != EOF)
        {
            // printf("%s\n", buffer);
            int index;

            find_index(&index, buffer);
            // printf("Index is %d\n", index);
            if (hash_array[index].m_link == NULL)
            {
                // printf("In Main Node\n");
                Main_node *main_new_node = create_main_node(buffer);
                Sub_node *sub_new_node = create_sub_node(head->file_name);
                main_new_node->s_link = sub_new_node;
                main_new_node->file_count = 1;
                hash_array[index].m_link = main_new_node;
            }
            else
            {
                int flag = 0;
                Main_node *temp1 = hash_array[index].m_link;
                Main_node *backup_main = NULL;
                Main_node *prev_main = NULL;

                while (temp1)
                {
                    if (strcmp(buffer, temp1->word) == 0)
                    {
                        flag = 1;
                        backup_main = temp1;
                        break;
                    }
                    prev_main = temp1;
                    temp1 = temp1->m_link;
                }

                if (flag)
                {
                    int flag1 = 0;
                    Sub_node *temp2 = backup_main->s_link;
                    Sub_node *backup_sub = NULL;
                    Sub_node *prev_sub = NULL;

                    while (temp2)
                    {
                        if (strcmp(temp2->file_name, head->file_name) == 0)
                        {
                            flag1 = 1;
                            backup_sub = temp2;
                            break;
                        }
                        prev_sub = temp2;
                        temp2 = temp2->s_link;
                    }
                    if (flag1)
                    {
                        backup_sub->word_count++;
                    }
                    else
                    {
                        Sub_node *new = create_sub_node(head->file_name);
                        backup_main->file_count++;
                        if (prev_sub == NULL)
                        {
                            backup_main->s_link = new;
                        }
                        else
                        {
                            prev_sub->s_link = new;
                        }
                    }
                }
                else
                {
                    Main_node *main_new = create_main_node(buffer);
                    Sub_node *sub_new = create_sub_node(head->file_name);

                    main_new->s_link = sub_new;
                    main_new->file_count = 1;

                    if (prev_main == NULL)
                    {
                        // Insert at head
                        hash_array[index].m_link = main_new;
                    }
                    else
                    {
                        // Insert at end
                        prev_main->m_link = main_new;
                    }
                }
            }
        }
        fclose(fptr);
        head = head->next;
    }
    return SUCCESS;
}

void display_database(Hash_t *hash_array)
{
    printf("============================================================================================\n");
    printf("                                   Display Database\n");
    printf("============================================================================================\n");
    printf("%-8s %-20s %-12s %-25s %-12s\n", "Index", "Word", "FileCount", "FileName", "WordCount");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_SIZE; i++)
    {
        Main_node *main_temp = hash_array[i].m_link;

        while (main_temp)
        {
            Sub_node *sub_temp = main_temp->s_link;
            if (sub_temp == NULL)
            {
                main_temp = main_temp->m_link;
                continue;
            }
            printf("%-8d %-20s %-12d %-25s %-12d\n", i, main_temp->word, main_temp->file_count, sub_temp->file_name, sub_temp->word_count);
            sub_temp = sub_temp->s_link;
            while (sub_temp)
            {
                printf("%-8s %-20s %-12s %-25s %-12d\n", " ", " ", " ", sub_temp->file_name, sub_temp->word_count);
                sub_temp = sub_temp->s_link;
            }

            main_temp = main_temp->m_link;
        }
    }

    printf("============================================================================================\n");
}

Status search_database(Hash_t *hash_arr, char *data)
{
    int index, found = 0;
    find_index(&index, data);

    Main_node *main_temp = hash_arr[index].m_link;
    while (main_temp)
    {
        if (strcmp(main_temp->word, data) == 0)
        {
            printf("Word %s is present in %d files\n", data, main_temp->file_count);
            Sub_node *sub_temp = main_temp->s_link;
            found = 1;
            while (sub_temp)
            {
                printf("In File : %s -> %d times\n", sub_temp->file_name, sub_temp->word_count);
                sub_temp = sub_temp->s_link;
            }
        }
        main_temp = main_temp->m_link;
    }
    if (!found)
        printf("Unable to find %s\n", data);
    return SUCCESS;
}

Status save_database(Hash_t *hash_array, char *file_name)
{
    if (validate_file_extension(file_name) == FAILURE)
    {
        fprintf(stderr, "Error: '%s' has invalid extension. It must be .txt\n", file_name);
        return FAILURE;
    }

    FILE *fptr = fopen(file_name, "w+");
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Main_node *main_temp = hash_array[i].m_link;
        while (main_temp)
        {
            Sub_node *sub_temp = main_temp->s_link;

            fprintf(fptr, "#%d;%s;%d;", i, main_temp->word, main_temp->file_count);

            while (sub_temp)
            {
                fprintf(fptr, "%s;%d;", sub_temp->file_name, sub_temp->word_count);
                sub_temp = sub_temp->s_link;
            }

            fprintf(fptr, "#\n");
            main_temp = main_temp->m_link;
        }
    }

    fclose(fptr);
    printf("INFO: Database saved successfully in file '%s'\n\n", file_name);

    return SUCCESS;
}

Status update_database(Hash_t *hash_array, char *backup, File_list **head)
{
    // Validate file
    if (validate_file_extension(backup) == FAILURE)
    {
        fprintf(stderr, "Error: '%s' has invalid extension. It must be .txt\n", backup);
        return FAILURE;
    }

    // Open & verify database format
    FILE *fptr = fopen(backup, "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error: Unable to open '%s' file\n", backup);
        return FAILURE;
    }

    if (validate_file_size(fptr) == 0)
    {
        fprintf(stderr, " ERROR: %s file is empty\n", backup);
        return FAILURE;
    }

    if (validate_backup_database(fptr) == FAILURE)
    {
        fprintf(stderr, " ERROR: %s file is not a DATABASE file\n", backup);
        return FAILURE;
    }
    int index, file_count;
    char word[WORD_SIZE];

    while (fscanf(fptr, "#%d;%[^;];%d;", &index, word, &file_count) == 3)
    {
        Main_node *curr_main = hash_array[index].m_link;
        Main_node *prev_main = NULL;

        while (curr_main)
        {
            prev_main = curr_main;
            curr_main = curr_main->m_link;
        }

        Main_node *newNode = create_main_node(word);
        newNode->file_count = file_count;

        if (prev_main)
            prev_main->m_link = newNode;
        else
            hash_array[index].m_link = newNode;

        Sub_node *temp_sub = newNode->s_link;

        int word_count;
        char file_name[WORD_SIZE];

        for (int i = 0; i < file_count; i++)
        {
            fscanf(fptr, "%[^;];%d;", file_name, &word_count);
            Sub_node *newSubNode = create_sub_node(file_name);
            newSubNode->word_count = word_count;

            if (delete_duplicate_file(head, file_name) == SUCCESS)
            {
                printf("\nINFO: Deleting File %s in FileList (already present in the database file %s)\n", file_name, backup);
                print_file_list(head);
            }

            if (temp_sub == NULL)
            {
                newNode->s_link = newSubNode;
            }
            else
            {
                temp_sub->s_link = newSubNode;
            }
            temp_sub = newSubNode;
        }
        fscanf(fptr, "#\n");
    }
    fclose(fptr);

    insert_at_last(head,backup);
    return SUCCESS;
}
