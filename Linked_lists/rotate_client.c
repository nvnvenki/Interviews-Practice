#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
        node_t head = NULL;
        int a[] = {1, 2, 3, 4, 3, 4, 9};
        int i = 0;
        for(i = 0; i < 7; ++i)
        {
                head = addElement(head,a[i]);
        }
        display(head);
        int n = 11;
        head = rotateBy(head,n);
        display(head);
        return 0;
}
