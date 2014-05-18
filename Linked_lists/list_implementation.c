#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t addElement(node_t head, int element)
{
        //head = sortedAdd(head,element);

        node_t temp = (node_t)malloc(sizeof(struct node));
        temp -> key = element;
        temp -> link = NULL;

        if(head == NULL)
        {
                head = temp;
        }
        else
        {

                node_t cur;
                cur = head;
                while(cur -> link != NULL)
                {
                        cur = cur -> link;
                }
                cur -> link = temp;

        }

        return head;
}

void display(node_t head)
{
        if(head == NULL)
        {
                printf("Empty list\n");
                return;
        }
        node_t temp = head;
        while(temp)
        {
                printf("%d\t", temp -> key);
                temp = temp -> link;
        }
        printf("\n");
}


node_t reverseList(node_t head)
{
  
        if(head == NULL)
        {
                return head;
        }
        node_t p;
        node_t q;
        node_t r;

        p = head;
        q = head -> link;
        // Separate the first node
        p -> link = NULL;

        while(q != NULL)
        {
                r = q -> link;
                q -> link = p;
                p = q;
                q = r;
        }

        head = p;
        return head;
}

node_t del(node_t head,node_t temp)
{       
        
        if(head == NULL || temp == NULL )
        {
                return head;
        }
        node_t next = temp -> link;
        temp -> key = next -> key;
        temp -> link = next -> link;
        free(next);
        return head;
}

node_t sortedAdd(node_t head,int element)
{
        node_t temp = (node_t)malloc(sizeof(struct node));
        temp -> key = element;
        temp -> link = NULL;
        if(head == NULL)
        {
                head = temp;
                return head;
        }
        if(temp -> key > head -> key)
        {
                temp -> link = head;
                head = temp;
        }
        else
        {
                node_t prev = NULL;
                node_t  cur = head;
                
                while(cur != NULL && temp -> key <= cur -> key)
                {
                        prev = cur;
                        cur = cur -> link;
                }
                prev -> link = temp;
                temp -> link = cur;
        }
        
        return head;
}

node_t clear(node_t head)
{
        node_t temp = head;
        node_t cur;
        while(temp != NULL)
        {
                cur = temp;
                temp = temp -> link;
                free(cur);               
        }
        head = NULL;
        return head;
}

int nthFromLast(node_t head,int n)
{
        if(head == NULL)
        {
                return -1;
        }
        
        node_t temp = head;
        node_t cur = head;
        int count = 0;
        while(count < n)
        {
                if(cur == NULL)
                {
                        return -1;
                }
                cur = cur -> link;
                ++count;
        }
        while(cur != NULL)
        {
                temp = temp -> link;
                cur = cur -> link;
        }
        return temp -> key;
}


node_t makeUnique(node_t head)
{       
        if(head == NULL)
        {
                return head;
        }
        node_t temp = head;
        while(temp -> link != NULL)
        {
                if(temp -> key == temp -> link -> key)
                {
                        node_t next = temp -> link -> link;
                        free(temp -> link);
                        temp -> link = next;
                }
                else
                {
                        temp = temp -> link;
                }
        }

        return head;
}

void displayRev(node_t head)
{
        if(head == NULL)
        {
                return;
        }
        else
        {
                node_t temp = head;
                if(temp -> link != NULL)
                {
                        displayRev(temp -> link);
                }
                printf("%d\t", temp -> key);
        }
}

int count(node_t head,int key)
{
        if(head == NULL)
        {
                return -1;
        }
        node_t temp = head;
        int n = 0;
        while(temp != NULL)
        {
                if(temp -> key == key)
                {
                        ++n;
                }
                temp = temp -> link;
        }

        return n;
}

int getNth(node_t head,int index)
{
        if(head == NULL)
        {
                return -1;
        }
        int i = 0;
        node_t temp = head;
        while(i < index)
        {
                temp = temp -> link;
                ++i;
        }
        return temp -> key;

}

node_t pop(node_t head)
{
        if(head == NULL)
        {
                return head;
        }
        printf("Popped value: %d\n", head -> key);
        return head -> link;
}

node_t insertAt(node_t head,int val,int index)
{
        node_t temp = (node_t)malloc(sizeof(struct node));
        temp -> key = val;
        temp -> link = NULL;
        int i = 0;
        node_t cur = head;
        while(cur != NULL && i <= index - 1) 
        {
                cur = cur -> link;
                ++i;
        }
        printf("%d\n",cur -> key);
        node_t prev = cur;
        temp -> link = cur -> link;
        prev -> link = temp;
        return head;
}

node_t deleteNafterM(node_t head,int m, int n)
{
        // Skip m nodes and delete n nodes after that - Problem
        node_t cur = head;

        while(cur != NULL)
        {
                // skip n nodes
                for(int i = 1; cur != NULL && i < m; i++)
                {
                        cur = cur -> link;
                }

                if(cur == NULL)
                {
                        return head;
                }
                
                node_t temp = cur -> link; // start from next node after m nodes
                for(int i = 1; temp != NULL && i <= n; ++i)
                {
                        node_t next = temp;
                        temp = temp -> link;
                        free(next);
                }
                
                cur -> link = temp;
                cur = temp;
        }
        return head;
}

void deleteNode(node_t node_ptr)
{
        node_t temp = node_ptr -> link;
        node_ptr -> key = temp -> key;
        node_ptr -> link = temp -> link;
        free(temp);
}

int getLength(node_t head)
{
        node_t temp = head;
        int count = 0;
        if(temp == NULL)
        {
                return count;
        }
        while(temp != NULL)
        {
                ++count;
                temp = temp -> link;
        }
        return count;
}

node_t swapKth(node_t head,int k)
{
        if(head == NULL || k <= 0)
        {
                return head;
        }
        int n = getLength(head);
        if(k > n)
        {
                return head;
        }
        if(2 * k - 1 == n) // if kth node from last is same as the kth node from the end
        {
                return head;
        }
        // From the front
        node_t cur = head;
        node_t prev = NULL;
        for(int i = 1; i < k; ++i)
        {
                prev = cur;
                cur = cur -> link;
        }
        //printf("%d\n",cur -> key);
        // Now from the rear
        node_t rear = head;
        node_t rear_prev = NULL;
        for(int i = 1; i < n - k + 1; ++i)
        {
                rear_prev = rear;
                rear = rear -> link;
        }
        //printf("%d\n",rear -> key);
        if(cur != NULL)
        {
                prev -> link = rear;
        }
        if(rear != NULL)
        {
                rear_prev -> link = cur;
        }
        
        // swap the pointers
        node_t temp = cur -> link;
        cur -> link = rear -> link;
        rear -> link = temp;
        
        if(k == 1)
        {
                head = rear;
        }
        if(k == n)
        {
                head = cur;
        }
        return head;
}

node_t sortZOT(node_t head)
{
        int count[3] = {0,0,0}; // Array to keep track of no of 0's 1's and 2's
        node_t temp = head;
        while(temp != NULL)
        {
                ++count[temp -> key];
                temp = temp -> link;
        }
        temp = head;
        int i = 0;
        while(temp != NULL)
        {
                if(count[i] == 0)
                {
                        ++i;
                }
                else
                {
                        temp -> key = i;
                        --count[i];
                        temp = temp -> link;
                }
        }

        return head;
}


int isPresent(node_t list,int key)
{
        node_t temp = list;
        while(temp != NULL)
        {
                if(temp -> key == key)
                {
                        return 1;
                }
                temp = temp -> link;
        }

        return 0;
}

node_t intersection(node_t list1,node_t list2,node_t intersection_list)
{
        if(list1 == NULL || list2 == NULL)
        {
                intersection_list = NULL;
        }
        else
        {
                node_t temp = list1;
                while(temp != NULL)
                {
                        if(isPresent(list2,temp -> key))
                        {
                                intersection_list = addElement(intersection_list,temp -> key);
                        }
                        temp = temp -> link;
                }
        }

        return intersection_list;
}

node_t union_(node_t list1,node_t list2,node_t union_list)
{
        union_list = NULL;
        if(list1 == NULL)
        {
                union_list = list2;
        }
        else if(list2 == NULL)
        {
                union_list = list1;
        }
        else
        {
                node_t temp1 = list1;
                node_t temp2 = list2;
                
                while(temp1 != NULL)
                {
                        union_list = addElement(union_list,temp1 -> key);
                        temp1 = temp1 -> link;
                }

                while(temp2 != NULL)
                {
                        if(!isPresent(union_list, temp2 -> key))
                        {
                                union_list = addElement(union_list,temp2 -> key);
                        }
                        temp2 = temp2 -> link;
                }
       }

       return union_list;
}

node_t swap_every_two_nodes(node_t head)
{
        if(head == NULL || head -> link == NULL)
        {
                return head;
        }
        node_t cur = head;
        node_t next = cur -> link;
        head = next;
        node_t prev = NULL;

        while(next != NULL)
        {
                cur -> link = next -> link;
                next -> link = cur;
                if(prev != NULL)
                {
                        prev -> link = next;
                }
                if(cur -> link != NULL)
                {
                        prev = cur;
                        cur = cur -> link;
                }
                next = cur -> link;
                
        }
        return head;
}

// Split alternate nodes
void splitNodes(node_t head)
{
        if(head == NULL)
        {
                return ;
        }
        node_t cur = head;
        node_t next = head -> link;

        node_t list1 = head;
        node_t list2 = head -> link;

        while(cur != NULL && next != NULL)
        {
                if(next != NULL)
                {
                        cur -> link = next -> link;
                        cur = cur -> link;
                }
                if(cur != NULL)
                {
                        next -> link = cur -> link;
                        next = next -> link;
                }
        }

        display(list1);
        display(list2);
}

void mergeIntoAnotherAtAlternatePositions(node_t list1,node_t list2)
{
        if(list1 == NULL || list2 == NULL)
        {
                return;
        }

        node_t cur1 = list1;
        node_t cur2 = list2;
        node_t next1 = NULL;
        node_t next2 = NULL;

        while(cur1 != NULL && cur2 != NULL)
        {
                next1 = cur1 -> link;
                next2 = cur2 -> link;

                cur2 -> link = next1;
                cur1 -> link = cur2;

                cur1 = next1;
                cur2 = next2;
        }
        list2 = cur2;
        display(list1);
        display(list2);
}


node_t addSameSize(node_t list1,node_t list2,int* carry)
{
        if(list1 == NULL)
        {
                return NULL;
        }

        int sum;

        node_t list3 = (node_t) malloc(sizeof(struct node));

        list3 -> link = addSameSize(list1->link,list2->link,carry);
        
        sum = list1->key + list2->key + *carry;
        *carry = sum / 10;

        sum = sum % 10;

        list3->key = sum;

        return list3;
}

void swapPointers(node_t* a,node_t* b)
{
        node_t temp = *a;
        *a = *b;
        *b = temp;
}
void addCarryToRemaining(node_t list1,node_t cur,int* carry,node_t* list3)
{
        int sum;
        if(list1 != cur)
        {
                addCarryToRemaining(list1->link,cur,carry,list3);

                sum = list1->key + *carry;
                *carry = sum / 10;
                sum = sum % 10;
                
                node_t temp = (node_t)malloc(sizeof(struct node));
                temp -> key = sum;
                temp -> link = *list3;
                *list3 = temp;
        }
        
}

node_t add_two_lists(node_t list1,node_t list2,node_t list3)
{
        node_t cur;
        if(list1 == NULL)
        {
                return list2;
        }
        else if(list2 == NULL)
        {
                return list1;
        }

        int length1 = getLength(list1);
        int length2 = getLength(list2);
        
        int carry = 0;

        if(length1 == length2)
        {
                list3 = addSameSize(list1,list2,&carry);
        }
        else
        {
                int difference = abs(length1 - length2);

                if(length1 < length2)
                {
                        swapPointers(&list1,&list2);
                }

                for(cur = list1; difference--; cur = cur -> link);

                list3 = addSameSize(cur,list2,&carry);
                addCarryToRemaining(list1,cur,&carry,&list3);
        }

        if(carry != 0)
        {
                node_t temp = (node_t)malloc(sizeof(struct node));
                temp -> key = carry;
                temp -> link = list3;
                list3 = temp;
        }

        return list3;

}


