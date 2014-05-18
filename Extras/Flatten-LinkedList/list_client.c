#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
        node_t head = NULL;
        printf("Created lists\n");
        head = createMultiLevelList();
        head = flattenList(head);
        printf("Flattened list\n");
        display(head);
        return 0;
}
