#include "inverted_search.h"

Status create_database(Hash_t *hash_array, File_list *head)
{
    while (head != NULL)
    {
        FILE *fptr = fopen(head->file_name, "r");
        printf("%s\n", head->file_name);
        if (fptr == NULL)
        {
            fprintf(stderr, "Error : Failed to open '%s' file\n", head->file_name);
            head = head->next;
            continue;
        }
        char buffer[WORD_SIZE];
        while (fscanf(fptr, "%s", buffer) != EOF)
        {
            printf("%s\n", buffer);
            int index;

            find_index(&index, buffer);
            printf("Index is %d\n", index);
            if (hash_array[index].m_link == NULL)
            {
                printf("In Main Node\n");
                Main_node *main_new_node = create_main_node(buffer);
                Sub_node *sub_new_node = create_sub_node(head->file_name);
                main_new_node->s_link = sub_new_node;
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
                        backup_sub->word_count += 1;
                    }
                    else
                    {
                        Sub_node *new = create_sub_node(head->file_name);
                        temp1->file_count += 1;
                        prev_sub->s_link = new;
                    }
                }
                else
                {
                    Main_node *main_new = create_main_node(buffer);
                    Sub_node *sub_new = create_sub_node(head->file_name);
                    main_new->s_link = sub_new;
                    prev_main->m_link = main_new;
                }
            }
        }
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
                printf("%-8d %-20s %-12d %-25s %-12s\n", i, main_temp->word, main_temp->file_count, "-", "-");
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
