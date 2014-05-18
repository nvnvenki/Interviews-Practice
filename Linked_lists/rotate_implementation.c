#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t rotateBy(node_t head, int n)
{
        if(head == NULL || n == 0)
        {
                return head;
        }
        node_t cur = head;
        while(cur -> link -> link != NULL)
        {
                cur = cur -> link;
        }
        node_t temp = cur -> link;
        cur -> link = NULL;
        temp -> link = head;
        head = temp;

        return head = rotateBy(head, n - 1);
}
