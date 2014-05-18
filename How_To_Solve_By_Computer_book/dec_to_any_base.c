#include <stdio.h>

void dec_to_any(int n,int base)
{
        int i = 0,m,digits[1000],flag;
        printf("%d is converted to base %d\n",n,base);

        while(n)
        {
                m = n % base;
                digits[i] = "0123456789abcdefghijklmnopqrstuvwxyz"[m];
                n = n / base;
                ++i;
        }

        for(i--; i > 0; i--)
        {  
                if(!flag && digits[i] != '0')
                {
                        flag = 1;
                }
                if(flag)
                { 
                        printf("%c",digits[i]);
                }
        }
        printf("\n");
}

int main()
{
        dec_to_any(10,2); // 10 to binary
        dec_to_any(255,16); // 255 to hex
        return 0;
}

