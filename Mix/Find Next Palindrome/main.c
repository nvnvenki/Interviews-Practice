#include <stdio.h>
#include <stdlib.h>


int all9s(int *a,int n)
{
        for(int i = 0; i < n; ++i)
        {
                if(a[i] != 9)
                {
                        return 0;
                }
        }
        return 1;
}

void printArray(int *a,int n)
{
        for(int i = 0; i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
}

int main(int argc, char *argv[])
{
        int a[] = {9,4,1,8,7,9,7,8,3,2,2};
        int n = sizeof(a)/sizeof(a[0]);
        generateNextPalindrome(a,n);
        return 0;
}
