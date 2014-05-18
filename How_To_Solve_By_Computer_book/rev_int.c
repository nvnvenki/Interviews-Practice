#include <stdio.h>

int rev(int n)
{
        int reversed = 0;
        while(n > 0)
        {

                reversed = reversed * 10 + (n % 10);
                n = n /10;
        }
        printf("\n");

        return reversed;
}


int main()
{
        int n = 3259;
        printf("Reversed: %d\n", rev(n));
        return 0;
}
