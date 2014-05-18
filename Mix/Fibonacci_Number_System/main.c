#include <stdio.h>
#include <stdlib.h>

void print_array(int *a,int n)
{
        for(int i = 1; i <= n; ++i)
        {
                printf("%d\t",a[i]);
        }
        printf("\n");
}

int fib(int n)
{
        if(n <= 1)
        {
                return n;
        }
        else
        {
                return fib(n - 1) + fib(n - 2);
        }
}

void solve(int *bits,int end,int number,int *series,int size)
{

#if 0
        if(end < 0 || number == 0)
        {
                if(number == 0)
                {
                        print_array(bits,size);
                }
        }
        else
        {
                if(series[end] <= number)
                {
                        bits[end] = 1;
                        solve(bits,end - 1,number - series[end],series,size);
                }
                else
                {
                        bits[end] = 0;
                        solve(bits,end - 1,number,series,size);
                }
        }
#endif
        for(int i = size + 1; i > 0; ++i)
        {
                printf("%d\n", series[i]);
        }
}

void solution(int number,int *series,int size)
{
        printf("\nSolution:\n");
        int bits[size + 1];
        for(int i = 0; i < size + 1; ++i)
        {
                bits[i] = 0;
        }
        solve(bits,size,number,series,size);
}

int main()
{
        int n = 10;
        int fibonacci[n];
        int i;// i - 2: no of fibonacci numbers generated
        int f;
        for(i = 2; (i < n) && ((f = fib(i)) <= n); ++i)
        {
                fibonacci[i - 1] = f;
        }
        int num = i - 2; // no of fibonacci numbers generated
        printf("Number generate aaythu\n");
        print_array(fibonacci,num);
        solution(n,fibonacci,num); 
        return 0;
}
