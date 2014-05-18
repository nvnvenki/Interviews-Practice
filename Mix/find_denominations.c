#include <stdio.h>
#include <limits.h>

int denominations(int *a,int n,int sum)
{
        int min[sum + 1];
        for(int i = 0; i < sum + 1; ++i)
        {
                min[i] = INT_MAX;
        }
        
        min[0] = 0;
        int i,j;
        for(i = 1; i <= sum; ++i)
        {
                for(j = 0;j < n;++j)
                {
                        if(a[j] <= i && (min[i - a[j]] < min[i]))
                        {
                                min[i] = min[i - a[j]] + 1;
                        }
                }
        }
        
        return min[sum];


}

int main()
{
        int a[] = {1,3,4,5};
        int sum = 11;
        int n;
        printf("Min no of coins: %d\n",denominations(a,n,sum));

        return 0;
}
