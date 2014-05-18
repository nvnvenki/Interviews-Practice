#include <stdio.h>
#include <stdlib.h>

int find_min(int *a, int low,int high)
{
        if(high < low) // If array is not rotated
        {
                return a[0];
        }
        if(high == low) // array has only one element
        {
                return a[low];
        }
        int mid = low + (high - low)/2;

        if(mid < high && a[mid + 1] < a[mid])
        {
                return a[mid + 1];
        }
        if(mid > low && a[mid] < a[mid - 1])
        {
                return a[mid];
        }

        if(a[high] > a[mid])
        {
                return find_min(a,low,mid - 1);
        }

        return find_min(a, mid + 1, high);
}

int main()
{
        int a[] = {4, 2,1 , 3};
        printf("min element of the array is : %d\n",find_min(a,0,3));

        int b[] = {1};
        printf("Min element in array is: %d\n",find_min(b,0,0));
        return 0;
}
