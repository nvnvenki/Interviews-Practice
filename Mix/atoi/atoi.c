#include <stdio.h>

int atoi(char *num)
{
        int i = 0;
        while(*num)
        {
                i = (i  <<  3) + ( i  << 1) + (*num - '0');
                printf("%d \n", i);
                ++num;
        }
        return i;
}

int main()
{
        printf("%d\n",atoi("100"));
        return 0;
}
