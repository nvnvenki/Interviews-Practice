#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
        int a[] = {3,6,1,7,9};
        //selection_sort(a,4);
        //bubble_sort(a,4);
        //insertionSort(a,4);
        //mergeSort(a,0,4);
        quickSort(a,0,3);
        for(int i = 0; i < 4; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
        return 0;
}
