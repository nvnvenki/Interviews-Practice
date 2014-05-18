#include <stdio.h>

int fibonaci(int n)
{
        if( n == 0 || n == 1)
        {
                return n;
        }
        else
        {
                return fibonaci(n - 1) + fibonaci(n - 2);
        }
}
int main()
{
        int i;
        for(i = 0; i < 10; ++i)
        {
                printf("%d\t",fibonaci(i));
        }
        printf("\n");

        int a = 0;
        int b = 1;
        i = 2;
        while(i < 10)
        {
                printf("%d\t",a);
                printf("%d\t",b);
                a = a + b;
                b = a + b;
                i = i + 2;
        }
        printf("\n");
        return 0;
}
