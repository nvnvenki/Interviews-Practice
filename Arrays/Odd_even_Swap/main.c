#include <stdio.h>

void swap(int *a,int *b)
{
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
}

void change(int *a,int n)
{
#if 0
        for(int i = 1; i < n - 1; ++i)
        {
                if(i % 2 == 0)
                {
                        a[i] = a[i + 1];
                }
        }
#endif
}

int main()
{
        int a[] = {0,1,2,3,4,5,6,7};
        int n = 8;
        printf("Before reversal:\n");
        for(int i = 1;i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
        change(a,n);

        printf("After reversal\n");
        for(int i = 1; i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
        return 0;
}
