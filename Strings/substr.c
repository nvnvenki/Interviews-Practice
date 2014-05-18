#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substr(char *destn, char *src, int pos, int length)
{
        if(length < 0 && pos < 0 && (length > strlen(src) || pos > strlen(src)))
        {
                printf("Error");
                exit(0);
        }
        
        while(length > 0)
        {
                *destn = *(src + pos);
                ++destn;
                ++src;
                --length;
        }
}

int main()
{
        char destn[100];
        char *src = "hello";
        substr(destn,src,1,2);
        puts(destn);
        return 0;
}
