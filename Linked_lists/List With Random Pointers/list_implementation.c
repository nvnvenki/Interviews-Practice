#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t getNode(int key)
{
        node_t temp = (node_t)malloc(sizeof(struct node));
        temp->key = key;
        temp->link = NULL;
        temp->random = NULL;
        return temp;
}

node_t addNode(node_t head,node_t temp)
{
        
        if(head == NULL)
        {
                head = temp;
        }
        else
        {
                node_t cur = head;
                while(cur->link != NULL)
                {
                        cur = cur->link;
                }
                cur->link = temp;
        }
        return head;
}


void display(node_t head)
{
        if(head == NULL)
        {
                printf("List is empty\n");
                return;
        }
        node_t temp = head;
        while(temp)
        {
                printf("%d\t",temp->key);
                temp = temp->link;
        }
        printf("\n");
}

int count(node_t list)
{
        int count = 0;
        node_t temp = list;
        while(temp)
        {
                ++count;
                temp = temp->link;
        }
        return count;
}

node_t clone(node_t cloned_list,node_t* original_list)
{
        
        if(*original_list == NULL)
        {
                return NULL;
        }
        else
        {
                int length = count(*original_list); 
                node_t original_random[length];
                int i = 0;
                node_t temp = *original_list;
                while(temp)
                {
                        original_random[i++] = temp->link;
                        temp = temp->link;
                }
                
                temp = *original_list;
                while(temp)
                {
                        node_t newNode = getNode(temp->key);
                        cloned_list = addNode(cloned_list,newNode);
                        temp = temp -> link;
                }
                
                temp = *original_list;
                node_t cloned = cloned_list;
                for(int i = 0; i < length; ++i)
                {
                        node_t cur = temp -> link;
                        temp  = cloned;
                        cloned -> random = temp;
                        temp = cur;
                        cloned = cloned -> link;
                }
                
                cloned = cloned_list;
                while(cloned)
                {
                        if(cloned -> random -> random -> link != NULL)
                        {
                                cloned -> random = cloned -> random -> random -> link;
                        }

                        cloned = cloned -> link;
                }
                

                temp = *original_list;
                for(int i = 0; i < length; ++i)
                {
                        temp -> link = original_random[i];
                        temp = temp -> link;
                }
                
                return cloned_list;
        }

}
