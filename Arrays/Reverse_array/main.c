#include <stdio.h>

void swap(int *a,int *b)
{
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
}

void reverseArray(int *a,int n)
{
        int i = 0;
        int j = n - 1;
        while(i < j)
        {
                swap(&a[i++],&a[j--]);
        }
}

int main()
{
        int a[] = {1,2,3,4,5,6,7};
        int n = 7;
        printf("Before reversal:\n");
        for(int i = 0;i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
        reverseArray(a,n);

        printf("After reversal\n");
        for(int i = 0; i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
        return 0;
}
