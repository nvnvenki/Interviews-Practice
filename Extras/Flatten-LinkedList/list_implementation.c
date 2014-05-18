#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(node_t head)
{
        node_t temp = head;
        while(temp != NULL)
        {
                printf("%d\t",temp -> key);
                temp = temp -> link;
        }
        printf("\n");

}

node_t createMultiLevelList()
{
        //Some stupid arrays
        int a[] = {10,5,12,7,11};
        int b[] = {4,20,13};
        int c[] = {17,6};
        int d[] = {10,20};
        int e[] = {1};

        //Now create the linked list of each Array
        node_t a_head = createList(a,5);
        //display(a_head);
        node_t b_head = createList(b,3);
        node_t c_head = createList(c,2);
        node_t d_head = createList(d,2);
        //node_t e_head = createList(e,1);
        //printf("a\n")
        display(a_head);
        display(b_head);
        display(c_head);
        display(d_head);
        //display(e_head);
        // Nw modify these list to multi level
        
        //c_head -> link -> child = d_head;
        a_head->link->child = b_head;
        a_head->link->link->child = c_head;
        //display(a_head);
        c_head->link-> child = d_head;
        
        //printf("Test\n");
        //display(c_head);
        //display(d_head);        
        return a_head;
}

node_t createList(int *a , int n)
{
        node_t head = NULL;
        int i;
        for(i = 0; i < n ; ++i)
        {
                node_t temp = (node_t)malloc(sizeof(struct node));
                temp -> key = a[i];
                temp -> link = NULL;
                temp -> child = NULL;
                if(head == NULL){
                        head = temp;
                }
                else{
                        node_t cur;
                        cur = head;
                        while(cur -> link != NULL)
                        {
                                cur = cur -> link;
                        }
                        cur->link = temp;
                }
        }

        return head;
}

node_t flattenList(node_t head)
{
        if(head == NULL)
        {
                return;
        }
        
        //Find the end of the first level list
        node_t end = head;
        while(end -> link != NULL)
        {
                end = end -> link;
        }

        //Now traverse through all the nodes of first level
        node_t cur = head;

        while(cur != end)
        {
                //If that node has a child list
                if(cur -> child){
                        //Then append that to end
                        end -> link = cur -> child;
                        //Now update the end of the list
                        node_t temp = cur -> child;
                        while(temp -> link != NULL)
                        {
                                temp = temp -> link;
                        }
                        //temp wld be in end of the child list nw
                        //So change the end of the original list to end of the child list
                        end = temp;
                }

                cur = cur -> link;
        }

        return head;
}
