#include <stdio.h>

void display(int *a,int n)
{
        for(int i = 1; i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
}

void heapify(int *a,int n)
{
        int i = 0;
        int k = 0;
        int v = 0;
        int j = 0;
        int heap = 0;

        for(i = (n - 1) / 2; i >= 1; --i)
        {
                k = i;
                v = a[k];
                heap = 0;

                while(!heap && (2 * k) <= n - 1)
                {
                        j = 2 * k;
                        if(j < n - 1)
                        {
                                if(a[j] < a[j + 1])
                                {
                                        ++j;
                                }
                        }
                        if(v >= a[j])
                        {
                                heap = 1;
                        }
                        else
                        {
                                a[k] = a[j];
                                k = j;
                        }
                }
                a[k] = v;
        }
}

void heapsort(int *a,int n)
{
        int k = n - 1;
        for(int i = 0; i < n - 2; ++i)
        {
                int temp = a[1];
                a[1] = a[k];
                a[k] = temp;
                --k;
                heapify(a,k + 1);
        }
}

int main()
{
        int a[] = {4, 1, 3, 5, 7, 8, 2, 6, 9};
        int n = 8;
        display(a,n);
        heapify(a,n);

        heapsort(a,n);
        display(a,n);


}
