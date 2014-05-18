#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
        node_t list = NULL;
        int a[] = {1,2,3,4,5};

        for(int i = 0; i < 5; ++i)
        {
                list = addNode(list,getNode(a[i]));
        }
        display(list);

        // Make random pointer to point to some random list node
        list->random = list->link->link->link;
        list->link->random = list->link->link;
        list->link->link->link->random = list;
        list->link->link->random = list->link->link->link->link;

        node_t cloned_list = NULL;
        
        display(list);

        cloned_list = clone(cloned_list,&list);
        display(cloned_list);
        // test
        printf("%d\n",cloned_list->link->link->random->key);

        return 0;
}
