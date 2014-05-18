#include <stdio.h>

void rotateRight(int *a,int n,int times)
{
        while(times > 0)
        {
                int i;
                int temp = a[0];
                for(i = 0; i < n - 1; ++i)
                {
                        a[i] = a[i + 1];
                }
                a[i] = temp;
                --times;
        }
}


void rotateLeft(int *a,int n,int times)
{
        while(times > 0)
        {
                int i;
                int temp = a[n - 1];
                for(i = n - 1; i > 0; --i)
                {
                        a[i] = a[i - 1];
                }
                a[i] = temp;
                --times;
        }
}

void display(int *a,int n)
{
        for(int i = 0; i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
}

void swap(int *a,int *b)
{
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
}
/*
        one more algo
        1.Reverse array from 0 to times - 1
        2.Reverse array from times to n - 1
        3.Reverse whole array
*/
int main()
{
        // int a[] = {1,2,3,4,5};
        int a[] = {21, 32, 13, 14, 43};
        int n = sizeof(a) / sizeof(a[0]);
        int times = 2;
        display(a,n);
        //rotateLeft(a,n,times);
        // rotateRight(a,n,times);
        
        display(a,n);
        return 0;
}
