#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int linear_search(int *a,int n,int key)
{
        int i = 0;
        while(i < n && a[i] != key)
        {
                i++;
        }
        if(i < n)
        {
                return i;
        }
        else
        {
                return -1;
        }
}
