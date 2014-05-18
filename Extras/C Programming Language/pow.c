#include <stdio.h>

int pow(int a,int b)
{
#if 0
        if(b == 1)
        {
                return a;
        }
        else
        {
                return a * pow(a, b -1);
        }
#endif
        if(b == 0)
        {
                return 1;
        }
        else if(b % 2 == 0)
        {
                return pow(a, b / 2) * pow(a , b /2);
        }
        else
        {
                return a * pow(a, b / 2) * pow(a, b / 2);
        }
}


int main()
{
        printf("pow(2,3): %d\n",pow(2,3));
}
