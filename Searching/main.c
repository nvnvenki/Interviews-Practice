#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
        int a[] = {7, 1, 2, 5, 6, 3, 4};
        int n = 7;
        int search_key = 60;
        int flag = linear_search(a,7,search_key);
        if(flag > 0)
        {
                printf("%d is found\n", search_key);
        }
        else
        {
                printf("%d is not found\n",search_key);
        }
        return 0;
}
