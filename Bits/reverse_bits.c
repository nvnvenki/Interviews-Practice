#include <stdio.h>

unsigned int rev(unsigned int n)
{
        unsigned int bits = sizeof(n) * 8;
        unsigned int reversed = 0;
        unsigned int temp;

        for(unsigned int i = 0; i < bits; ++i)
        {
                temp = (n & 1 << i);
                if(temp)
                {
                        reversed |= (1 << ((bits - 1) - i));
                }
        }
        return reversed;
}

int main()
{
        unsigned int n = 0xf0;
        printf("Reveresed bits of %d is : %d\n",n,rev(n));
        return 0;
}
