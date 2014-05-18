#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    return (a > b ? a: b);
}



int maxSubArraySum(int *a,int n)
{
        int max_so_far = a[0];
        int i;
        int current_max = a[0];
        int start = 0;
        int end = 0;

        for(i = 1; i < n; ++i)
        {
                current_max = max(a[i],current_max + a[i]);
                max_so_far = max(max_so_far,current_max);
        }

        return max_so_far;
}



int main()
{
        int a[] = {-2,-3,4,-1,-2,1,5,-3};
        int n = 8;
        printf("Max : %d\n",maxSubArraySum(a,n));
        return 0;
}
