#include <stdio.h>
#include <stdlib.h>


void display(int* a,int n)
{
       for(int i = 0; i < n; ++i)
       {
               printf("%d\t",a[i]);
       }
       printf("\n");
}

int getMax(int* a,int n)
{
        int max = a[0];
        for(int i = 1; i < n; ++i)
        {
                if(a[i] > max)
                {
                        max = a[i];
                }
        }
        return max;
}

void countSort(int* a,int n, int exp)
{
        int output[n];
        
        int count[10] = {0};
        for(int i = 0; i < n; ++i)
        {
                count[(a[i] / exp) % 10]++;
        }

        for(int i = 1; i < 10; ++i)
        {
                count[i] += count[i - 1];
        }

        for(int i = n - 1; i >= 0; --i)
        {
                output[count[(a[i] / exp) % 10] - 1] = a[i];
                count[(a[i] / exp) % 10]--;
        }
        for(int i = 0; i < n; ++i)
        {
                a[i] = output[i];
        }
}

void radix_sort(int* a,int n)
{
        int max = getMax(a,n);

        // For every digit 
        for(int exp = 1; max/exp > 0; exp *= 10)
        {
                countSort(a,n,exp);
        }
}


int main()
{
        int a[] = {170,4,460,121,10,100,48};
        int n = 7;
        display(a,n);
        radix_sort(a,n);
        display(a,n);
        return 0;
}
