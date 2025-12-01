#include "inverted_search.h"
          
Status create_database(Hash_t *hash_array, File_list *head)
{
    while(head != NULL)
    {
        FILE *fptr = fopen(head->file_name, "r");
        printf("%s\n", head->file_name); 
        if(fptr == NULL)
        {
            fprintf(stderr ,"Error : Failed to open '%s' file\n", head->file_name);
            continue;
        }
        char buffer[100];
        while(fscanf(fptr,"%s",buffer) != EOF)
        {
            // printf("%s\n", buffer);
            int index;

            find_index(&index, buffer);
            // printf("Index is %d\n", index);
            if(hash_array[index].m_link == NULL)
            {
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

                while(temp1)
                {
                    if(strcmp(buffer, temp1->word) == 0)
                    {
                        flag = 1;
                        backup_main = temp1;
                    }
                    prev_main = temp1;
                    temp1 = temp1->m_link;
                }
                
                if(flag)
                {
                    int flag1 = 0;
                    Sub_node *temp2 = backup_main->s_link;
                    Sub_node *backup_sub = NULL;
                    Sub_node *prev_sub = NULL;

                    while(temp2)
                    {
                        if(strcmp(temp2->file_name, head->file_name) == 0)
                        {
                            flag1 = 1;
                            backup_sub = temp2;
                        }
                        prev_sub = temp2;
                        temp2 = temp2->s_link;
                    }
                    if(flag1)
                    {
                        backup_sub->word_count += 1;
                    }
                    else
                    {
                        Sub_node *new = create_sub_node(head->file_name);
                        temp1->file_count += 1;
                        prev_sub = new;
                    }

                }
                else
                {
                    
                }
            }

        }
        head = head->next;
    }
    return SUCCESS;
}