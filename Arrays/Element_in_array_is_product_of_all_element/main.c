#include <stdio.h>

void buildB(int *a,int *b, int n)
{
#if 0
        // Worst efficiency

        for(int i = 0; i < n; ++i)
        {
                int product = 1;
                for(int j = 0; j < n; ++j)
                {
                        if( j != i)
                        {
                                product = product * a[j];
                        }
                }
                printf("product %d : %d\n",i,product);
                b[i] = product;
        }
#endif
        // can i make it better??

}


int main()
{
        int a[] = {1,2,3,4,5};
        int b[5];
        int n = 5;
        printf("Elements of array A are: \n");
        for(int i = 0;  i < n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
        buildB(a,b,n);

        printf("Elements of array B are: \n");
        
        for(int i = 0;  i < n; ++i)
        {
                printf("%d\t",b[i]);
        }
        printf("\n");
}
