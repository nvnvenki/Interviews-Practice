#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{

#if 0
        node_t head = NULL;
        node_t head1 = NULL;
        int a[] = {1, 7, 8, 5, 3, 4, 9,6};
        int i = 0;
        for(i = 0; i < 3; ++i)
        {
                head = addElement(head,a[i]);
                head1 = addElement(head1,a[i] + rand() % 13);
        }
        head1 = addElement(head1,100);
        printf("List created....\n");
        display(head);
        display(head1);
        printf("--------------------------------------------------\n");
        
        mergeIntoAnotherAtAlternatePositions(head,head1); 
#endif
        //head = swap_every_two_nodes(head);

        //display(head);
#if 0
        head = reverseList(head);
        printf("Reversed list....\n");
        display(head);
        // lets delete 4th node
        node_t cur = head -> link -> link -> link;
        printf("After deleting a node....\n");
        del(head,cur);
        display(head);

        head = clear(head);
        display(head);
        int nthLast = nthFromLast(head,12);
        if(nthLast != -1)
        {
                printf("Nth from last: %d\n",nthLast);
        }

        head = makeUnique(head);
        display(head);
        
        displayRev(head);
        printf("\n");
        printf("No of occurence of 1 in list is: %d\n", count(head,1));

       printf("3rd node value in the list: %d\n", getNth(head,2));

        head = pop(head);
        head = makeUnique(head);
        display(head);
        head = insertAt(head,10,1);
        display(head);
        int m = 2;
        int n = 3;
        head = deleteNafterM(head, m, n);
        display(head);
        deleteNode(head -> link);
        display(head);
        printf("No of nodes in the list is : %d\n",getLength(head));
        int k = 2;
        head = swapKth(head,k);
        display(head);
 #endif

#if 0
        node_t head = NULL;
        int a[] = {2, 1, 0, 2, 1, 2, 0};
        for(int i = 0; i < 7; ++i)
        {
                head = addElement(head,a[i]);
        }
        display(head);
        head = sortZOT(head);
        display(head);
#endif
#if 0
        int a[] = {1,2,3,4,6,7};
        int b[] = {1,7,2};
        node_t list1 = NULL;
        node_t list2 = NULL;
        node_t intersection_list = NULL;
        node_t union_list = NULL;
        for(int i = 0; i < 6; ++i)
        {
                list1 = addElement(list1,a[i]);
        }
        for(int i = 0; i < 3; ++i)
        {
                list2 = addElement(list2,b[i]);
        }

        intersection_list = intersection(list1,list2,intersection_list);
        printf("Intersection: \n");
        display(intersection_list);

        union_list = union_(list1,list2,union_list);
        printf("Union: \n");
        display(union_list);
        splitNodes(head);
        
#endif
        int a[] = {1,4,4,0};
        int b[] = {1,0,0};

        node_t list1 = NULL;
        node_t list2 = NULL;
        node_t list3 = NULL;

        for(int i = 0; i < 3; ++i)
        {
                list1 = addElement(list1,a[i]);
                list2 = addElement(list2,b[i]);
        }
        list1 = addElement(list1,a[3]);
        display(list1);
        display(list2);
        
        list3 = add_two_lists(list1,list2,list3);
        display(list3);
        return 0;
}
