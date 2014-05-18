#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fact(int n)
{
        if(n == 0 || n == 1)
        {
                return 1;
        }
        else
        {
                return (n * fact(n - 1));
        }
}

double sin_(int x)
{
        
        int sign = 1;
        int term = 1;
        double value = x;
        while(term < 9)
        {
                term = term + 2;
                sign = sign * -1;
                value = value + (sign * pow(x,term) / fact(term));

        }
        return value;
        
}

int main()
{
        int x = 1;
        printf("sin(%d) = %.2f\n",x,sin_(x));
}
