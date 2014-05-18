#include <stdio.h>
#include <stdlib.h>

void tower(int n,char from,char to,char temp)
{
        if(n > 0)
        {
                tower(n - 1,from,temp,to);
                printf("\n Move disc %d from %c to %c\n",n,from,to);
                tower(n - 1,temp,to,from);
        }
}

int main()
{
        int n = 50;
        tower(n,'L','R','C');
        return 0;
}
