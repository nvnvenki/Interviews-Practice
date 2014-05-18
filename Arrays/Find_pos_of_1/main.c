#include <stdio.h>

int getPos(int *a, int n)
{
        
        if(a[0] == 1) // sorted in descending order
        {
                return 0;
        }
        else
        {
                for(int i = 1; i < n; ++i)
                {
                        if(a[i] > a[i - 1])
                        {
                                return i;
                        }
                }
        }
        return -1;
}

int main()
{
        int a[] = {1,1,1,1,1};
        int n = 5;
        printf("Position of first 1 is : %d\n",getPos(a,n));
        return 0;
}
